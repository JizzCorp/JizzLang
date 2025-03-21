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
		printf("[COMPILER] [EXTERNAL ERROR] Not a .cfn file\n\n\n");
		exit(1);
	}
	char extension[] = FILENAME_EXT;
	if(strcmp(extension, ".cfn")) {
		printf("[COMPILER] [EXTERNAL ERROR] Not a .cfn file\n\n\n");
		exit(1);
	}

	Token* tokenlist = lexer(FILENAME);
	
	return 0;
}