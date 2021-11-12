#pragma once
#define MAX_POLYNOMINAL_LENGTH 12
#include <iostream>
#include "MyInputUtil.h"
#include <stdlib.h>
#include <math.h>

using namespace std;

// Nightmare
void printNominal(double currentNominal, int* nominalsCount, bool* hasStarted) {
	//If no nominal of this power
	if(currentNominal == 0) {
		return;
	}
	// in case currentNominal is not the first to cout
	if(*hasStarted) {
		if (currentNominal < 0) {
			cout << " - ";
		} else {
			cout << " + ";
		}
		if(*nominalsCount == 0) {
			cout << abs(currentNominal);
			return;
		}
		if(currentNominal == 1 || currentNominal == -1) {
			cout << "x";
		} else {
			cout << abs(currentNominal) << "x";
		}
		if(*nominalsCount > 1) {
			cout << "^" << *nominalsCount;
		}
	}
	// in case currentNominal is the first to cout
	else {
		// in case currentNominal is first and the last simuntaneously;
		if(*nominalsCount == 0) {
			cout << currentNominal;
			return;
		}
		// in case currentNominal is equal to 1
		if(currentNominal == 1) {
			cout << "x";
		}
		// in case currentNominal is equal to -1
		else if(currentNominal == -1) {
			cout << "-x";
		}
		else {
			cout << currentNominal << "x";
		}
		if(*nominalsCount != 1) {
			cout << "^" << *nominalsCount;
		}
		*hasStarted = true;
	}
}


template <class NumericType>
class Polynominal {
	public:
		int nominalsCount{};
		NumericType nominals[MAX_POLYNOMINAL_LENGTH]{};
		Polynominal(NumericType nominals[], int length) {
			this->nominalsCount = length-1;
			this->fillMeWith(nominals, length);
		}
		void printMe() {
			int nominalsCount = this->nominalsCount;
			bool hasStarted = false;
			cout << "f(x) = ";
			for(int i{}; i < MAX_POLYNOMINAL_LENGTH; i++) {
				NumericType currentNominal = this->nominals[i];
				printNominal(currentNominal, &nominalsCount, &hasStarted);
				nominalsCount--;
			}
			cout << endl;
		}

		NumericType solveMe(NumericType x) {
			return this->commonSolve(x);
		};

		NumericType solveMe() {
			char text[] = "Podaj x: ";
			NumericType x = typedInput<NumericType>(text);
			return this->commonSolve(x);
		}

		NumericType commonSolve(NumericType x) {
			NumericType result = 0;
			int nominalsCount = this->nominalsCount;
			for(int i{}; i < MAX_POLYNOMINAL_LENGTH; i++) {
				NumericType a = this->nominals[i];
				if(a != 0) {
					result += a * pow(x, nominalsCount--);
				}
			}
			return result;
		}
		void fillMeWith(NumericType nominals[], int length) {
			if(length > MAX_POLYNOMINAL_LENGTH) {
				cout << "Max polynominal length is set to " << MAX_POLYNOMINAL_LENGTH-1 << endl;
				exit( 0 );
			}
			for(int i{}; i < length; i++) {
				this->nominals[i] = nominals[i];
			}
		};
};

template <class NumericType>
class PolynominalRefactored {
	int nominalsCount{};
	NumericType nominals[MAX_POLYNOMINAL_LENGTH]{};
	
};

// anything that is not private is accessible
// a[i] == *(a+i)

struct RootsModel {
	double x1;
	double x2;
	bool exists;
};

template <class T = double>
class QuadriaticEquation : public Polynominal<T> {
	public: 
		//using Polynominal<NumericType>::Polynominal;
		QuadriaticEquation(T arr[], int length) : Polynominal<T>(arr, length) {};
		double getDelta() {
			if(this->nominalsCount != 2) {
				cout << "given polynominaln is not quadriatic!" << endl;
				exit( 0 );
			}
			double a = this->nominals[0];
			double b = this->nominals[1];
			double c = this->nominals[2];
			cout << a << b << c << endl;
			double result = b*b - 4*a*c;
			return result;
		}
		RootsModel getRoots() {
			double a = this->nominals[0], b = this->nominals[1], c = this->nominals[2];
			double delta = this->getDelta();
			RootsModel roots;
			if(delta > 0) {
				roots.x1 = (-1 * b - sqrt(delta)) / (2 * a);
				roots.x2 = (-1 * b + sqrt(delta)) / (2 * a);
				roots.exists = true;
			}
			if(delta == 0) {
				double theOnlyRoot = (-1 * b) / (2 * a);
				roots.x1 = (-1 * b) / (2 * a);
				roots.x2 = (-1 * b) / (2 * a);
				roots.exists = true;
			}
			if(delta < 0) {
				roots.exists = false;
			}
			return roots;
		}
};
