#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int coef, exp;
	node *next;
};

class Polynomial
{
	node *head;
	char *exp;
	
	void show_value()
	{
		if(head==NULL)
			cout<<"Nothing to show"<<endl;
		else
		{
			cout<<"Equation is: ";
			cout<<head->coef<<"x^"<<head->exp;
			node *p = head->next;
			while(p!= NULL)
			{
				if(p->exp == 0)
				{
					if(p->coef>0)
						cout<<"+"<<p->coef<<endl;
					else
						cout<<p->coef<<endl;
				}
				else
				{
					if(p->coef<0)
						cout<<p->coef<<"x^"<<p->exp;
					else
						cout<<"+"<<p->coef<<"x^"<<p->exp;
				}
				p = p->next;
			}
		}
	}
	
	node* Create_term(int c, int e)
	{
		node *temp_node = new node;
		temp_node->coef = c;
		temp_node->exp = e;
		temp_node->next = NULL;
		return(temp_node);
	}
		
	void Add_expression(int c, int e)
	{
		//cout<<"Present coeffcient: "<<c<<" and Exponent is: "<<e<<endl;
		node *temp_node = Create_term(c, e);
		if(head == NULL)
		{
			head = temp_node;
		}
		else
		{
			node *p = head;
			while(p->next!= NULL)
			{
				if(p->exp<e)
					break;
				p = p->next;
			}
			p->next = temp_node;
		}
	}
	
	public:
		Polynomial(char *temp)
		{
			int i = 0, j = 0;
			head = NULL;
			exp = temp;
			cout<<"1"<<endl;
			/*while(temp[i] != '\0')
			{
				cout<<"2"<<endl;
				if(((temp[i] == '+') || (temp[i] == '-')) && (isdigit(temp[i+1]) == 1) && (temp[i+2] == 'x') && (((temp[i+3] == '+') || (temp[i] == '-'))))
				{
					exp[j] = temp[i];
					exp[j+1] = temp[i+1];
					exp[j+2] = temp[i+2];
					exp[j+3] = '^';
					exp[j+4] = '1';
					j += 5;
					i += 3;
				}
				else
				{
					if(((temp[i] == '+') || (temp[i] == '-')) && (isdigit(temp[i+1]) == 1) && (((temp[i+2] == '+') || (temp[i] == '-'))))
					{
						exp[j] = temp[i];
						exp[j+1] = temp[i+1];
						exp[j+2] = 'x';
						exp[j+3] = '^';
						exp[j+4] = '1';
						j += 5;
						i += 2;
					}
					else
					{
						exp[j] = temp[i];
						exp[j+1] = temp[i+1];
						exp[j+2] = temp[i+2];
						exp[j+3] = temp[i+3];
						exp[j+4] = temp[i+4];
						j += 5;
						i += 5;
					}
				}
			}*/
			i = 0;
			cout<<"3"<<endl;
			while(exp[i+1] != '\0')
			{
				if(exp[i+1] == '\0')
				{
					cout<<"Value of i: "<<i<<" "<<exp[i]<<endl;
					i = i+1;
				}
				else
				{
					if( ((exp[i] == '+') || (exp[i] == '-')) && (isdigit(exp[i+1]) == 1) && (exp[i+2] == 'x') &&(((exp[i+3] == '+') || (exp[i+3] == '-'))) )
					{
						cout<<"Value of i: "<<i<<" "<<exp[i]<<exp[i+1]<<exp[i+2]<<endl;
						i = i+3;
					}
					else
					{
						cout<<"Value of i: "<<i<<" "<<exp[i]<<exp[i+1]<<exp[i+2]<<exp[i+3]<<endl;
						i = i+4;
					}
				}
			}
		}
		
		void Create_polynomial()
		{
			int e, c;
			
		}
		
		void Show_Polynomial()
		{
			show_value();
		}
};

int main()
{
	char temp[] = "3x^2-5x+6";
	Polynomial p1 = Polynomial(temp);
	return 0;
}
