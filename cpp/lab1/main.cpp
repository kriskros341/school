#include "headers/lab1.h"
#define FROMCIN_MAX_LEN 1024


// Generic bardzo podobny do tego w typescript <3
// made to simulate python input("text:")
template <typename Type>
Type typedInput(char text[FROMCIN_MAX_LEN]) {
	Type v;
	cout << text;
	cin >> v;
	cin.clear();
	return v;
}

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

template <typename T>
double avgFromArray(T array[], int length) {
	T sum{};
	for (int i{}; i < length; i++) {
		sum += array[i];
	}
	return sum/length;
}


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

double pow(double x, int p) {
	double result = 1;
	for(int i{}; i < p; i++) {
		result *= x;
	}
	return result;
}

class Polynominal {
	#define MAX_POLYNOMINAL_LENGTH 6
	private:
		int nominalsCount{};
		double nominals[MAX_POLYNOMINAL_LENGTH]{};
		
		void fillMeWith(double nominals[], int length) {
			if(length > MAX_POLYNOMINAL_LENGTH) {
				cout << "Max polynominal length is set to " << MAX_POLYNOMINAL_LENGTH-1 << endl;
				return;
			}
			for(int i{}; i < length; i++) {
				this->nominals[i] = nominals[i];
			}
		};

	public:
		Polynominal(double nominals[], int length) {
			this->nominalsCount = length-1;
			this->fillMeWith(nominals, length);
		}

		double solveMe(double x) {
			double result = 0;
			int nominalsCount = this->nominalsCount;
			for(int i{}; i < MAX_POLYNOMINAL_LENGTH; i++) {
				double a = this->nominals[i];
				if(a != 0) {
					result += a * pow(x, nominalsCount--);
				}

			}
			return result;
		};

		void printMe() {
			int nominalsCount = this->nominalsCount;
			bool hasStarted = false;
			cout << "f(x) = ";
			for(int i{}; i < MAX_POLYNOMINAL_LENGTH; i++) {
				auto a = this->nominals[i];
				if(hasStarted) {
					if (a < 0) {
						cout << " - ";
					}
					if (a > 0) {
						cout << " + ";
					}
				}
				if(a == 0) {
					nominalsCount--;
					continue;
				}
				else if(a == 1) {
					cout << "x^" << nominalsCount--;
					hasStarted = true;
					continue;
				}
				else if(a == -1) {
					cout << "-x^" << nominalsCount--;
					hasStarted = true;
					continue;
				}
				else {
					if(not hasStarted) {
						cout << a;
					}
					else {
						cout << abs(a);
					}
					hasStarted = true;
				}
				if(nominalsCount == 1) {
					cout << "x";
					nominalsCount--;
				}
				else if(nominalsCount == 0) {
				
				}
				else
				{
					cout << "x^" << nominalsCount--;
				}
				
			}
			cout << endl;
		}

};

template <typename T>
void polynominalEquation(T as[], int length, double x) {
	
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
	
	Polynominal p = Polynominal(nominals, nominalsCount);
	p.printMe();

	cout << "f(" << x << ") = " << p.solveMe(x) << endl;
}


int main() {
	//ex1();
	//ex2();
	//ex3();
	ex4();
	return 0;
}
