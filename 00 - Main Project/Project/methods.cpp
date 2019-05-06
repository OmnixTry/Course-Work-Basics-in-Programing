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
		return"There's infinite nuber of solutions\n";
	}
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
		return"There's infinite nuber of solutions\n";
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