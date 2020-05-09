#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int i = 0, temp;
	char pol[] = "35x^2+5x-36";
	while(pol[i]!= '\0')
	{
		if(isdigit(pol[i])==1)
		{
			temp = atoi(pol+i);
			cout<<"temp: "<<temp<<endl;
		}
		i++;
		cout<<"i: "<<i<<endl;
	}
	return 0;
} 
