#include <string.h>

#include "../globals.h"

#include "automatonlib.h"

State nreal_automaton(char target, Bool reset) {
	static State state = A;

	if(reset) {
		state = A;
		return state;
	}

	switch(state) {
		case A:
			if(target == '-') state = B;
			else state = ERR;
		break;
		case B:
			if(target == '0') state = C;
			else if(NONZERO_NUMBER(target)) state = D;
			else state = ERR;
		break;
		case C:
			if(target == '.') state = E;
			else state = ERR;
		break;
		case D:
			if(target == '.') state = E;
			else if(NUMBER(target)); // state remains D
			else state = ERR;
		break;
		case E:
			if(target == '0'); // state remains E
			else if(NONZERO_NUMBER(target)) state = F;
			else state = ERR;
		break;
		case F:
			if(target == '0') state = E;
			else if(NONZERO_NUMBER(target)); // state remains F
			else state = ERR;
		break;
		default:
			return False;
		break;
	}

	return (state == F) ? FINAL : state;
}
