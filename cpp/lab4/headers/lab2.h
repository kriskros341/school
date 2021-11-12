#pragma once
#include <iomanip>
#include <math.h>
#include "../../misc/MyInputUtil.h"
#define CHARLEN 1024
#define ALPHABET "ABCDEFGHIJKLMNOPRSTUVWXYZ"
#define ALPHABET_LENGTH 25
#define DEFAULT_TABLE_SIZE 5

using namespace std;

struct text {
	char *theChar;
	int length;
};

struct li {
	char litera;
	int ilosc;
};

 
int zliczLitery(char* text, char letter) {
	int i{}, result{};
	while(text[i] != 0) {
		if(text[i] == letter) {
			result++;
		}
		i++;
	}
	return result;
}
int zliczLitery(char* text, char* letter) {
	int length = sizeof(letter) / (int)sizeof(*letter), result{};
	for(int i{}; i < length; i++) {
		result += zliczLitery(text, letter[i]);
	}
	return result;
}

void wypiszBinarnie(int n) {
	const int intLength = 24;
	int result[intLength]{};
	for(int i = intLength; n != 0; i--) {
		result[i] = n % 2;
		n /= 2;
	}
	for(int i = 1; i <= intLength; i++) {
		cout << result[i];
		if(i % 8 == 0) {
			cout << " ";
		}
	}
	cout << endl;
}

void coutOverX10(int n, int s) {
	if(s > 10 && n > 10) {
		do {
			cout << ALPHABET[s - n];	
			n -= s;
		} while(n > 10);
		return;
	}
	cout << n;
}


void wypiszWSystemie(int n, int s, int formatting = 8) {
	int length = 24 / (s / 2);
	int *numArray;
	// Initializing array with variable pog
	numArray = new int[length];
	for(int i = length; n != 0; i--) {
		numArray[i] = n % s;
		n /= s;
	}
	for(int i = 1; i <= length; i++) {
		coutOverX10(numArray[i], s);
		if(i % formatting == 0) {
			cout << " ";
		}
	}
	cout << endl;
	delete [] numArray;
}

int przeciwPrzekatna(int** T, int size) {
	cout << T << endl;
	return 0;
}

void coutTable(int** T, int size) {
	for(int i{}; i < size; i++) {
		for(int j{}; j < size; j++) {
			cout << T[i][j];
		}
	}
}
#define MAX_RAND 10
int** createTable(int size) {
	int **tablica1;
	tablica1 = new int *[size];
	for(int i{}; i < size; i++) {
		tablica1[i] = new int[size];
		for(int j{}; j < size; j++) {
			tablica1[i][j] = rand();
		}
	}
	return tablica1;
}


int** createTable(int size, int filler) {
	int **tablica1;
	tablica1 = new int *[size];
	for(int i{}; i < size; i++) {
		tablica1[i] = new int[size];
		for(int j{}; j < size; j++) {
			tablica1[i][j] = filler;
		}
	}
	return tablica1;
}


int** createTable(int **T, int size) {
	int **tablica1;
	tablica1 = new int *[size];
	for(int i{}; i < size; i++) {
		tablica1[i] = new int[size];
		for(int j{}; j < size; j++) {
			tablica1[i][j] = T[i][j];
		}
	}
	return tablica1;
}

int** createTable(int **T) {
	int size = sizeof(*T) / (int)sizeof(**T);
	cout << sizeof(*T) << " " << (int)sizeof(**T) << endl;
	cout << size;
	return createTable(**T, size);
}

void sumTables(int size) {
	/*
	 * Creates randomized tables of given size and sums them up
	*/
	int** tablica1 = createTable(size);
	int** tablica2 = createTable(size);
	int** tablica3 = createTable(size, 0);
	for(int i{}; i < size; i++) {
		for(int j{}; j < size; j++) {
			tablica3[i][j] = tablica1[i][j] + tablica2[i][j]; 
		}
	}
	coutTable(tablica1, size);
	coutTable(tablica2, size);
	coutTable(tablica3, size);
}

int** sumTables(int size, int **tablica1, int target) {
	/* 
	 * Creates a table of integers equal to [target] and 
	 * returns a table, which contents are result of subtraction 
	 * of given new table's and given table's values
	*/
	int** tablica3 = createTable(size, target);
	for(int i{}; i < size; i++) {
		for(int j{}; j < size; j++) {
			tablica3[i][j] -= tablica1[i][j]; 
		}
	}
	coutTable(tablica1, size);
	coutTable(tablica3, size);
	return tablica3;
}

