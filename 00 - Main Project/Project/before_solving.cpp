#include <string>
using namespace std;

bool is_letter(char letter) {
	if (((letter >= 'a') && (letter <= 'z')) || ((letter >= 'A') && (letter <= 'Z'))) {
		return true;
	}
	return false;
}

int how_many_wariables(string raw_system) {
	string variables;
	int how_many = 0;
	for (int i = 0; i < raw_system.size(); i++) {
		if ((variables.find(raw_system[i]) == string::npos) && is_letter(raw_system[i])) {
			variables += raw_system[i];
			how_many++;
		}
	}
	return how_many;
}