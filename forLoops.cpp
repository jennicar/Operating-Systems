#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

const int MAX_ROWS = 10000;
const int MAX_COLS = 10000;

void allocate(int **array) {
	for (int cols = 0; cols < MAX_COLS; cols++) {
		array[cols] = new int[MAX_COLS];
	}
}

void deallocate(int **array) {
	for (int col = 0; col < MAX_COLS; col++) { delete array[col]; }
	delete[] array;
}

void timeGoodLoop(int **array) {
	cout << "*** GOOD LOOPS ****\n";
	cout << "*** Start timer ***\n";
	clock_t startTime = clock();
	for (int col = 0; col < MAX_COLS; col++) {
		for (int row = 0; row < MAX_ROWS; row++) {
			array[col][row] = 0;
		}
	}
	clock_t endTime = clock();
	cout << "*** End timer ***\n";
	double msPassed = endTime - startTime;

	cout << "Start: " << startTime << " ms\n";
	cout << "End: " << endTime << " ms\n";
	cout << "Miliseconds Passed: " << msPassed << " ms\n\n";
}

void timeBadLoop(int **array) {
	cout << "*** BAD LOOPS ****\n";
	cout << "*** Start timer ***\n";
	clock_t startTime = clock();
	for (int row = 0; row < MAX_ROWS; row++) {
		for (int col = 0; col < MAX_COLS; col++) {
			array[col][row] = 0;
		}
	}
	clock_t endTime = clock();
	cout << "*** End timer ***\n";
	double msPassed = endTime - startTime;

	cout << "Start: " << startTime << " ms\n";
	cout << "End: " << endTime << " ms\n";
	cout << "Miliseconds Passed: " << msPassed << " ms\n\n";
}

int main() {
	int **pixels = new int *[MAX_ROWS];
	allocate(pixels);
	timeGoodLoop(pixels);
	timeBadLoop(pixels);
	deallocate(pixels);
	return 0;
}
