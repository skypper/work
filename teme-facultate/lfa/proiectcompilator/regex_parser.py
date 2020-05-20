'''
Represents an expression operation, containing the type of the operation (either unary or binary),
the operation and the operand(s).
'''
class Operation:
    def __init__(self):
        self.index = -1

    # constructor for unary operation
    def unary(self, operator, operand):
        self.operator = operator
        self.operand = operand
        self.type = 'unary'

    # constructor for binary operation
    def binary(self, operator, lhs_operand, rhs_operand):
        self.operator = operator
        self.lhs_operand = lhs_operand
        self.rhs_operand = rhs_operand
        self.type = 'binary'

    def to_string(self):
        if self.type == 'unary':
            return self.operand + ' ' + self.operator
        elif self.type == 'binary':
            return self.lhs_operand + ' ' + self.operator + ' ' + self.rhs_operand


'''
Represents a node in the abstract parse tree.
'''
class TreeNode:
    def __init__(self, operation, expression):
        self.expression = ''

        self.left = None
        self.right = None

        self.operation = operation
        self.expression = expression

        self.nullable = False
        self.firstpos = {}
        self.lastpos = {}

    def is_leaf(self):
        return self.operation is None


def is_operator(token):
    return token in '*|.'


def is_symbol(token):
    return token in 'abc'


'''
Returns the operation object for the corresponding expression.
'''
def parse_operation(expression):
    if expression[0] == '(' and expression[len(expression) - 1] == ')':
        expression = expression[1:len(expression)-1]

    paranthesis_depth = 0
    for i in range(len(expression)):
        token = expression[i]
        if token == '(':
            paranthesis_depth += 1
        elif token == ')':
            paranthesis_depth -= 1
        elif is_operator(token) and paranthesis_depth == 0:
            operator = token

            if operator == '*':
                # unary operator
                operand = expression[0:i]
                operation = Operation()
                operation.unary(operator, operand)
                return operation
            else:
                # binary operator
                lhs_operand = expression[0:i]
                rhs_operand = expression[i + 1:len(expression)]

                operation = Operation()
                operation.binary(operator, lhs_operand, rhs_operand)
                return operation
    return None
