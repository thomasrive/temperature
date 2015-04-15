#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int initArraySizeX, initArraySizeY;
    double initTopEdge, initBottomEdge, initLeftEdge, initRightEdge;
    double epsilon;
    int i, j;
    int iteration = 0;
    cout << "Please enter the size of the array: \n";
    cout << "Array Rows: " ;
    cin >> initArraySizeX;
    cout << "Array Columns: " ;
    cin >> initArraySizeY;
    while(((initArraySizeX<0) || (initArraySizeX>=26)) || ((initArraySizeY<0) || initArraySizeY>=30)){
        cout << "Array cannot be bigger than 26 by 30, nor less than 1. Renter values please" << endl;
        cout << "Array Rows: " << endl;
        cin >> initArraySizeX;
        cout << "Array Columns: " << endl;
        cin >> initArraySizeY;
    }
    double Array[initArraySizeX][initArraySizeY];
    cout << "What is the temperature of the top edge: ";
    cin >> initTopEdge;
    while((initTopEdge<0) || (initTopEdge>300)){
        cout << "Temperature cannot be greater than 300 or less than 0" << endl;
        cout << "What is the temperature of the top edge: ";
        cin >> initTopEdge;
    }
    cout << "What is the temperature of the bottom edge: ";
    cin >> initBottomEdge;
    while((initBottomEdge<0) || (initBottomEdge>300)){
        cout << "Temperature cannot be greater than 300 or less than 0" << endl;
        cout << "What is the temperature of the bottom edge: ";
        cin >> initBottomEdge;
    }
    cout << "What is the temperature of the left edge: ";
    cin >> initLeftEdge;
    while((initLeftEdge<0) || (initLeftEdge>300)){
        cout << "Temperature cannot be greater than 300 or less than 0" << endl;
        cout << "What is the temperature of the left edge: ";
        cin >> initLeftEdge;
    }
    cout << "What is the temperature of the right edge: ";
    cin >> initRightEdge;
    while((initRightEdge<0) || (initRightEdge>300)){
        cout << "Temperature cannot be greater than 300 or less than 0" << endl;
        cout << "What is the temperature of the right edge: ";
        cin >> initRightEdge;
    }
    cout << "What is the value of epsilon: ";
    cin >> epsilon;
    
    //Setting Temperature of edges
    
    for(i=1;i<initArraySizeX-1;i++){
        Array[0][i] = initTopEdge;
    }
    
    for(i=1;i<initArraySizeX-1;i++){
        Array[initArraySizeY-1][i] = initBottomEdge;
    }
    
    for(i=1;i<initArraySizeY-1;i++){
        Array[i][0] = initLeftEdge;
    }
    
    for(i=1;i<initArraySizeY-1;i++){
        Array[i][initArraySizeX-1] = initRightEdge;
    }
    
    //Calculating Corners
    //TopLeft
    
    Array[0][0] = (((Array[1][0]) + Array[0][1])/2);
    
    //TopRight
    
    Array[0][initArraySizeX-1] = (((Array[0][initArraySizeX-2]) + Array[1][initArraySizeX-1])/2);
    
    //BottomLeft
    
    Array[initArraySizeY-1][0] = (((Array[initArraySizeY-2][0]) + Array[initArraySizeY-1][1])/2);
    
    //Bottom Right
    
    Array[initArraySizeX-1][initArraySizeY-1] = (((Array[initArraySizeY-1][initArraySizeX-2]) + Array[initArraySizeY-2][initArraySizeX-1])/2);
    
    //Iteration Run
    /*
    for(i=1;i<initArraySizeY-1;i++){
        for(j=1;j<initArraySizeX-1;j++){
            Array[i][j] = 
        }
    }
    */
    
    //OutputArrayPrototype
    cout << endl << "Array: " << endl;
    for (i = 0; i < initArraySizeX; i++){
        for(j = 0; j < initArraySizeY; j++){
            cout << fixed << setw(5) << showpoint << setprecision(2) << Array[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}