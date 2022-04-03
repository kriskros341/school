#include <iostream>
#include <stdlib.h>
#include <time.h>

void zlicz(char buff[]) {
	char alphabet[] = "abcdefghijklmnoprstuvwxyz";

	unsigned int max = 0;
	char maxL{};
	for (int i{}; alphabet[i] != '\0'; i++) {
		unsigned int count = 0;
		for (int j{}; buff[j] != '\0'; j++) {
			if (alphabet[i] == buff[j] || alphabet[i] == (int)buff[j] + 32) {
				count++;
				if (count > max) {
					max = count;
					maxL = alphabet[i];
				}
			}
		}
	}
	std::cout << max << " " << maxL << std::endl;;
}


void ex1() {
	char buff[100]{};
	char c{};
	int i = 0;
	while (c = std::cin.get()) {
		if (c == '\n')
			break;
		buff[i] = c;
		i++;
	}
	zlicz(buff);
}

int zlicz(int **mat) {
	int sum{};
	for (int i{}; i < 5; i++) {
		for (int j{}; j < 5; j++) {
			if (i < j) {
				sum += mat[i][j];
			};
		};
	};
	return sum;
}

int** randMat() {
	std::srand(time(0));
	int** mat = new int*[5];
	for (int i{}; i < 5; i++) {
		mat[i] = new int[5];
	}

	for (int i{}; i < 5; i++) {
		for (int j{}; j < 5; j++) {
			mat[i][j] = std::rand();
		}
	}
	return mat;
}

void ex2() {
	int mat[5][5] = {
		{ 1, 1, 1, 1, 2 },
		{ 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1 }
	};
	int** mat2 = randMat();
	
	std::cout << zlicz(mat2) << std::endl;
}

//sudoku

int main() {
	ex2();

}