#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class My_Graph
{
	int n;
	char *ver, **mat;
	public:
		My_Graph(int temp)
		{
			int i, j, tempj;
			n =  temp;
			ver = (char *)malloc(n*sizeof(char));
			cout<<"Enter the name of the vertices:";
			for(int i = 0;i<n;i++)
				cin>>ver[i];
			
			mat = (char **)malloc((n+1)*sizeof(char *));
			for(i = 0; i<n+1;i++)
			{
				mat[i] = (char *)malloc((n+1)*sizeof(char));
			}
			mat[0][0] = 'O';
			tempj = 0;
			for(i = 1;i<n+1;i++)
			{
				for(j = 0;j<n+1;j++)
				{
					if(j == 0)
					{
						mat[i][0] = ver[tempj];
						mat[0][i] = ver[tempj];
						tempj++;
					}
					else
					{
						mat[i][j] = '0';
					}
				}
			} 
		}
		
		void Create_adjacency_matrix()
		{
			int e, i, j, c, index1, index2;
			bool flag1 = false, flag2 = false;
			char u, v;
			cout<<"\nEnter the total number of edges:";
			cin>>e;
			
			cout<<"\nEnter the endpoints of each edge:";
			for(i = 0; i<e;i++)
			{
				cin>>u>>v;
				flag1 = false;
				flag2 = false;
				for(c=0; c<n;c++)
				{
					if(ver[c] == u)
					{
						index1 = c+1;
						flag1 = true;
					}
					if(ver[c] == v)
					{
						flag2 = true;
						index2 = c+1;
					}
				}
				
				if(flag1 && flag2)
				{
					mat[index1][index2] = '1';
					mat[index2][index1] = '1';
				}
				else
				{
					cout<<"\t\t****************************************************\n";
					cout<<"\t\t\tTwo vertices You entered are Wrong"<<endl;
					cout<<"\t\t****************************************************\n";
				}
			}
		}
		
		void Show_adjacency_matrix()
		{
			cout<<endl;
			int i, j;
			for(i = 0; i<n+1;i++)
			{
				for(j=0;j<n+1;j++)
				{
					cout<<mat[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
};
