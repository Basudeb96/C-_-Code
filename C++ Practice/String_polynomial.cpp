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
		cout<<"Present coeffcient: "<<c<<" and Exponent is: "<<e<<endl;
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
			while(temp[i] != '\0')
			{
				cout<<temp[i]<<endl;
				i++;
			}
		}
		
		void Create_polynomial()
		{
			int i, c, e; 
			if((isdigit(exp[0])==1) && ((exp[1] == 'x') || (exp[1] == 'X')) && (exp[2] == '^') && (isdigit(exp[3])==1))
			{
				c = (int)(exp[0]) - '0';
				e = (int)(exp[3]) - '0';
				Add_expression(c, e);
				i = 4;
			}
			else
			{
				if((exp[0] == '-') && (isdigit(exp[1])==1) && ((exp[2] == 'x') || (exp[2] == 'X')) && (exp[3] == '^') && (isdigit(exp[4])==1))
				{
					c = (int)exp[0] - '0';
					e = (int)exp[4] - '0';
					Add_expression(c, e);
					i = 5;
				}
			}
			cout<<"Present value of i: "<<i<<"\n";
			while( ((exp[i+2] != '\0') && (exp[i+3] != '\0') && (exp[i+4]!='\0') ))
			{
				if((exp[i] == '+') && (isdigit(exp[i+1])==1) && ((exp[i+2] == 'x') || (exp[i+2] == 'X')) && (exp[i+3] == '^') && (isdigit(exp[i+4])==1))
				{
					cout<<"1";
					c = (int)exp[i+0] - '0';
					e = (int)exp[i+4] - '0';
					Add_expression(c, e);
				}
				else
				{
					if((exp[i] == '-') && (isdigit(exp[i+1])==1) && ((exp[i+2] == 'x') || (exp[i+2] == 'X')) && (exp[i+3] == '^') && (isdigit(exp[i+4])==1))
					{
						cout<<"2";
						c = (int)exp[i+0] - '0';
						e = (int)exp[i+4] - '0';
						Add_expression(c, e);
					}
				}
				i += 4;
				cout<<"Present value of i: "<<i<<"\n";
			}
		}
		
		void Show_Polynomial()
		{
			show_value();
		}
};

int main()
{
	char temp[] = "3x^12+2x^8-3x^3";
	Polynomial p1 = Polynomial(temp);
	p1.Create_polynomial();
	p1.Show_Polynomial();
	return 0;
}
