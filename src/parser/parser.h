#ifndef PARSER
#define PARSER

#define MIN_STATEMENTS 1

NodeProgram* parse_program(Token* tokenlist, size_t tokenlist_cursor);
NodeStatement* parse_statement(Token* tokenlist, size_t* tokenlist_cursor);
NodeOutput* parse_output(Token* tokenlist, size_t* tokenlist_cursor);
NodeIf* parse_if(Token* tokenlist, size_t* tokenlist_cursor);
NodeCase* parse_case(Token* tokenlist, size_t* tokenlist_cursor);
NodeLoop* parse_loop(Token* tokenlist, size_t* tokenlist_cursor);
NodeReturn* parse_return(Token* tokenlist, size_t* tokenlist_cursor);
NodeExit* parse_exit(Token* tokenlist, size_t* tokenlist_cursor);
NodeFunctionDecl* parse_function_decl(Token* tokenlist, size_t* tokenlist_cursor);
NodeInput* parse_input(Token* tokenlist, size_t* tokenlist_cursor);
NodeDeclaration* parse_declaration(Token* tokenlist, size_t* tokenlist_cursor);
NodeAssignment* parse_assignment(Token* tokenlist, size_t* tokenlist_cursor);
NodeFunctionCall* parse_function_call(Token* tokenlist, size_t* tokenlist_cursor);
NodeExpression* parse_expression(Token* tokenlist, size_t* tokenlist_cursor);
NodeLogOr* parse_logical_or(Token* tokenlist, size_t* tokenlist_cursor);
NodeLogAnd* parse_logical_and(Token* tokenlist, size_t* tokenlist_cursor);
NodeBitOr* parse_bitwise_or(Token* tokenlist, size_t* tokenlist_cursor);
NodeBitAnd* parse_bitwise_and(Token* tokenlist, size_t* tokenlist_cursor);
NodeEquality* parse_equality(Token* tokenlist, size_t* tokenlist_cursor);
NodeIneq* parse_inequality(Token* tokenlist, size_t* tokenlist_cursor);
NodeAdd* parse_addition(Token* tokenlist, size_t* tokenlist_cursor);
NodeMult* parse_multiplication(Token* tokenlist, size_t* tokenlist_cursor);
NodePower* parse_power(Token* tokenlist, size_t* tokenlist_cursor);
NodeNot* parse_negation(Token* tokenlist, size_t* tokenlist_cursor);
NodePrimary* parse_primary(Token* tokenlist, size_t* tokenlist_cursor);

#endif
