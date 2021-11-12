#pragma once
#include <iostream>
#define FROMCIN_MAX_LEN 1024


template <typename T>
T typedInput() {
	T v;
	std::cin >> v;
	std::cin.clear();
	return v;
}

template <typename Type>
Type typedInput(char text[FROMCIN_MAX_LEN]) {
	Type v;
	std::cout << text;
	std::cin >> v;
	std::cin.clear();
	return v;
}


template <typename T>
void fillArrayWithInput(T arr[], int arrLength) {
	for(int i{}; i < arrLength; i++) {
		char text[] = "input: ";
		arr[i] = typedInput<T>(text);
	}
}
