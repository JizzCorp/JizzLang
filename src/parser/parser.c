#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../globals.h"

#include "../lexer/automatonlib.h"
#include "../lexer/tokens.h"
#include "../lexer/lexer.h"

#include "ast.h"
#include "parser.h"

int main(int argc, char** argv) {
	// check if FILENAME was provided
	if(argc < 2) {
		printf("[COMPILER] [EXTERNAL ERROR] No file name provided\n\n\n");
		exit(1);
	}
	// check if extension is correct
	int filename_len = strlen(FILENAME);
	if(filename_len < MIN_FILENAME_LEN) {
		printf("[COMPILER] [EXTERNAL ERROR] Not a .jizz file\n\n\n");
		exit(1);
	}
	char extension[] = FILENAME_EXT;
	if(strcmp(extension, ".jizz")) {
		printf("[COMPILER] [EXTERNAL ERROR] Not a .jizz file\n\n\n");
		exit(1);
	}

	Token* tokenlist = lexer(FILENAME);
	AbstractSyntaxTree ast = parse_program(tokenlist, 0);
	
	return 0;
}

NodeProgram* parse_program(Token* tokenlist, size_t tokenlist_cursor) {
	NodeProgram* program_subtree = (NodeProgram*)malloc(sizeof(NodeProgram));
	program_subtree->node_type = NODEPROGRAM;
	
	size_t statements_cursor = 0, statements_count = MIN_STATEMENTS;
	program_subtree->statements = (NodeStatement**)malloc(sizeof(NodeStatement**) * statements_count);
	
	for(int i = tokenlist_cursor; tokenlist[i] != EOTL; ++i) {
		(program_subtree->statements)[statements_cursor] = (NodeStatement*)malloc(sizeof(NodeStatement*));
		(program_subtree->statemenst)[statements_cursor] = parse_statement(tokenlist, &tokenlist_cursor);

		++statements_cursor;
		if(statements_cursor >= statements_count) {
			statements_count *= 2;
			NodeStatement** resized_statements_list = (NodeStatement**)realloc(sizeof(NodeStatements**) * statements_count);
			if(!resized_statements_list) {
				free(program_subtree);
				printf("[PARSER] [INTERNAL ERROR] Statements list reallocation failed\n\n\n");
				exit(2);
			}
		}
	}
	return program_subtree;
}

NodeStatement* parse_statement(Token* tokenlist, size_t* tokenlist_cursor) {
	NodeStatement* statement_subtree = (NodeStatement*)malloc(sizeof(NodeStatement));
	statement_subtree->node_type = NODESTATEMENT;

	Token token_name = tokenlist[tokenlist_cursor].name; char* token_value = tokenlist[tokenlist_cursor].value;
	if(token_name == IO && !strcmp(token_value, "out")) {
		statement_subtree->child_type = NODEOUTPUT;
		statement_subtree->statement = parse_output(tokenlist, &tokenlist_cursor);
	}
	else if(token_name == CFLOW && !strcmp(token_value, "if")) {
		statement_subtree->child_type = NODEIF;
		statement_subtree->statement = parse_if(tokenlist, &tokenlist_cursor);
	}
	else if(token_name == CFLOW && !strcmp(token_value, "case")) {
		statement_subtree->child_type = NODECASE;
		statement_subtree->statement = parse_case(tokenlist, &tokenlist_cursor);
	}
	else if(token_name == CFLOW && !strcmp(token_value, "loop")) {
		statement_subtree->child_type = NODELOOP;
		statement_subtree->statement = parse_loop(tokenlist, &tokenlist_cursor);
	}
	else if(token_name == CFLOW && !strcmp(token_value, "return")) {
		statement_subtree->child_type = NODERETURN;
		statement_subtree->statement = parse_return(tokenlist, &tokenlist_cursor);
	}
	else if(token_name == CFLOW && !strcmp(token_value, "exit")) {
		statement_subtree->child_type = NODEEXIT;
		statement_subtree->statement = parse_exit(tokenlist, &tokenlist_cursor);
	}
	else if(token_name == DTYPE && !strcmp(token_value, "Function")) {
		statement_subtree->child_type = NODEFUNCTIONDECL;
		statement_subtree->statement = parse_function_decl(tokenlist, &tokenlist_cursor);
	}
	else if(token_name == CFLOW && !strcmp(token_value, "if")) {
		statement_subtree->child_type = NODEIF;
		statement_subtree->statement = parse_if(tokenlist, &tokenlist_cursor);
	}
	else if(token_name == CFLOW && !strcmp(token_value, "if")) {
		statement_subtree->child_type = NODEIF;
		statement_subtree->statement = parse_if(tokenlist, &tokenlist_cursor);
	}
	else if(token_name == CFLOW && !strcmp(token_value, "if")) {
		statement_subtree->child_type = NODEIF;
		statement_subtree->statement = parse_if(tokenlist, &tokenlist_cursor);
	}
	else if(token_name == CFLOW && !strcmp(token_value, "if")) {
		statement_subtree->child_type = NODEIF;
		statement_subtree->statement = parse_if(tokenlist, &tokenlist_cursor);
	}
	else if(token_name == CFLOW && !strcmp(token_value, "if")) {
		statement_subtree->child_type = NODEIF;
		statement_subtree->statement = parse_if(tokenlist, &tokenlist_cursor);
	}
	return statement_subtree;
}

NodeOutput* parse_output(Token* tokenlist, size_t* tokenlist_cursor) {
	return NULL;
}

NodeIf* parse_if(Token* tokenlist, size_t* tokenlist_cursor) {
	return NULL;
}

NodeCase* parse_case(Token* tokenlist) {
	return NULL;
}

NodeLoop* parse_loop(Token* tokenlist) {
	return NULL;
}

NodeReturn* parse_return(Token* tokenlist) {
	return NULL;
}

NodeExit* parse_exit(Token* tokenlist) {
	return NULL;
}

NodeFunctionDecl* parse_function_decl(Token* tokenlist) {
	return NULL;
}

NodeInput* parse_input(Token* tokenlist) {
	return NULL;
}

NodeDeclaration* parse_declaration(Token* tokenlist) {
	return NULL;
}

NodeAssignment* parse_assignment(Token* tokenlist) {
	return NULL;
}

NodeFunctionCall* parse_function_call(Token* tokenlist) {
	return NULL;
}

NodeExpression* parse_expression(Token* tokenlist) {
	return NULL;
}

NodeLogOr* parse_logical_or(Token* tokenlist) {
	return NULL;
}

NodeLogAnd* parse_logical_and(Token* tokenlist) {
	return NULL;
}

NodeBitOr* parse_bitwise_or(Token* tokenlist) {
	return NULL;
}

NodeBitAnd* parse_bitwise_and(Token* tokenlist) {
	return NULL;
}

NodeEquality* parse_equality(Token* tokenlist) {
	return NULL;
}

NodeIneq* parse_inequality(Token* tokenlist) {
	return NULL;
}

NodeAdd* parse_addition(Token* tokenlist) {
	return NULL;
}

NodeMult* parse_multiplication(Token* tokenlist) {
	return NULL;
}

NodePower* parse_power(Token* tokenlist) {
	return NULL;
}

NodeNot* parse_negation(Token* tokenlist) {
	return NULL;
}

NodePrimary* parse_primary(Token* tokenlist) {
	return NULL;
}
