#ifndef matrix_h
#define matrix_h

#include <vector>
#include "../common/vector.h"
using namespace std;

class Matrix {
	int rows, columns;
	
public:
	std::vector<std::vector<float> > mat;
	Matrix();
	Matrix (int, int, int);
	void print();
	Vector operator*(Vector& u);

};

#endif /* matrix_h */
