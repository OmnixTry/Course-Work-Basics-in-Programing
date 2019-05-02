#include <string>
#pragma once
using namespace std;

class systema {
private:
	string variables;
	double **arr;
	int height;
	int length;
	
	
public:
	string hauss_method();
	string hauss_single_solution();
	void graphical_method(double &kx1, double &b1, double &kx2, double &b2);
	void create_system(string str);
	System::String^ matrix();
	int number_of_variables();
	//bool solve(int selected_method, string &result);
	


};