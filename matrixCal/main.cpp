#include "matrix.h"
#include <iostream>

void testGS(matrix);
void testAS(matrix, matrix);


int main() {
	
	std::cout << "Constructors" << std::endl;
	matrix x(3, 3);
	matrix y(3, 3);


	//testGS(x);

	testAS(x, y);

	system("pause");
	return 0;
}

//test input for get set
void testGS(matrix a) {
	int r = 0;
	int c = 0;
	int n = 5;

	//Getters
	std::cout << "Number of rows: " << a.getRSize() << std::endl;
	std::cout << "Number of cols: " << a.getCSize() << std::endl;

	std::cout << "Print Matrix before alter;" << std::endl;
	a.printMat();

	std::cout << "\nThe value in row " << r << " and col " << c <<": ";
	std::cout << a.getValue(r, c);

	//Setters
	std::cout << "\nSetting row " << r << " and col " << c << " to: " << n;


	std::cout << "\nPrint Matrix after alter;" << std::endl;
	a.printMat();
}

//test input for add subract operators
void testAS(matrix a, matrix b){
	matrix temp(a.getRSize(), a.getCSize());

	//print all 3 matrices
	std::cout << "Before Addition" << std::endl;
	std::cout << "A Matrix" << std::endl;
	a.printMat();
	std::cout << "B Matrix" << std::endl;
	b.printMat();
	std::cout << "Temp Matrix" << std::endl;
	temp.printMat();

	//Addition
	temp = a + b;

	
	std::cout << "After Addition of a and b" << std::endl;
	std::cout << "Temp Matrix" << std::endl;
	temp.printMat();

	//Subraction
	temp = a - b;

	std::cout << "After Subtraction of a and b" << std::endl;
	std::cout << "Temp Matrix" << std::endl;
	temp.printMat();


}
