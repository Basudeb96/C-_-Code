#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int coef, exp;
	node *prev, *next;
};

class Polynomial
{
	node *head;
	
	public:
		Polynomial()
		{
			head = NULL;
		}
		
		node* Create_term(int c, int e)
		{
			node *temp_node = new node;
			temp_node->coef = c;
			temp_node->exp = e;
			temp_node->prev = NULL;
			temp_node->next = NULL;
			return(temp_node);
		}
		
		void Add_expression(int c, int e)
		{
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
};

int main()
{
	Polynomial p1 = Polynomial();
	p1.Add_expression(6, 3);
	p1.Add_expression(5, 2);
	p1.Add_expression(10, 0);
	p1.show_value();
	return 0;
}
