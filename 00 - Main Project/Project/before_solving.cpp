#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

bool is_letter(char letter) {
	if (((letter >= 'a') && (letter <= 'z')) || ((letter >= 'A') && (letter <= 'Z'))) {
		return true;
	}
	return false;
}

bool is_number(char symbol) {
	if ((symbol >= '0') && (symbol <= '9'))
		return true;
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

void upper_triangle_matrix(double **arr, int length, int height) {
	double *buff;
	double multiplication;
	for (int row = 0; row < height-1; row++) {
		for (int i = row; i < height; i++) {
			if (arr[i][row] != 0) {
				buff = arr[row];
				arr[row] = arr[i];
				arr[i] = buff;
				break;
			}
		}
		multiplication = arr[row][row];
		for (int i = row; i < (length); i++) {
			arr[row][i] /= multiplication;
		}

		for (int i = row + 1; i < height; i++) {
			multiplication = arr[i][row];
			for (int j = row; j < length; j++) {
				arr[i][j] -= (arr[row][j])*multiplication;
			}
		}
	}
	//system("pause");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			cout << setw(8) << arr[i][j];
		}
		cout << endl;

	}
}

int zero_row(double **arr, int height) {
	int j;
	for (int i = 0; i < height; i++) {
		for (j = 0; j < height; j++) {
			if (arr[i][j] != 0) break;
		}
		if (j == height) return i;
	}
	return -1;
}

int get_determinant(double **arr, int size) {
	double **copy = new double*[size];
	for (int i = 0; i < size; i++) {
		copy[i] = new double[size];
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			copy[i][j] = arr[i][j];

	//coppied code fron upper triangle matrix;
	double determinant = 1;
	double *buff;
	double multiplication;
	for (int row = 0; row < size - 1; row++) {
		for (int i = row; i < size; i++) {
			if (copy[i][row] != 0) {
				buff = copy[row];
				copy[row] = copy[i];
				copy[i] = buff;
				break;
			}
		}
		multiplication = copy[row][row];
		determinant *= multiplication;
		for (int i = row; i < (size); i++) {
			copy[row][i] /= multiplication;
		}

		for (int i = row + 1; i < size; i++) {
			multiplication = copy[i][row];
			for (int j = row; j < size; j++) {
				copy[i][j] -= (copy[row][j])*multiplication;
			}
		}
	}
	multiplication *= copy[size - 1][size - 1];
	for (int i = 0; i < size; i++) {
		delete[] copy[i];
	}
	delete[]copy;
	return determinant;
}



/*
2x+4y+4z+5k=0
x+2y+9z+8k=5
7x+7y+3z+4k=6
3x+4y+5z+6k=7
x+2y+3z+4k+5p=9
*/