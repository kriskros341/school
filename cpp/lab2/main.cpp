#include "headers/headers.h"

void ex1() {
	const int length = 3;
	double arr[length]{};
	double roots[2]{};
	char text1[] = "Podaj a: ";
	arr[0] = typedInput<double>(text1);
	char text2[] = "Podaj b: ";
	arr[1] = typedInput<double>(text2);
	char text3[] = "Podaj c: ";
	arr[2] = typedInput<double>(text3);
	auto p = QuadriaticEquation<double>(arr, length);
	cout << "funkcja kwadratowa: "; p.printMe();
	auto r = p.getRoots();
	if(r.exists) {
		if(roots[0] == roots[1]) {
			cout << "Ma jedno miejsce zerowe w punkcie " << roots[0];
		} else {
			cout << "Ma dwa miejsca zerowe w punktach x1=" << roots[0] << " i x2=" << roots[1];
		}
	}
	else {
		cout << "Ta funkcja nie ma miejsc zerowych" << endl;
	}
}

void ex2() {
	writeATable(3);
}

void ex3() {
	makeASlope(5);
}

void ex4() {
	multiplicationTable();
}

void ex5() {
	calculatorInterface();
}

int main() {
	ex5();
	return 0;
}
