/*
If most of the elements of the matrix have value '0', then it is called Sparse Matrix.
Converting such a matrix into sparse matrix helps in saving storage and decreases computation time.
Sparse Matrix only stores non-zero elements with triplets i.e. Row,Column,Values.
*/
//This Code converts a matrix into SparseMatrix.

#include <iostream>
using namespace std;
int main()
{
	int matrix[4][5] = 
	{
	{0,0,3,0,4},
	{0,0,5,7,0},
	{0,0,0,0,0},
	{0,2,6,0,0}
	};
	cout<<"Matrix:"<<endl;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<matrix[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	
	int total = 0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(matrix[i][j] != 0)
			{
				total++;
			}
		}
	}
	
	int sparsematrix[total][3];
	int k=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(matrix[i][j] != 0)
			{
				sparsematrix[k][0] = i;
				sparsematrix[k][1] = j;
				sparsematrix[k][2] = matrix[i][j];
				k++;
			}
		}
	}
	cout<<"------------------------------Sparse Matrix------------------------------"<<endl;
	cout<<"Row\tColumns\tValue"<<endl;
	for(int i=0;i<total;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<sparsematrix[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
