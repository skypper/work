from unittest import TestCase


class TestRegexDFA(TestCase):
    @classmethod
    def setUpClass(cls):
        regex = '((((((((a.a).a)|(b.b))*).a).b).b).((a|b)*))'
        from regex2dfa import dfa
        cls.dfa = dfa

    def test_accept_simple(self):
        word = 'abb'
        self.assertTrue(TestRegexDFA.dfa.accept(word))

    def test_not_accept_null(self):
        word = ''
        self.assertFalse(TestRegexDFA.dfa.accept(word))

    def test_accept_complex(self):
        word = 'bbbbabbabab'
        self.assertTrue(TestRegexDFA.dfa.accept(word))

    def test_not_accept_complex(self):
        word = 'aabbabbabab'
        self.assertFalse(TestRegexDFA.dfa.accept(word))

    def test_not_accept_random(self):
        word = 'asdasdabb'
        self.assertFalse(TestRegexDFA.dfa.accept(word))