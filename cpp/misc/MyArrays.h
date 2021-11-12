#pragma once



//ARRAYS
template <typename T>
T appendFront(T arr[], T val) {
	int length = sizeof(arr) / sizeof(*arr);
	T result[length + 1] = {val};
	for(int i{}; i < length; i++) {
		result[i+1] = arr[i];
	}
	return result;
}


template <typename T>
bool checkIfEmpty(T array[], int arrayLength) {
	for(int i{}; i < arrayLength; i++) {
		if(array[i] != 0) {
			return false;
		}
	}
	return true;
}


template <typename T>
double avgFromArray(T array[], int length) {
	T sum{};
	for (int i{}; i < length; i++) {
		sum += array[i];
	}
	return sum/length;
}
