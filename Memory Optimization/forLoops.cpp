#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <windows.h>

using namespace std;

void timeBadLoop(int array[1024][500]){
	cout << "Bad Loop\n";
	clock_t startTime = clock();
	for (int row = 0; row < 500; row++){
		for (int col = 0; col < 1024; col++){
			array[col][row] = 0;
		}
	}
	clock_t endTime = clock();
	double duration = endTime - startTime;
	
	cout << "Start: " << startTime << " seconds" << endl;
	cout << "End: " << endTime << " seconds" << endl;
	cout << "Duration: " << duration << " seconds" << endl;
}

void timeGoodLoop(int array[1024][500]){
	cout << "Bad Loop\n";
	clock_t startTime = clock();
	for (int col = 0; col < 1024; col++){
		for (int row = 0; row < 500; row++){
			array[col][row] = 0;
		}
	}
	clock_t endTime = clock();
	double duration = endTime - startTime;
	
	cout << "Start: " << startTime << " seconds" << endl;
	cout << "End: " << endTime << " seconds" << endl;
	cout << "Duration: " << duration << " seconds" << endl;
}

int main(){
	int pixels[1024][500];
	timeBadLoop(pixels);
	timeGoodLoop(pixels);
	return 0;
}
