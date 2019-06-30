#include "StringUtils.h"

std::string StringUtils::tolower(std::string str) {
	std::string RESULT = std::move(str);

	for (int i = 0; i < RESULT.length(); i++) {
		if (RESULT[i] == 'A') {
			if (RESULT[i] == 'A') {
				RESULT[i] = 'a';
			}
			if (RESULT[i] == 'B') {
				RESULT[i] = 'b';
			}
			if (RESULT[i] == 'C') {
				RESULT[i] = 'c';
			}
			if (RESULT[i] == 'D') {
				RESULT[i] = 'd';
			}
			if (RESULT[i] == 'E') {
				RESULT[i] = 'e';
			}
			if (RESULT[i] == 'F') {
				RESULT[i] = 'f';
			}
			if (RESULT[i] == 'G') {
				RESULT[i] = 'g';
			}
			if (RESULT[i] == 'H') {
				RESULT[i] = 'h';
			}
			if (RESULT[i] == 'I') {
				RESULT[i] = 'i';
			}
			if (RESULT[i] == 'J') {
				RESULT[i] = 'j';
			}
			if (RESULT[i] == 'K') {
				RESULT[i] = 'k';
			}
			if (RESULT[i] == 'L') {
				RESULT[i] = 'l';
			}
			if (RESULT[i] == 'M') {
				RESULT[i] = 'm';
			}
			if (RESULT[i] == 'N') {
				RESULT[i] = 'n';
			}
			if (RESULT[i] == 'O') {
				RESULT[i] = 'o';
			}
			if (RESULT[i] == 'P') {
				RESULT[i] = 'p';
			}
			if (RESULT[i] == 'Q') {
				RESULT[i] = 'q';
			}
			if (RESULT[i] == 'R') {
				RESULT[i] = 'r';
			}
			if (RESULT[i] == 'S') {
				RESULT[i] = 's';
			}
			if (RESULT[i] == 'T') {
				RESULT[i] = 't';
			}
			if (RESULT[i] == 'U') {
				RESULT[i] = 'u';
			}
			if (RESULT[i] == 'V') {
				RESULT[i] = 'v';
			}
			if (RESULT[i] == 'W') {
				RESULT[i] = 'w';
			}
			if (RESULT[i] == 'X') {
				RESULT[i] = 'x';
			}
			if (RESULT[i] == 'Y') {
				RESULT[i] = 'y';
			}
			if (RESULT[i] == 'Z') {
				RESULT[i] = 'z';
			}
		}
	}
	
	return RESULT;
}