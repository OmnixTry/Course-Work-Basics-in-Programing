#pragma once
#include <string>
using namespace std;

int how_many_equations(string raw_system);
int how_many_wariables(string raw_system);
bool is_letter(char letter);
bool is_number(char symbol);
void upper_triangle_matrix(double **arr, int length, int height);
int zero_row(double **arr, int height);