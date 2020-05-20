from unittest import TestCase
import state_machine


class TestRegexNFA(TestCase):
    @classmethod
    def setUpClass(cls):
        #regex = '(((((a|b)*).a).b).b)'
        regex = '((((((((a.a).a)|(b.b))*).a).b).b).((a|b)*))'
        cls.nfa = state_machine.RegexNFA.from_regex(regex)

    def test_accept_simple(self):
        word = 'abb'
        self.assertTrue(TestRegexNFA.nfa.accept(word))

    def test_not_accept_null(self):
        word = ''
        self.assertFalse(TestRegexNFA.nfa.accept(word))

    def test_accept_complex(self):
        word = 'bbbbabbabab'
        self.assertTrue(TestRegexNFA.nfa.accept(word))

    def test_not_accept_complex(self):
        word = 'aabbabbabab'
        self.assertFalse(TestRegexNFA.nfa.accept(word))

    def test_not_accept_random(self):
        word = 'asdasdabb'
        self.assertFalse(TestRegexNFA.nfa.accept(word))