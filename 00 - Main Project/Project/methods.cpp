#include "system.h"
using namespace std;

void systema::graphical_method(float &kx1, float &b1, float &kx2, float &b2){
	kx1 = (-arr[0][0]) / arr[0][1];
	b1 = arr[0][2] / arr[0][1];

	kx2 = (-arr[1][0]) / arr[1][1];
	b2 = arr[1][2] / arr[1][1];
}