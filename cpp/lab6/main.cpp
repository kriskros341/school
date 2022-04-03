#include <stdlib.h>
#include <iostream>
#include <time.h>


void generuj_losowe(int* wsk, const int rozmiar, int a, int b) {
	std::srand(time(0));
	for (int i{}; i < rozmiar; i++) {
		wsk[i] = a + (std::rand() % b);
	}
}

void wypisz(int* wsk, const int rozmiar) {
	for (int i{}; i < rozmiar; i++) {
		std::cout << wsk[i];
		if (i != rozmiar - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

void ex1() 
{
	const int len = 10;
	int wsk[10]{};
	generuj_losowe(wsk, len, 0, 10);
	wypisz(wsk, len);
}

void konkatenacja(const char* nap1, const char* nap2, char* wynik) {
	int i = 0;
	for (;nap1[i] != '\0'; i++) {
		wynik[i] = nap1[i];
	}
	for (int j{}; nap2[j] != '\0'; j++)
		wynik[i + j] = nap2[j];

	std::cout << wynik << std::endl;
}

void ex2() {
	char g[] = "gg";
	char j[] = "ff";
	char h[5]{};
	konkatenacja(g, j, h);
}

void formatuj(char w[]) {
	for (int i{}; w[i] != '\0'; i++) {
		if (w[i] == ' ') {
			continue;
		}
		if ((int)w[i] <= 90) {
			std::cout << w[i];
		}
		else {
			std::cout << (char)(w[i] - 32);
		}
	}
}

void ex3() {
	char w[100]{};
	char c{};
	int i = 0;
	while (c = std::cin.get()) {
		if (c == '\n')
			break;
		w[i] = c;
		i++;
	}
	std::cout << w << std::endl;
	formatuj(w);
}

void kwadraty(int* t1, int* t2, int n) {
	for (int i{}; i < n; i++) {
		t1[i] = t2[i] * t2[i];
	}
}

void coutt(int* t, int n) {
	for (int i{}; i < n; i++) {
		std::cout << t[i];
	}
	std::cout << std::endl;
}

void ex4() {
	int n{};
	std::cin >> n;
	int* w = new int[n]{};
	int* tab1 = new int[n]{};
	int c{};
	for (int i{}; i < n; i++) {
		std::cin >> w[i];
	}
	coutt(tab1, n);
	coutt(w, n);
	kwadraty(tab1, w, n);
	coutt(tab1, n);
}

int len(char* g) {
	int result = 0;
	for (int i{}; g[i] != '\0'; i++) {
		result++;
	}
	return result;
}

bool isIn(char* n1, char* n2) {
	for (int i{}; i < len(n1) - len(n2); i++) {
		int score = 0;
		for (int j{}; j < len(n2); j++) {
			if (n1[i + j] != n2[j])
				break;
			score++;
		}
		if (score == len(n2)) {
			return true;
		}
	}
	return false;
}



void ex5() {
	char l[] = "klagsa";
	char l2[] = "las";
	std::cout << isIn(l, l2) << std::endl;
}

//insetion sort

int main() {
	ex5();
}