#include<iostream>
#include<cmath>
using namespace std;

int ** find_cofactor()
{
	int **sub_mat;
	
}

int determinent(int **mat, int size)
{
	int **sub_mat, temp_det = 0, i, j, k, subi, subj, row, col;
	int temp_size =size-2;
	cout<<"temp_size: "<<temp_size<<endl;mas
	
	if(size == 2)
	{
		cout<<"1"<<endl;
		return((mat[0][0]*mat[1][1]) - (mat[0][1]*mat[1][0]));
	}
	else
	{
		cout<<"2"<<endl;
		sub_mat =(int **)malloc(temp_size*sizeof(int *));
		for(i=0;i<size;i++)
			sub_mat[i] = (int *)malloc(temp_size*sizeof(int));
		for(k=0;k<size;k++)
		{
			subi = 0;
			for(i=1;i<size;i++)
			{
				subj = 0;
				for(j=0; j<size;j++)
				{
					if(j!=k)
					{
						sub_mat[subi][subj] = mat[i][j];
						//cout<<"sub_mat["<<subi<<"]["<<subj<<"]:
						subj++;
					}
				}
				subi++;
			}
			cout<<"Minors of "<<mat[0][k]<<" is:"<<endl;
			for(row = 0; row<size;row++)
			{
				for(col = 0;col<size;col++)
					cout<<sub_mat[row][col]<<"\t";
				cout<<"\n";
			}
			cout<<"Temporary Determinent: "<<temp_det<<endl;
			temp_det = temp_det + pow(-1, k)*mat[0][k]*determinent(sub_mat, size-1);
		}
	}
	return temp_det;
}

int main()
{
	int **a, size, i, j, det;
	cout<<"Enter the size of the Matrix: ";
	cin>>size;
	
	a =(int **)malloc(size*sizeof(int *));
	for(i=0;i<size;i++)
		a[i] = (int *)malloc(size*sizeof(int));
	cout<<"Enter the elements of the Matrix:"<<endl;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			cin>>a[i][j];
	}
	
	//det = determinent(a, size);
	cout<<"Determinent of the matrix: "<<determinent(a, size)<<endl;
	return 0;
}
