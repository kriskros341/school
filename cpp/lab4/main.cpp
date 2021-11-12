#include "headers/headers.h"

void ex1() {

	char text[CHARLEN] = "Godzina Ktora?";
	int length{};
	while(text[length] != 0) {
		length++;
	}
	for(int i = length; i >= 0; i--) {
		cout << text[i];
	}
}

//do the harder variant
void ex2() {
	char text[CHARLEN] = "dzisiaj JEST poniedzialek A jutro JEST wtorek";
	char search[] = "aA";
	int res = zliczLitery(text, search);
	cout << "Liczba wystąpień listery a lub A to: " << res << endl;
}

void ex3() {
	char text[] = "podaj liczbę naturalną: ";
	int a = typedInput<int>(text);
	wypiszBinarnie(a);
}

void ex3_wlasne() {
	char text[] = "podaj liczbę naturalną: ";
	int a = typedInput<int>(text);
	char text2[] = "podaj system do którego chcesz przeliczyć: x";
	int b = typedInput<int>(text2);
	wypiszWSystemie(a, b);
}

void ex4() {
	const int size = 4;
	int tablica[size][size] = {
		{1, 2, 3, -1},
		{2, 2, 1, -1},
		{0, 5, 3, 1},
		{1, 6, 0, 1}
	};
	cout << przeciwPrzekatna(tablica, size);
}

void ex5() {
	const int size = 4;

	int tablica[size][size] = {
		{1, 2, 3, -1},
		{2, 2, 1, -1},
		{0, 5, 3, 1},
		{1, 6, 0, 1}
	};
	int **tablica1 = createTable(**tablica, size-1);
}




int main() {
	ex4();
	return 0;
}
