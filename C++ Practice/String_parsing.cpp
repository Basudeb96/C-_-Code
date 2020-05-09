#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int main()
{
	int len;
	char s1[50];
	cout<<"Enter your string: ";
	cin>>s1;
	cout<<"Your string is: ";
	//len = s1.length();
	for(int i = 0; i<50;i++)
	{
		//if((isdigit(s1[i])) && (s1[i+1].compare("x") == 0) && (s1[i+2].compare("^")==0) && (isdigit(s1[i+3)))
		//{
		if(s1[i] != '\0')
			cout<<"coefficient: "<<s1[i]<<endl;
		else
			 break;
			//<<" and exponent is: "<<s1[i+3]<<endl;
		//}
		
	}
	return 0;
}
