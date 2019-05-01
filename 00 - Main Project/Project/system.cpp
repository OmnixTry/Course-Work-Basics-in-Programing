#include "system.h"
#include "before_solving.h"
#include <stdlib.h>
#include <string>
#include <msclr\marshal_cppstd.h>
//#include "MyForm.h"
using namespace std;

void systema::create_system(string str) {
	height = how_many_wariables(str);
	length = height + 1;
	// create the array of zeroes
	arr = new float*[height];
	for (int i = 0; i < height; i++) {
		arr[i] = new float[length];
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

	//making matrix
	double cnumber = 0; //Number we are going to put into the matrix
	int row = 0; // Number of te row in matrix;
	//string help;
	bool plus = true; // shows is number positive or negative
	bool coma = false; // shows presence of coma
	float multiply_coma = 1;

	str += "\n";

	for (int i = 0; i < str.size(); i++) {
		if (is_number(str[i])) {
			if (!coma) {
				cnumber *= 10;
				cnumber += (int)str[i] - 48;
			}
			else{
				multiply_coma *= 0.1;
				cnumber += ((int)str[i] - 48) * multiply_coma;
			}
		}
		else if ((is_letter(str[i])) && (variables.find_first_of(str[i]) != string::npos)) {
			if (cnumber == 0) {
				cnumber = 1;
			}
			arr[row][variables.find_first_of(str[i])] = plus ? cnumber : cnumber * (-1);
			cnumber = 0;
			plus = true;
			coma = false;
			multiply_coma = 1;
		}
		else if (str[i] == '-') {
			plus = false;
		}
		else if ((str[i] == '.')||(str[i] == ',')) {
			coma = true;
		}
		else if (str[i] == '\n') {
			arr[row][length - 1] = plus ? cnumber : cnumber * (-1);
			row++;
			cnumber = 0;
			plus = true;
			coma = false;
			multiply_coma = 1;
		}
	}


}

System::String^ systema::matrix() {
	System::String^ the_str;
	string help;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			help = to_string(arr[i][j]);
			for (int i = help.size() - 1; i >= 0; i--) {
				if (help[i] != '0') break;
				else {
					help.erase(i);
				}
			}
			if(help[help.size()-1] == '.') help.erase(help.size() - 1);

			while(help.size() <= 5){
				help += " ";
			}
			msclr::interop::marshal_context context;
			the_str += context.marshal_as<System::String^>(help);
			//the_str += marshal_as<String^>(help);
			//the_str += arr[i][j];
			//the_str += " ";
		}
		the_str += "\n";
	}
	return the_str;
}

/*for (int i = 0; i < height; i++) {
	row = str.substr(0, str.find_first_of('\n'));
	str.erase(0, str.find_first_of('\n') + 1);

	do {
		help = row.substr(0, );
	} while (row.size() != 0);
}*/