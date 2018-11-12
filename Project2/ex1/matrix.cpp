#include "matrix.h"

#include <iostream>

Matrix::Matrix() {
	rows = 3;
	columns = 3;
	mat.resize(rows);
	for (unsigned i = 0; i < mat.size(); i++) {
		mat[i].resize(columns);
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++) {
			mat[i][j] = 1;
		}
	}
}
Matrix::Matrix(int num_rows, int num_col, int initial) {
	rows = num_rows;
	columns = num_col;
	mat.resize(rows);
	for (unsigned i = 0; i < mat.size(); i++) {
		mat[i].resize(columns);
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++) {
			mat[i][j] = initial;
		}
	}
}

void Matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

// Matrix*Vector 
Vector Matrix::operator*(Vector& u) {
	Vector result(mat[0][0] * u.vx() + mat[0][1] * u.vy() +mat[0][2] * u.vz(), mat[1][0] * u.vx() + mat[1][1] * u.vy() +mat[1][2] * u.vz(), mat[2][0] * u.vx() + mat[2][1] * u.vy() +mat[2][2] * u.vz());

	return result;
}
