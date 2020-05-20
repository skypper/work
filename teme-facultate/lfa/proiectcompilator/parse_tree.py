import regex_parser


def parse_expression(expression):
    # parse the operation expression
    operation = regex_parser.parse_operation(expression)

    # update the Parse Tree with the new operation
    parse_tree_root = regex_parser.TreeNode(operation, expression)

    node_stack = [parse_tree_root]
    current_index = 1

    while len(node_stack) > 0:
        node = node_stack.pop()

        if not node.is_leaf():
            #print(node.operation.to_string())

            if node.operation.type == 'unary':
                child_operation = regex_parser.parse_operation(node.operation.operand)
                child = regex_parser.TreeNode(child_operation, node.operation.operand)
                node.left = child
                node_stack.append(child)
            elif node.operation.type == 'binary':
                left_child_operation = regex_parser.parse_operation(node.operation.lhs_operand)
                left_child = regex_parser.TreeNode(left_child_operation, node.operation.lhs_operand)
                node.left = left_child
                node_stack.append(left_child)

                right_child_operation = regex_parser.parse_operation(node.operation.rhs_operand)
                right_child = regex_parser.TreeNode(right_child_operation, node.operation.rhs_operand)
                node.right = right_child
                node_stack.append(right_child)
        else:
            #print(node.expression)

            node.index = current_index
            current_index += 1

    return parse_tree_root
