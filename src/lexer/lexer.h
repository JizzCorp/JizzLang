#ifndef LEXER
#define LEXER

#define FILENAME argv[1]
#define FILENAME_EXT {FILENAME[filename_len-5], FILENAME[filename_len-4], FILENAME[filename_len-3], FILENAME[filename_len-2], FILENAME[filename_len-1], '\0'}
#define MIN_FILENAME_LEN 6

#define EMPTY_CHAR(x) ((x) == ' ' || (x) == '\n' || (x) == '\t')
#define CONCATENABLE_CHAR(x) ((x) == '(' || (x) == ')' || (x) == '[' || (x) == ']' || (x) == '{' || (x) == '}' || (x) == ',' || (x) == ';' || (x) == '`')

#define INIT_BUFFER_SIZE 128

#define FREEHEAP free(tokenlist); free(buffer)

typedef State (*Automaton)(char, Bool);

Token* lexer(char* filename);

#endif
