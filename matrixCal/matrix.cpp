#include "matrix.h"
#include <iostream>

matrix::matrix(int row, int col) {
	rSize = row;
	cSize = col;

	value = new int*[rSize];

	for (int i = 0; i < rSize; i++){
		value[i] = new int[cSize];
	}
	

	for (int i = 0; i < rSize; i++) {
		for (int j = 0; j < cSize; j++) {
			value[i][j] = 0;
		}
	}
}


matrix::~matrix() {

}


void matrix::printMat() {

	for(int i = 0; i < rSize; i++)
		for (int j = 0; j < cSize; j++)
		{
			std::cout << value[i][j] << "   ";
		}
}