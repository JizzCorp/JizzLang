#include <string.h>
#include "tokens.h"

TokenName recognize_token(char* target) {
	if(!strcmp(target, "if")       ||
	   !strcmp(target, "else")     ||
	   !strcmp(target, "case")     ||
	   !strcmp(target, "elsecase") ||
	   !strcmp(target, "loop")     ||
	   !strcmp(target, "exit")     ||
	   !strcmp(target, "return")
	) return CFLOW;

	if (!strcmp(target, "in") ||
		!strcmp(target, "out")
	) return IO;

	if(!strcmp(target, "Bool") ||
	   !strcmp(target, "Int")  ||
	   !strcmp(target, "Flt")  ||
	   !strcmp(target, "Str")  ||
	   !strcmp(target, "Function")
	) return DTYPE;

	if(!strcmp(target, "(") ||
	   !strcmp(target, ")") ||
	   !strcmp(target, "[") ||
	   !strcmp(target, "]") ||
	   !strcmp(target, "{") ||
	   !strcmp(target, "}")
	) return PAR;

	if(!strcmp(target, ";") ||
	   !strcmp(target, ",")
	) return CMD;

	if(!strcmp(target, "<-")) return ASSN;

	if(!strcmp(target, "<")  ||
	   !strcmp(target, ">")  ||
	   !strcmp(target, "=")  ||
	   !strcmp(target, "<=") ||
	   !strcmp(target, ">=") ||
	   !strcmp(target, "!=")
	) return CMP;

	if(!strcmp(target, "+") ||
	   !strcmp(target, "-") ||
	   !strcmp(target, "*") ||
	   !strcmp(target, "/") ||
	   !strcmp(target, "%") ||
	   !strcmp(target, "@") ||
	   !strcmp(target, "^") ||
	   !strcmp(target, "and") ||
	   !strcmp(target, "or") ||
	   !strcmp(target, "not")
	) return OP;

	if(!strcmp(target, "&") ||
	   !strcmp(target, "|") ||
	   !strcmp(target, "!")
	) return BOP;

	return UNRECOGNIZED;
}
