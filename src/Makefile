parsertest: parser.o lexer.o word_automaton.o nat_automaton.o preal_automaton.o nint_automaton.o nreal_automaton.o tokens.o
	@gcc -o parsertest parser.o lexer.o word_automaton.o nat_automaton.o preal_automaton.o nint_automaton.o nreal_automaton.o tokens.o

parser.o: parser/parser.c
	@gcc parser/parser.c -o parser.o -c

lexer.o: lexer/lexer.c
	@gcc lexer/lexer.c -o lexer.o -c

word_automaton.o: lexer/word_automaton.c
	@gcc lexer/word_automaton.c -o word_automaton.o -c

nat_automaton.o: lexer/nat_automaton.c
	@gcc lexer/nat_automaton.c -o nat_automaton.o -c

preal_automaton.o: lexer/preal_automaton.c
	@gcc lexer/preal_automaton.c -o preal_automaton.o -c

nint_automaton.o: lexer/nint_automaton.c
	@gcc lexer/nint_automaton.c -o nint_automaton.o -c

nreal_automaton.o: lexer/nreal_automaton.c
	@gcc lexer/nreal_automaton.c -o nreal_automaton.o -c

tokens.o: lexer/tokens.c
	@gcc lexer/tokens.c -o tokens.o -c

clean:
	@rm parser.o lexer.o word_automaton.o nat_automaton.o preal_automaton.o nint_automaton.o nreal_automaton.o tokens.o
