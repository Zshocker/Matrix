#include "pch.h"
#include "Matrix.h"
#include<iostream>
#include"assert.h"
using namespace std;

using namespace Math;
void Matrix::Remplissage(int elem)
{
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			this->Matx[i][j] = elem;
		}
	}
}
Matrix::Matrix(unsigned int numC, unsigned int numL)
{
	assert(numC != 0 && numL != 0);
	this->numC = numC;
	this->numL = numL;
	this->Matx = new int* [numL];
	for (int i = 0; i < numL; i++)this->Matx[i] = new int[numC];
	this->Remplissage(0);
}
Matrix* Matrix::operator+(const Matrix& R) const
{
	assert(this->numC==R.numC&&this->numL==R.numC);
	Matrix *pt=new Matrix(this->numC, this->numL);
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			pt->Matx[i][j] = this->Matx[i][j] + R.Matx[i][j];
		}
	}
	return pt;
}

Matrix* Matrix::operator-(const Matrix& R) const
{
	assert(this->numC == R.numC && this->numL == R.numC);
	Matrix* pt = new Matrix(this->numC, this->numL);
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			pt->Matx[i][j] = this->Matx[i][j] - R.Matx[i][j];
		}
	}
	return pt;
}


Matrix* Matrix::operator*(const Matrix&R) const
{
	assert(this->numC == R.numL);

	Matrix* nM = new Matrix(R.numC, this->numL);
	for (int i = 0; i < nM->numL; i++)
	{
		for (int j = 0; j < nM->numC; j++)
		{
			nM->Matx[i][j]=0;
			for (int k = 0; k <this->numC; k++)
			{
				nM->Matx[i][j] +=this->Matx[i][k]*R.Matx[k][j];
			}
		}
	}
	return nM;
}
Matrix* Matrix::operator*(int elem) const
{
	Matrix* pt = new Matrix(this->numC, this->numL);
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			pt->Matx[i][j] = this->Matx[i][j] * elem;
		}
	}
	return pt;
}

void Matrix::Print() const
{
	cout <<endl<< "{ ";
	for (int i = 0; i < this->numL; i++)
	{
		for (int j = 0; j < this->numC; j++)
		{
			cout <<  this->Matx[i][j];
			if (j != this->numC - 1) cout << ",";
		}
		if(this->numL-1!=i)cout << endl << "  ";
	}
	cout << " }";
}

Matrix::~Matrix()
{
	for (int i = 0; i < this->numL; i++)
	{
		delete[] this->Matx[i];
		this->Matx[i] = NULL;
	}
	delete this->Matx;
	this->Matx = NULL;
}
