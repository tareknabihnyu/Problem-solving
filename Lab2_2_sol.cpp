//============================================================================
// Name         : lab2_2
// Author       : Tarek Nabih
// Version      : 
// Date Created : 
// Date Modified: 
// Description  : A C++ Program that add, subtracts and multiplies dynamially
//                created matrices
// Copyright © 2021. All rights reserved.
//============================================================================
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

//function declaration
int** add(int** matrix1, int** matrix2, int rows, int cols);
int** subtract(int** matrix1, int** matrix2, int rows, int cols);
int** multiply(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2);
void fill(int** matrix, int rows, int cols);
void display(int** matrix, int rows, int cols);
void cleanup(int** matrix, int rows);
int main()
{
	int **matrix1=NULL;
	int **matrix2=NULL;
	int rows1, cols1, rows2, cols2;
	int **ans1=NULL, **ans2=NULL, **ans3=NULL;

	cout<<"Enter the number of rows for first Matrix :";
	cin>>rows1;
	cout<<"Enter the number of columns for first Matrix :";
	cin>>cols1;
	cout<<"Enter the number of rows for second Matrix :";
	cin>>rows2;
	cout<<"Enter the number of rows for second Matrix :";
	cin>>cols2;

	// Create dynamic 2D arrays
	matrix1 = new int*[rows1];
	for(int i=0; i<rows1; i++)
		matrix1[i] = new int[cols1];
	matrix2 = new int*[rows2];
	for(int i=0; i<rows2; i++)
		matrix2[i] = new int[cols2];

	srand(time(NULL));				//Pass System time to to srand function to create different random numbers everytime the program starts
	fill(matrix1,rows1,cols1);		//fill both matrices with random values (int the range of 0-20)
	fill(matrix2,rows2,cols2);
	cout<<"Matrix1 :"<<endl;
	display(matrix1, rows1, cols1);
	cout<<"Matrix2 :"<<endl;
	display(matrix2, rows2, cols2);
	
	if(rows1 == rows2 and cols1 == cols2)		//Pefrom addition only if both matrices have same dimensions
	{
		ans1 = add(matrix1, matrix2, rows1, cols1);
		cout<<"Matrix1 + Matrix2 :"<<endl;
		display(ans1,rows1, cols1);

		ans2 = subtract(matrix1, matrix2, rows1, cols1);
		cout<<"Matrix1 - Matrix2 :"<<endl;
		display(ans2,rows1, cols1);
	}

	if(cols1 == rows2)							//Perform mutliplicaiton if colums of first matrix are rows to the columns of second matrix
	{
		ans3 = multiply(matrix1,matrix2,rows1, cols1, rows2, cols2);
		cout<<"Matrix1 * Matrix2 :"<<endl;
		display(ans3,rows1,cols2);
	}

	//Perform necessary cleanup (delete dynamically created memory)
	cleanup(matrix1,rows1);
	cleanup(matrix2,rows2);
	cleanup(ans1,rows1);
	cleanup(ans2,rows2);
	cleanup(ans3,rows1);

	return 0;
}
//===============================================================
// add two matrices and return the result back to calling program
int** add(int** matrix1, int** matrix2, int rows, int cols)
{
  int ** matri = NULL;
	matri = new int*[rows];
	for(int i=0; i<rows; i++)
		matri[i] = new int[cols];
  
  
  for(int i = 0; i < rows; i++){
    for(int z = 0; z < cols; z++){
      matri[i][z] = matrix1[i][z] + matrix2[i][z];
    }
  }
  
  return matri;
	
}
//===============================================================
// subtract two matrices (matrix1-matrix2) and return result
int** subtract(int** matrix1, int** matrix2, int rows, int cols)
{
	
  int ** matri = NULL;
	matri = new int*[rows];
	for(int i=0; i<rows; i++)
		matri[i] = new int[cols];
  
  
  for(int i = 0; i < rows; i++){
    for(int z = 0; z < cols; z++){
      matri[i][z] = matrix1[i][z] - matrix2[i][z];
    }
  }
  
  return matri;
}
//==============================================================
// multiply two matrices and retun the result
int** multiply(int** matrix1, int** matrix2, int rows1, int cols1, int rows2,int cols2)
{
  int ** matri = NULL; //int fin,sin;
  //if(rows1 > cols1){fin = rows1; sin = cols1;}else{fin = cols1; sin = rows1;}
	matri = new int*[rows1];
	for(int i=0; i<rows1; i++)
		matri[i] = new int[cols2];
  



	for(int i = 0; i < rows1; i++){
        for(int z = 0; z < cols2; z++){
            int newn(0);
            for(int ii = 0 ; ii < cols1; ii++){
            newn += matrix1[i][ii] * matrix2[ii][z]; 
            }
            matri[i][z] = newn;
        }
  }


  return matri;
}
//===============================================================
// fill the matrix with random values in the range of 0 to 20
void fill(int** matrix, int rows, int cols)
{
	for(int i = 0; i < rows; i++){
    for(int z = 0; z < cols; z++){
      matrix[i][z] = rand() % 21;
    }
  }
}
//===============================================================
// display the matrix in two dimension form
void display(int** matrix, int rows, int cols)
{
	for(int i = 0; i < rows; i++){
    for(int z = 0; z < cols; z++){
      cout << setw(4) << matrix[i][z] << "  "; 
    }
    cout << endl;
  }
}
//==============================================================
// delete the memory dynaicall reserved for matrix 
void cleanup(int** matrix, int rows)
{
	for(int i = 0; i < rows; i++){
    delete [] matrix[i];
  }

  delete [] matrix;
}


