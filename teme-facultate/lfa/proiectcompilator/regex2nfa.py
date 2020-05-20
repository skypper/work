'''
3. Sa se scrie un program care primeste la intrare elementele unei expresii regulate (alfabetul expresiei,
 expresia propriu -zisa (in forma prefixata sau infixata - adica forma naturala), care contine 3 tipuri de
  operatori: reuniune, concatenare si iteratie Kleene (*)). Sa se determine un automat finit nedeterminist
   cu lambda-tranzitii (sa se afiseze elememtele sale) care recunoaste acelasi limbaj ca cel descris de
   expresia regulata. Programul afiseaza si graful care corespunde noului automat (grafic 1 punct).
'''

import parse_tree
import state_machine


nfa1 = state_machine.RegexNFA('a')
nfa1.to_string()

nfa2 = state_machine.RegexNFA('b')
nfa2.to_string()

nfa3 = state_machine.RegexNFA.union(nfa1, nfa2)
nfa3.to_string()

nfa4 = state_machine.RegexNFA.closure(nfa1)
nfa4.to_string()

nfa5 = state_machine.RegexNFA.concat(nfa1, nfa2)
nfa5.to_string()

nfa6 = state_machine.RegexNFA.closure(state_machine.RegexNFA.union(nfa1, nfa2))
nfa6.to_string()


# regex := ((a|b)*abb)#
regex = '(((((a|b)*).a).b).b)'
nfa = state_machine.RegexNFA.from_regex(regex)
nfa.to_string()
print(nfa.accept('aabb'))