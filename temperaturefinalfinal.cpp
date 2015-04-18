#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double printArray(double mainArray[][26], int sizeX, int sizeY, int many);

int main(){
	int initArraySizeX, initArraySizeY;
	double initTopEdge, initBottomEdge, initLeftEdge, initRightEdge;
	double epsilon, tempDiff;
	double arraySum = 0, arrayAverage = 0, maxDiff = 0;
	int i = 0, j = 0, k = 0;
	int iteration = 0;
	cout << "Please enter the size of the array: \n";
	cout << "Array Rows: ";
	cin >> initArraySizeX;
	cout << "Array Columns: ";
	cin >> initArraySizeY;
	while (((initArraySizeX<0) || (initArraySizeX>26)) || ((initArraySizeY<0) || initArraySizeY>30)){
		cout << "Array cannot be bigger than 26 by 30, nor less than 1. Renter values please" << endl;
		cout << "Array Rows: " << endl;
		cin >> initArraySizeX;
		cout << "Array Columns: " << endl;
		cin >> initArraySizeY;
	}
	//double Array[initArraySizeX][initArraySizeY];
	double Array[30][26];
	cout << "What is the temperature of the top edge: ";
	cin >> initTopEdge;
	while ((initTopEdge<0) || (initTopEdge>300)){
		cout << "Temperature cannot be greater than 300 or less than 0" << endl;
		cout << "What is the temperature of the top edge: ";
		cin >> initTopEdge;
	}
	cout << "What is the temperature of the bottom edge: ";
	cin >> initBottomEdge;
	while ((initBottomEdge<0) || (initBottomEdge>300)){
		cout << "Temperature cannot be greater than 300 or less than 0" << endl;
		cout << "What is the temperature of the bottom edge: ";
		cin >> initBottomEdge;
	}
	cout << "What is the temperature of the left edge: ";
	cin >> initLeftEdge;
	while ((initLeftEdge<0) || (initLeftEdge>300)){
		cout << "Temperature cannot be greater than 300 or less than 0" << endl;
		cout << "What is the temperature of the left edge: ";
		cin >> initLeftEdge;
	}
	cout << "What is the temperature of the right edge: ";
	cin >> initRightEdge;
	while ((initRightEdge<0) || (initRightEdge>300)){
		cout << "Temperature cannot be greater than 300 or less than 0" << endl;
		cout << "What is the temperature of the right edge: ";
		cin >> initRightEdge;
	}
	cout << "What is the value of epsilon: ";
	cin >> epsilon;
	while (epsilon<0){
		cout << "Epsilon cannot be less than 0!" << endl;
		cout << "What is the value of epsilon: ";
		cin >> epsilon;
	}

	//Setting Temperature of edges
	//Double Check these
	for (i = 1; i<initArraySizeY - 1; i++){
		Array[0][i] = initTopEdge;
	}

	for (i = 1; i<initArraySizeY - 1; i++){
		Array[initArraySizeX - 1][i] = initBottomEdge;
	}

	for (i = 1; i<initArraySizeX - 1; i++){
		Array[i][0] = initLeftEdge;
	}

	for (i = 1; i<initArraySizeX - 1; i++){
		Array[i][initArraySizeY - 1] = initRightEdge;
	}

	//Calculating Corners
	//TopLeft

	Array[0][0] = (((Array[1][0]) + Array[0][1]) / 2);

	//TopRight

	Array[0][initArraySizeY - 1] = (((Array[0][initArraySizeY - 2]) + Array[1][initArraySizeY - 1]) / 2);

	//BottomLeft

	Array[initArraySizeX - 1][0] = (((Array[initArraySizeX - 2][0]) + Array[initArraySizeX - 1][1]) / 2);

	//Bottom Right

	Array[initArraySizeX - 1][initArraySizeY - 1] = (((Array[initArraySizeX - 1][initArraySizeY - 2]) + Array[initArraySizeX - 2][initArraySizeY - 1]) / 2);

	//Iteration Run
	//epsilon is done right
	tempDiff = epsilon + 1;
	while (tempDiff>epsilon){
		//while(iteration<300){
		for (i = 1; i<initArraySizeX - 1; i++){
			for (j = 1; j<initArraySizeY - 1; j++){
				maxDiff = Array[i][j];
				Array[i][j] = (((Array[i - 1][j]) + (Array[i][j - 1]) + (Array[i + 1][j]) + (Array[i][j + 1])) / 4);
				if (abs(Array[i][j] - maxDiff)<epsilon){
					tempDiff = abs(Array[i][j] - maxDiff);
					//iteration += 1;
				}
				//iteration += 1;
			}
			//iteration += 1;
		}
		iteration += 1;
	}

	//OutputArrayPrototype
	/*
	cout << endl << "Array: " << endl;
	for (i = 0; i < initArraySizeX; i++){
	for(j = 0; j < initArraySizeY; j++){
	cout << fixed << setw(5) << showpoint << setprecision(1) << Array[i][j] << " ";
	}
	cout << endl;
	}
	cout << endl << "Iteration: " << iteration << endl;
	*/
	printArray(Array, initArraySizeX, initArraySizeY, iteration);
	return 0;
}

double printArray(double mainArray[][26], int sizeX, int sizeY, int many){
	int i, j;
	cout << endl << "Array: " << endl;
	for (i = 0; i < sizeX; i++){
		for (j = 0; j < sizeY; j++){
			cout << fixed << setw(5) << showpoint << setprecision(1) << mainArray[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "Iteration: " << many << endl;
	return 0;
}