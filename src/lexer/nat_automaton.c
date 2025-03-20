#include <string.h>

#include "../globals.h"

#include "automatonlib.h"

State nat_automaton(char target, Bool reset) {
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
			state = ERR;
		break;
		case C:
			if(NUMBER(target)); // state remains C
			else state = ERR;
		break;
		default:
			return False;
		break;
	}

	return (state == B || state == C) ? FINAL : state;
}
