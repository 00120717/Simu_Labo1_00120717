#include <iostream>
#include "math_tools.h"
#include "display_tools.h"
#include "stdlib.h"

int main(void){

	Vector 	zeroes_vector;
	Matrix matrix_a,invertedMatrix;
	float det = 0.0;
	zeroes(matrix_a,3);

	cout << "Matriz a invertir"<<"\n";
	matrix_a.at(0).at(0)=2;matrix_a.at(0).at(1)=2;matrix_a.at(0).at(2)=3;
	matrix_a.at(1).at(0)=4;matrix_a.at(1).at(1)=5;matrix_a.at(1).at(2)=6;
	matrix_a.at(2).at(0)=7;matrix_a.at(2).at(1)=8;matrix_a.at(2).at(2)=9;


	showMatrix(matrix_a);
	det = determinant(matrix_a);
	if(det == 0){
		return EXIT_FAILURE;
	}
	cout << "Matriz Invertida: "<<"\n";

	inverseMatrix(matrix_a,invertedMatrix);

	showMatrix(invertedMatrix);

	return 0;

}
