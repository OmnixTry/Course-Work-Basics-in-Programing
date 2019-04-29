#include "system.h"
#include "before_solving.h"
//#include "MyForm.h"
using namespace std;

void systema::create_system(string str) {
	height = how_many_wariables(str);
	length = height + 1;
	// create the array of zeroes
	arr = new int*[height];
	for (int i = 0; i < height; i++) {
		arr[i] = new int[length];
	}
	for (int i = 0; i < height; i++)
		for (int j = 0; j < length; j++)
			arr[i][j] = 0;

	//getting the list of variables
	for (int i = 0; i < str.size(); i++) {
		if ((variables.find(str[i]) == string::npos) && is_letter(str[i])) {
			variables += str[i];
		}
	}




}