#include <vector>
#include "math.h"

using namespace std;

typedef vector<float> Vector;
typedef vector<Vector> Matrix;

void zeroes(Vector &v, int n){

	for(int i=0;i<n;i++){
		v.push_back(0.0);
	}
}

void zeroes(Matrix &M, int n){
	for(int i=0;i<n;i++){
		Vector row(n,0.0);//Crea vector con caracteristicas que le pasamos
		M.push_back(row);
	}
}

//Copy Matrix
void copyMatrix(Matrix A, Matrix &copy){

    zeroes(copy,A.size());

    for(int i=0;i<A.size();i++){
        for(int j=0;j<A.at(0).size();j++){
            copy.at(i).at(j) = A.at(i).at(j);
		}
	}
}

//ProductMatrixVector

void productMatrixVector(Matrix A, Vector v, Vector &R){

    for(int f=0;f<A.size();f++){
        float cell = 0.0;
        for(int c=0;c<v.size();c++){
            cell += A.at(f).at(c)*v.at(c);
        }
        R.at(f) += cell;
    }
}

//productRealMatrix
void productRealMatrix(float real,Matrix M,Matrix &R){

    zeroes(R,M.size());

    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            R.at(i).at(j) = real*M.at(i).at(j);
		}
	}
}

// Funvion GetMinor
void getMinor(Matrix &M,int i, int j){

    M.erase(M.begin()+i);

    for(int i=0;i<M.size();i++){
        M.at(i).erase(M.at(i).begin()+j);
	}
}

//Determinante
float determinant(Matrix M){

    if(M.size() == 1) return M.at(0).at(0);
    else{

        float det=0.0;

        for(int i=0;i<M.at(0).size();i++){

            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,0,i);

            det += pow(-1,i)*M.at(0).at(i)*determinant(minor);
        }
        return det;
    }
}

//Cofactores
void cofactors(Matrix M, Matrix &Cof){

    zeroes(Cof,M.size());

    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){

            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,i,j);

            Cof.at(i).at(j) = pow(-1,i+j)*determinant(minor);
        }
    }
}

// transpuesta

void transpose(Matrix M, Matrix &T){

    zeroes(T,M.size());

    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            T.at(j).at(i) = M.at(i).at(j);
		}
	}
}

//divide una Matrix entre un escalar
void divideRealMatrix(float real,Matrix M,Matrix &R){

    zeroes(R,M.size());

    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            R.at(i).at(j) = M.at(i).at(j)/real;
		}
	}
}

//Inversa
void inverseMatrix(Matrix M, Matrix &I){

	Matrix auxCof,aux2;
	cofactors(M,auxCof);
	transpose(auxCof,aux2);
	divideRealMatrix(determinant(M),aux2,I);
	
}
