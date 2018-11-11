#ifndef MATRIX_H
#define MATRIX_H

class matrix {
private:
	int rSize;
	int cSize;
	int** value;
public:
	matrix(int, int);
	~matrix();

	int getRSize();
	int getCSize();
	int getValue(int, int);

	void printMat();

};


#endif
