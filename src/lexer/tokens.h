#ifndef TOKENS
#define TOKENS

#define TOKENSCOUNT 5
#define INIT_TOKENLIST_SIZE 8

typedef enum {
	WORD,
	NAT,
	NINT,
	NREAL,
	PREAL,
	STR,
	CFLOW,
	IO,
	DTYPE,
	PAR,
	CMD,
	ASSN,
	CMP,
	OP,
	BOP,
	EOTL,
	UNRECOGNIZED
} TokenName;

typedef struct {
	TokenName name;
	char value[100];
} Token;

TokenName recognize_token(char* target);

#endif
