#pragma once

#include <iostream>
#include <math.h>
#include "../../misc/MyInputUtil.h"

using namespace std;

void writeATable(int number) {
	cout << "0)  ";
	for(int i{}; i < 101; i++) {
		if (i % number == 0) {
			cout.width(5);
			cout << i;
		}
		if (i % 10 == 0) {
			cout << endl;
			cout << i / 10 << ")  ";
		}
	}
}

void makeASlope(int n) {
	for(int i{}; i < n; i++) {
		for (int j = n-i; j > 0; j--) {
			cout << "*";
		}
		cout << endl;
	}
}


void multiplicationTable() {
	cout.width(5);
	cout << "*|";
	for (int i = 1; i <= 10; i++) {
		cout.width(4);
		cout << i;
	}
	cout << endl;
	cout << "---------------------------------------------";
	cout << endl;

	for(int i = 1; i <= 10; i++) {
		bool first = true;
		for (int j = 1; j <= 10; j++) {
			if(first) {
				cout.width(4);
				cout << i << "|";
				first = false;
			}
			cout.width(4);
			cout << j*i;
		}
		cout << endl;
	}
}

template <typename T = int>
struct calcModel {
	T a{};
	char action;
	T b{};
};

void calculatorInterface() {
	while(true) {
		calcModel<int> calc;
		cout << "Podaj a: ";
		calc.a = typedInput<int>();
		cout << "Podaj akcje: ";
		cin >> calc.action;
		cout << "Podaj b: ";
		calc.b = typedInput<int>();
		switch(calc.action) {
			case '+':
				cout << calc.a + calc.b << endl;
				break;
			case '-':
				cout << calc.a - calc.b << endl;
				break;
			case '*':
				cout << calc.a * calc.b << endl;
				break;
			case '/':
				if(calc.b != 0) {
					cout << calc.a / calc.b << endl;
					break;
				}
				cout << "brak wyniku" << endl;
		}
		char c{};
		cout << "Czy kontynuować? [Y/n]: ";
		cin >> c;
		if(c == 'n') {
			break;
		}
	}
}

