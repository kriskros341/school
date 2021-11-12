#pragma once
#include <iostream>
#include <math.h>

using namespace std;


template <typename Type>
void coutEquation(Type a, Type b, char action) {
	switch(action) {
		case '+':
			cout << a << "+" << b << "=" << a+b;
			break;
		case '-':
			cout << a << "-" << b << "=" << a-b;
			break;
		case '*':
			cout << a << "*" << b << "=" << a*b;
			break;
		case '/':
			if(b == 0) {
				cout << "PAMIĘTAJ CHOLERO NIE DZIEL PRZEZ ZERO" << endl;
				break;
			}
			cout << a << "/" << b << "=" << a/b;
			break;
	}
	cout << endl;
}

//https://cyrkiel.info/liceum/wzory-na-pole-trojkata/
double HeronsTriangleSurfaceFormula(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}


double HeronsTriangleSurfaceFormula(double arr[2]) {
	double a = arr[0], b = arr[1], c = arr[2];
	return HeronsTriangleSurfaceFormula(a, b, c);
}
