#include "headers/headers.h"
#define MAX_POLYNOMINAL_LENGTH 12


void ex1() {
	double a{}, b{};
	char podaj1[] = "Podaj a: "; 
	a = typedInput<double>(podaj1);
	char podaj2[] = "Podaj b: ";
	b = typedInput<double>(podaj2); 
	coutEquation<double>(a, b, '+');
	coutEquation<double>(a, b, '-');
	coutEquation<double>(a, b, '*');
	coutEquation<double>(a, b, '/');
	double arr[] = {a, b};
	int length = sizeof(arr)/sizeof(*arr);
	double avg = avgFromArray<double>(arr, length);
	cout << "Srednia z " << a << " i " << b << " to " << avg << endl;
}


void ex2() {
	cout << "--------" << endl;
	cout << "| żółw |" << endl;
	cout << "--------" << endl;
	cout << " brak mi cierpliwości" << endl;

	char tl = 0xC9;
	char tb = 0xCD;
	char tr = 0xBB;
	char lr = 0xBA;
	char bl = 0xC8;
	char br = 0xBC;
	cout << "nie pamietam jak ustawic kodowanie" << endl;
}


void ex3() {
	double xA{}, xB{}, yA{}, yB{};
	char inp1[] = "podaj xA: ";
	xA = typedInput<double>(inp1);
	char inp3[] = "podaj yA: ";
	yA = typedInput<double>(inp3);
	char inp2[] = "podaj xB: ";
	xB = typedInput<double>(inp2);
	char inp4[] = "podaj yB: ";
	yB = typedInput<double>(inp4);
	/*
	 * a: Ay - By / Ax - Bx
	 * b = f(0)
	 */
	double a{};
	double b{};
	if(xB == xA) {
		cout << "Funkcja liniowa nie może przyjąć więcej niż jednej wartości w punkcie na osi x" << endl;
		return;
	}
	a = (yB - yA) / (xB - xA);
	b = yA - a * xA;
	char sign = (b > 0) ? '-' : '+';
	cout << "y = ";
	if(a != 1) {
		if(a == -1) {
			cout << "-";
		}
		if(a != 0) {
			cout << a;
		}
	}
	cout << "x";
	if(b != 0) {
		cout << " " << sign << " " << b;
	}
	cout << endl;
}


void ex4() {
	//DLACZEGO FORMATOWANIE CSTRINGÓW TO JEST RAKOWE BEZ INTERPOLACJI
	double a, b, c, x{};
	char inp1[] = "podaj a: ";
	a = typedInput<double>(inp1);
	char inp3[] = "podaj b: ";
	b = typedInput<double>(inp3);
	char inp2[] = "podaj c: ";
	c = typedInput<double>(inp2);
	
	char inp4[] = "podaj x: ";
	x = typedInput<double>(inp4);
	
	const int nominalsCount = 3;
	double nominals[nominalsCount] = {a, b, c};
	
	auto p = Polynominal<double>(nominals, nominalsCount);
	p.printMe();

	cout << "f(" << x << ") = " << p.solveMe(x) << endl;
}

void ex4_wlasne() {
	double nominals[MAX_POLYNOMINAL_LENGTH]{};
	int i{};
	for(; i < MAX_POLYNOMINAL_LENGTH; i++) {
		char text[] = "Podaj składnik";
		double n = typedInput<double>(text);
		if(n == 2137) {
			break;
		}
		nominals[i] = n;
	}
	auto p = Polynominal<double>(nominals, i);
	p.printMe();
	cout << p.solveMe() << endl;
}


void ex5() {
	const int length = 3;
	double arr[length];
	char text[] = "Podaj bok trójkąta: ";
	fillArrayWithInput<double>(arr, length);
	cout << HeronsTriangleSurfaceFormula(arr);
}

int main() {
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	//ex4_wlasne();
	ex5();
	return 0;
}
