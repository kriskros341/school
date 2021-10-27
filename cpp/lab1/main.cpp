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
	double a{}, b{}, c{}, d{};
	char inp1[] = "podaj xA: ";
	a = typedInput<double>(inp1);
	char inp2[] = "podaj xB: ";
	b = typedInput<double>(inp2);
	char inp3[] = "podaj yA: ";
	c = typedInput<double>(inp3);
	char inp4[] = "podaj yB: ";
	d = typedInput<double>(inp4);


}




int main() {
	//ex1();
	//ex2();
	return 0;
}
