#include <string>
#include "before_solving.h"
#include "system.h"
using namespace std;

void systema::graphical_method(double &kx1, double &b1, double &kx2, double &b2){
	kx1 = (-arr[0][0]) / arr[0][1];
	b1 = arr[0][2] / arr[0][1];

	kx2 = (-arr[1][0]) / arr[1][1];
	b2 = arr[1][2] / arr[1][1];
}

string systema::hauss_method() {
	upper_triangle_matrix(arr, length, height);
	
	// number of variables = number of equations
	if (zero_row(arr, height) == -1) {
		return this->hauss_single_solution();
	}
	else {
		return "Number of equations is not equel to number of variables\n";
	}
}

int systema::hauss_method(int k) {
	upper_triangle_matrix(arr, length, height);

	// number of variables = number of equations
	if (zero_row(arr, height) == -1) {
		return hauss_single_solution(k);
	}
	/*
	else {
		return "Number of equations is not equel to number of variables\n";
	}
	*/
}

int systema::hauss_single_solution(int k) {
	double *results = new double[height];
	double cresult;

	results[height - 1] = arr[height - 1][length - 1] / arr[height - 1][length - 2];

	for (int i = height - 2; i >= 0; i--) {
		cresult = 0;
		for (int j = i + 1; j < length - 1; j++) {
			cresult -= arr[i][j] * results[j];
		}
		cresult += arr[i][length - 1];
		results[i] = cresult;
	}

	string res_to_screen;

	for (int i = 0; i < height; i++) {
		res_to_screen += variables[i];
		res_to_screen += " = ";
		res_to_screen += to_string(results[i]);
		res_to_screen += "\n";
	}

	return results[0];
}

string systema::hauss_single_solution() {
	double *results = new double[height];
	double cresult;

	results[height - 1] = arr[height - 1][length - 1] / arr[height - 1][length - 2];

	for (int i = height - 2; i >= 0; i--) {
		cresult = 0;
		for (int j = i + 1; j < length-1; j++) {
			cresult -= arr[i][j] * results[j];
		}
		cresult += arr[i][length - 1];
		results[i] = cresult;
	}
	
	string res_to_screen;

	for (int i = 0; i < height; i++){
		res_to_screen += variables[i];
		res_to_screen += " = ";
		res_to_screen += to_string(results[i]);
		res_to_screen += "\n";
	}

	return res_to_screen;
}

string systema::jordan_hauss_method() {
	upper_triangle_matrix(arr, length, height);

	// number of variables = number of equations
	if (zero_row(arr, height) == -1) {
		return jordan_hauss_single_solution();
	}
	else {
		return "Number of equations is not equel to number of variables\n";
	}
}

string systema::jordan_hauss_single_solution() {
	arr[height - 1][length - 1] /= arr[height - 1][length - 2];
	arr[height - 1][length - 2] = 1;

	for (int row = height - 1; row > 0; row--) {
		for (int i = row - 1; i >= 0; i--) {
			arr[i][length - 1] -= arr[row][length - 1] * arr[i][row];
			arr[i][row] = 0;
		}
	}
	string result;
	for (int i = 0; i < height; i++) {
		result += variables[i];
		result += " = ";
		result += to_string(arr[i][length - 1]);
		result += "\n";
	}
	return result;
}

string systema::rotation_method() {
	double c;
	double s;
	double *buff1 = new double[length];
	double *buff2 = new double[length];

	for (int column = 0; column < height - 1; column++) {

		for (int row = column + 1; row < height; row++) {
			c = arr[column][column] / sqrt(pow(arr[column][column], 2) + pow(arr[row][column], 2));
			s = arr[row][column] / sqrt(pow(arr[column][column], 2) + pow(arr[row][column], 2));

			for (int i = 0; i < length; i++) {
				buff1[i] = buff2[i] = 0;
			}

			for (int i = column; i < length; i++) {
				buff1[i] = c * arr[column][i] + s * arr[row][i];
				buff2[i] = c * arr[row][i] - s * arr[column][i];
			}
			for (int i = 0; i < length; i++) {
				arr[column][i] = buff1[i];
				arr[row][i] = buff2[i];
			}
		}
	}

	if (zero_row(arr, height) != -1) {
		return "Number of equations is not equel to number of variables\n";
	}

	for (int row = height - 1; row > 0; row -= 1) {

		arr[row][length - 1] /= arr[row][row];
		arr[row][row] = 1;
		for (int i = row - 1; i >= 0; i--) {
			arr[i][length - 1] -= arr[row][length - 1] * arr[i][row];
			arr[i][row] = 0;
		}

	}

	arr[0][length - 1] /= arr[0][0];
	arr[0][0] = 1;
	string result;

	for (int i = 0; i < height; i++) {
		result += variables[i];
		result += " = ";
		result += to_string(arr[i][length - 1]);
		result += "\n";
	}
	return result;
}