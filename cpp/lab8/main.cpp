#include <iostream>
#include <cmath>

void calc(int argc, char** argv) {
	int v1 = std::atoi(argv[1]);
	char o = *argv[2];
	int v2 = std::atoi(argv[3]);

	switch (o) {
	case('+'): {
		std::cout << v1 + v2 << std::endl;
		break;
	}
	case('-'): {
		std::cout << v1 - v2 << std::endl;
		break;
	}
	case('x'): {
		std::cout << v1 * v2 << std::endl;
		break;
	}
	case('/'): {
		if (v2 == 0)
			break;
		std::cout << v1 / v2 << std::endl;
		break;
	}
	}
}

double fn1(double x) {
	return x * x - 9;
}

double fn2(double x) {
	return std::sin(x);
}

double fn3(double x) {
	return x * x * x + 6 * x * x - 144 * x + 256;
}

double bisekcja(double(*fn)(double x), double e, double a, double b) {
	double m;
	while (std::abs(b - a) >= 2 * e) {
		m = (b + a) / 2;
		if (fn(m) == 0) {
			return m;
		}
		if (fn(a) * fn(m) < 0) {
			b = m;
		}
		else {
			a = m;
		}
	}

	return m;
}

int main(int argc, char** argv) {
	std::cout << bisekcja(fn1, 0.001, 0, 5) << std::endl;
	std::cout << bisekcja(fn2, 0.001, 1, 5) << std::endl;
	std::cout << bisekcja(fn3, 0.001, 5, 20) << std::endl;
}