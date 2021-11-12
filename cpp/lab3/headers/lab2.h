#pragma once

#include <iomanip>
#include <math.h>
#include "../../misc/MyInputUtil.h"

#define EUR 4.61
#define USD 3.99
#define NKR 2.12

using namespace std;

int sumaCyfr(int n) {
	int result = 0;
	while(n) {
		result += n % 10;
		n = n / 10;
	}
	return result;
}

int nwd(int a, int b) {
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

bool czyPierwsza(int a) {
	cout << sqrt(a) << endl;
	for(int i = 2; i < (int)sqrt(a); i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

int pow(int base, int exponent = 2) {
	int result = base;
	for(int i{}; i < exponent-1; i++) {
		result *= base;
	}
	return result;
}

int pow(double base, int exponent = 2) {
	int result = base;
	for(int i{}; i < exponent-1; i++) {
		result *= base;
	}
	return result;
}
//references are safer than pointers
void pow(int &result, int base, int exponent) {
	int r = base;
	for(int i{}; i < exponent-1; i++) {
		r *= base;
	}
	result = r;
}

void multicout(char *n, int count) {
	for(int i{}; i < count; i++) {
		cout << *n;
	}
	cout << endl;
}

void kantor(int PLN) {
	int WIDTH = 30;
	cout << "Za kwotę " << PLN << " możesz zakupić: ";
	cout << endl;
	char filler[] = "*";
	cout << endl;
	multicout(filler, WIDTH);
	double euro = PLN / EUR;
	cout.width(WIDTH/2);
	// INNA BIBLIOTEKA DO CLI
	cout << setprecision(2) << fixed << euro << " euro," << endl;

	double usd = PLN / USD;
	cout.width(WIDTH/2);
	cout << setprecision(2) << fixed << usd << " dolarów," << endl;

	double nkr = PLN / NKR;
	cout.width(WIDTH/2);
	cout << setprecision(2) << fixed << nkr << " koron norweskich." << endl;

	multicout(filler, WIDTH);
}


