#include <string>
#pragma once
using namespace std;

class systema {
private:
	string variables;
	float **arr;
	int height;
	int length;
	
	
public:
	void graphical_method(float &kx1, float &b1, float &kx2, float &b2);
	void create_system(string str);
	System::String^ matrix();
	int number_of_variables();
	//bool solve(int selected_method, string &result);
	


};