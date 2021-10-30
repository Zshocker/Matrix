#pragma once
class Matrix
{
	int numL;
	int numC;
	int** Matx;
public:
	Matrix(unsigned int numC, unsigned int numL);
	Matrix(const Matrix&)=delete;
	void Remplissage(int elem);
	Matrix& operator=(const Matrix&)const=delete;
	Matrix* operator+(const Matrix&)const;
	Matrix* operator-(const Matrix&)const;
	Matrix* operator*(const Matrix&)const;
	Matrix* operator*(int elem)const;
	void Print()const;
	~Matrix();
};

