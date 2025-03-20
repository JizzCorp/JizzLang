#include <string.h>

#include "../globals.h"

#include "automatonlib.h"

State word_automaton(char target, Bool reset) {
	static State state = A;
	
	if(reset) {
		state = A;
		return state;
	}
	
	switch(state) {
		case A:
			if(ALPHA(target) || target == '_') state = B;
			else if(NUMBER(target)) state = C;
			else state = ERR;
		break;
		case B:
			if(ALPHA(target) || target == '_'); // state remains B
			else if(NUMBER(target)) state = D;
			else state = ERR;
		break;
		case C:
			if(ALPHA(target) || target == '_') state = B;
			else if(NUMBER(target)); // state remains C
			else state = ERR;
		break;
		case D:
			if(ALPHA(target) || target == '_') state = B;
			else if(NUMBER(target)); // state remains D
			else state = ERR;
		break;
		default:
			return False;
		break;
	}
	
	return (state == B || state == D) ? FINAL : state;
}
