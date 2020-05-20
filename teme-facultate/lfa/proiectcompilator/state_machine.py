from string import ascii_lowercase
import parse_tree


class StateMachine:
    def __init__(self):
        self.states = set()
        self.initial_state = None
        self.transitions = dict()
        self.final_states = set()

    def to_string(self):
        print('states = {}'.format(self.states))
        print('initial_state = {}'.format(self.initial_state))
        print('transitions = {}'.format(self.transitions))
        print('final_states = {}'.format(self.final_states))
        print()


class RegexNFA(StateMachine):
    def __init__(self, symbol):
        StateMachine.__init__(self)

        self.state_index = -1

        if symbol is None:
            return

        first_state = self.add_state()
        self.set_initial_state(first_state)
        second_state = self.add_state()
        self.set_final_state(second_state)

        self.add_transition(0, symbol, 1)

    @staticmethod
    def construct_rec(node):
        if node.is_leaf():
            return RegexNFA(node.expression)
        else:
            if node.operation.operator == '*':
                return RegexNFA.closure(RegexNFA.construct_rec(node.left))
            elif node.operation.operator == '|':
                return RegexNFA.union(RegexNFA.construct_rec(node.left), RegexNFA.construct_rec(node.right))
            elif node.operation.operator == '.':
                return RegexNFA.concat(RegexNFA.construct_rec(node.left), RegexNFA.construct_rec(node.right))

    @staticmethod
    def from_regex(regex):
        root = parse_tree.parse_expression(regex)
        nfa = RegexNFA.construct_rec(root)
        return nfa

    @staticmethod
    def union(nfa1, nfa2):
        if not isinstance(nfa1, RegexNFA) or not isinstance(nfa2, RegexNFA):
            return None

        result = RegexNFA(None)
        first_state = result.add_state()
        result.set_initial_state(first_state)

        state_map1 = result.merge_with(nfa1)
        state_map2 = result.merge_with(nfa2)

        result.add_transition(result.get_initial_state(), '\0', state_map1[nfa1.get_initial_state()])
        result.add_transition(result.get_initial_state(), '\0', state_map2[nfa2.get_initial_state()])

        last_state = result.add_state()
        result.set_final_state(last_state)

        for final_state1 in nfa1.get_final_states():
            result.add_transition(state_map1[final_state1], '\0', last_state)
        for final_state2 in nfa2.get_final_states():
            result.add_transition(state_map2[final_state2], '\0', last_state)

        return result

    @staticmethod
    def concat(nfa1, nfa2):
        if not isinstance(nfa1, RegexNFA) or not isinstance(nfa2, RegexNFA):
            return None

        result = RegexNFA(None)

        state_map1 = result.merge_with(nfa1)
        state_map2 = result.merge_with(nfa2)

        result.set_initial_state(state_map1[nfa1.get_initial_state()])
        for final_state2 in nfa2.get_final_states():
            result.set_final_state(state_map2[final_state2])

        for final_state1 in nfa1.get_final_states():
            result.add_transition(state_map1[final_state1], '\0', state_map2[nfa2.get_initial_state()])

        return result

    @staticmethod
    def closure(nfa):
        if not isinstance(nfa, RegexNFA):
            return None

        result = RegexNFA(None)
        first_state = result.add_state()
        result.set_initial_state(first_state)

        state_map = result.merge_with(nfa)

        last_state = result.add_state()
        result.set_final_state(last_state)

        result.add_transition(first_state, '\0', last_state)
        result.add_transition(first_state, '\0', state_map[nfa.get_initial_state()])
        for final_state in nfa.get_final_states():
            result.add_transition(state_map[final_state], '\0', state_map[nfa.get_initial_state()])
            result.add_transition(state_map[final_state], '\0', last_state)

        return result

    def add_state(self):
        self.state_index += 1
        self.states.add(self.state_index)

        return self.state_index

    def set_initial_state(self, initial_state):
        self.initial_state = initial_state

    def get_initial_state(self):
        return self.initial_state

    def is_final_state(self, state):
        return state in self.final_states

    def add_transition(self, from_state, with_symbol, to_state):
        if not (from_state, with_symbol) in self.transitions:
            self.transitions[(from_state, with_symbol)] = [to_state]
        else:
            self.transitions[(from_state, with_symbol)].append(to_state)

    def set_final_state(self, final_state):
        self.final_states.add(final_state)

    def get_final_states(self):
        return self.final_states

    def get_next_states(self, current_state, with_symbol):
        if not (current_state, with_symbol) in self.transitions:
            return None

        return self.transitions[(current_state, with_symbol)]

    def get_next_states_empty(self, current_state):
        return self.get_next_states(current_state, '\0')

    def merge_with(self, that):
        state_map_that_to_self = dict()
        for state in that.states:
            new_state = self.add_state()
            state_map_that_to_self[state] = new_state

        for transition_key in that.transitions:
            that_from_state = transition_key[0]
            with_symbol = transition_key[1]
            for that_to_state in that.transitions[transition_key]:
                self.add_transition(state_map_that_to_self[that_from_state],
                                    with_symbol,
                                    state_map_that_to_self[that_to_state])
        return state_map_that_to_self

    def accept(self, word):
        return self.accept_rec(self.initial_state, word)

    def accept_rec(self, current_state, word, pos = 0):
        if pos < len(word):
            if self.get_next_states(current_state, word[pos]) is not None:
                for next_state in self.get_next_states(current_state, word[pos]):
                    if self.accept_rec(next_state, word, pos + 1) is True:
                        return True

        if self.get_next_states_empty(current_state) is not None:
            for next_state in self.get_next_states_empty(current_state):
                if self.accept_rec(next_state, word, pos) is True:
                    return True

        if pos == len(word) and self.is_final_state(current_state):
            return True

        return False


class RegexDFA(StateMachine):
    def __init__(self, initial_state, followpos, symbol_index, final_pos):
        StateMachine.__init__(self)

        self.set_initial_state(initial_state)

        unmarked_states = [initial_state]
        while len(unmarked_states) > 0:
            state = unmarked_states.pop()

            for symbol in ascii_lowercase:
                next_state = set()

                for pos in state:
                    if symbol == symbol_index[pos]:
                        next_state.update(followpos[pos])

                if len(next_state) > 0:
                    if not self.has_state(next_state):
                        self.add_state(next_state)
                        if final_pos in next_state:
                            self.set_final_state(next_state)
                        unmarked_states.append(next_state)

                    self.add_transition(state, symbol, next_state)

    def add_state(self, state):
        self.states.add(frozenset(state))

    def has_state(self, state):
        return state in self.states

    def set_initial_state(self, initial_state):
        self.initial_state = initial_state
        self.add_state(initial_state)

    def get_initial_state(self):
        return self.initial_state

    def is_final_state(self, state):
        return state in self.final_states

    def add_transition(self, from_state, with_symbol, to_state):
        self.transitions[(frozenset(from_state), with_symbol)] = frozenset(to_state)

    def set_final_state(self, final_state):
        self.final_states.add(frozenset(final_state))

    def get_next_state(self, current_state, with_symbol):
        if (frozenset(current_state), with_symbol) not in self.transitions:
            return None

        return self.transitions[(frozenset(current_state), with_symbol)]

    def accept(self, word):
        current_state = self.initial_state

        for symbol in word:
            current_state = self.get_next_state(current_state, symbol)

            if current_state is None:
                return False

        if self.is_final_state(current_state):
            return True
        else:
            return False
