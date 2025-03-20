#include <string.h>

#include "../globals.h"

#include "automatonlib.h"

State preal_automaton(char target, Bool reset) {
	static State state = A;

	if(reset) {
		state = A;
		return state;
	}

	switch(state) {
		case A:
			if(target == '0') state = B;
			else if(NONZERO_NUMBER(target)) state = C;
			else state = ERR;
		break;
		case B:
			if(target == '.') state = D;
			else state = ERR;
		break;
		case C:
			if(target == '.') state = D;
			else if(NUMBER(target)); // state remains C
			else state = ERR;
		break;
		case D:
			if(target == '0'); // state remains D
			else if(NONZERO_NUMBER(target)) state = E;
			else state = ERR;
		break;
		case E:
			if(target == '0') state = D;
			else if(NONZERO_NUMBER(target)); // state remains E
			else state = ERR;
		break;
		default:
			return False;
		break;
	}

	return (state == E) ? FINAL : state;
}
