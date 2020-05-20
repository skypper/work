'''
2. Sa se scrie un program care primeste la intrare elementele unei expresii regulate (alfabetul expresiei,
expresia propriu -zisa (in forma prefixata sau infixata - adica forma naturala), care contine 3 tipuri de operatori:
reuniune, concatenare si iteratie Kleene (*)). Sa se determine un automat finit determinist (sa se afiseze elememtele
sale) care recunoaste acelasi limbaj ca cel descris de expresia regulata, folosind algoritmul de la curs. Programul
afiseaza si graful care corespunde noului automat (grafic 1 punct).
'''

import parse_tree
import state_machine

leaf_counter = 0
leaves_index = {}
symbol_index = {}
followpos = {}

def index_leaf_nodes(node):
    if node is None:
        return

    index_leaf_nodes(node.left)
    index_leaf_nodes(node.right)

    if node.is_leaf():
        global leaf_counter
        leaf_counter += 1
        node.index = leaf_counter
        leaves_index[node.index] = node

        global symbol_index
        symbol_index[node.index] = node.expression

        node.nullable = False
        node.firstpos = set([node.index])
        node.lastpos = set([node.index])
    else:
        if node.operation.operator == '*':
            node.nullable = True
            node.firstpos = node.left.firstpos.copy()
            node.lastpos = node.left.lastpos.copy()
        elif node.operation.operator == '|':
            node.nullable = node.left.nullable or node.right.nullable
            node.firstpos = node.left.firstpos.union(node.right.firstpos)
            node.lastpos = node.left.lastpos.union(node.right.lastpos)
            pass
        elif node.operation.operator == '.':
            node.nullable = node.left.nullable and node.right.nullable

            if node.left.nullable is True:
                node.firstpos = node.left.firstpos.union(node.right.firstpos)
            else:
                node.firstpos = node.left.firstpos.copy()

            if node.right.nullable is True:
                node.lastpos = node.left.lastpos.union(node.right.lastpos)
            else:
                node.lastpos = node.right.lastpos.copy()

        if node.operation.type == 'unary':
            for i in node.left.firstpos:
                for j in node.left.lastpos:
                    if i not in followpos:
                        followpos[i] = set([j])
                    else:
                        followpos[i].add(j)
        elif node.operation.type == 'binary':
            for i in node.left.lastpos:
                for j in node.right.firstpos:
                    if i not in followpos:
                        followpos[i] = set([j])
                    else:
                        followpos[i].add(j)


# regex ((a|b)*abb)#
regex = '((((((a|b)*).a).b).b).#)'
root = parse_tree.parse_expression(regex)
index_leaf_nodes(root)
print('----')
dfa = state_machine.RegexDFA(root.firstpos, followpos, symbol_index, leaf_counter)

print(dfa.accept('ab'))
print(dfa.accept('abb'))
print(dfa.accept('aabb'))
print(dfa.accept('babb'))
print(dfa.accept('babbb'))
