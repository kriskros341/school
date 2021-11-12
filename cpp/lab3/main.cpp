#include "headers/headers.h"

void ex1() {
	cout << sumaCyfr(1487) << endl;
}

void ex2() {
	cout << nwd(7, 14) << endl;
}

void ex3() {
	cout << czyPierwsza(23) << endl;
}

void ex4() {
	pow(3);
	pow(2, 3);
	pow(3.00);
	pow(3.00, 3);
	int a = 1;
	int& p = a;
	pow(p, 4, 3);
}

void ex5() {
	kantor(500);
}

int main() {
	ex5();
	return 0;
}
