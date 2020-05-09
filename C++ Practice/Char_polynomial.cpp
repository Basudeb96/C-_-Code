#include<iostream>
using namespace std;

struct node
{
	int coef, exp;
	node *prev, *next;
};

class Polynomial
{
	node *e1, *e2, *e3;
	
	node* Create_term(int c, int e)
	{
		node *temp = new node;
		temp->coef = c;
		temp->exp = e;
		temp->prev = temp->next = NULL;
		return(temp);
	}
	
	void Add_Expression(int eq, int c, int e)
	{
		node *temp = Create_term(c, e);
		node *head =  NULL;
		if(eq == 1)
		{
			head = e1;
		}
		else
		{
			if(eq == 2)
			{
				head = e2;
			}
			else
			{
				head = e3;
			}
		}
		
		if(head == NULL)
			head = temp;
		else
		{
			node *p = head;
			while(p->next != NULL)
			{
				if(p->exp>temp->exp)
					p = p->next;
				else
					break;
			}
			
			if(p == head)
			{
				if(p->exp<temp->exp)
				{
					temp->next = p;
					p->prev = temp;
					head = temp;
				}
				else
				{
					if(p->next == NULL)
					{
						p->next = temp;
						temp->prev = p;
					}
				}
			}
			else
			{
				if((p->exp>temp->exp) && (p->next == NULL))
				{
					p->next = temp;
					temp->prev = p;
				}
				else
				{
					node *q = p->prev;
					temp->prev = q;
					temp->next = p;
					p->prev =  temp;
					q->next = temp;
				}
			}
		}
		if(eq == 1)
			e1 = head;
		else
		{
			if(eq == 2)
				e2 = head;
			else
				e3 = head;
		}
	}
	
	void Show_expression(int eq)
	{
		node *head = NULL;
		if(eq == 1)
			head = e1;
		else
		{
			if(eq == 2)
				head = e2;
			else
				head = e3;
		}
		
		if(head == NULL)
		{
			cout<<"\n\t\t\tNothing to display\n";
		}
		else
		{
			node *p = head;
			if(eq == 1)
				cout<<"Your First Polynomial is: ";
			if(eq == 2)
				cout<<"Your Second Polynomial is: ";
			if(eq == 3)
				cout<<"Your Sum of two Polynomials is: ";
			while(p != NULL)
			{
				cout<<p->coef<<"x^"<<p->exp<<"+";
				p= p->next;
			}
			cout<<endl;
		}
	}
	
	void Addition()
	{
		node *p = e1, *q = e2;
		while((p!=NULL) && (q!= NULL))
		{
			if(p->exp>q->exp)
			{
				Add_Expression(3, p->coef, p->exp);
				p = p->next;
			}
			else
			{
				if(p->exp<q->exp)
				{
					Add_Expression(3, q->coef, q->exp);
					q = q->next;
				}
				else
				{
					Add_Expression(3, (q->coef+p->coef), q->exp);
					p = p->next;
					q = q->next;
				}
			}
		}
		
		if(p!=NULL)
		{
			while(p!=NULL)
			{
				Add_Expression(3, p->coef, p->exp);
				p = p->next;
			}
		}
		
		if(q!=NULL)
		{
			while(q!=NULL)
			{
				Add_Expression(3, q->coef, q->exp);
				q = q->next;
			}
		}
	}
	
	public:
		Polynomial()
		{
			e1 = NULL;
			e2 = NULL;
			e3 = NULL;
		}
		
		void Create_expression(int eq, int c, int e)
		{
			Add_Expression(eq, c, e);
		}
		
		void Display(int eq)
		{
			Show_expression(eq);
		}
		
		void Get_Sum()
		{
			Addition();
		}
};

int main()
{
	Polynomial p1 = Polynomial();
	int c, e, ch1, ch2;
	char poly[100];
	bool flag1= true, flag2;
	
	while(flag1)
	{
		cout<<"\t\t\t\tMain Menu\n";
		cout<<"\t\t**********************\n";
		cout<<"\t\t\t1. Create Expression\n\t\t\t2. Display Expression\n\t\t\t3. Addition\n\t\t\t4. Exit\n";
		cout<<"\t\t**********************\n";
		cout<<"Enter Your choice: ";
		cin>>ch1;
		switch(ch1)
		{
			case 1:
				flag2 = true;
				while(flag2)
				{
					cout<<"\t\t\t\tCreation Menu\n";
					cout<<"\t\t**********************\n";
					cout<<"\t\t\t1. First Polynomial\n\t\t\t2. Second Polynomial\n\t\t\t3. Exit\n";
					cout<<"\t\t**********************\n";
					cout<<"Enter Your choice: ";
					cin>>ch2;
					switch(ch2)
					{
						case 1:
							cout<<"Enter the coefficient and exponent:";
							cin>>c>>e;
							p1.Create_expression(1, c, e);
							break;
						case 2:
							cout<<"Enter the coefficient and exponent:";
							cin>>c>>e;
							p1.Create_expression(2, c, e);
							break;
						case 3:
							cout<<"Returing to the Main Menu"<<endl;
							flag2 = false;
							break;
						default:
							cout<<"Enter a Wrong choice"<<endl;
							break;
					}
				}
				break;
			case 2:
				flag2 =  true;
				while(flag2)
				{
					cout<<"\n\t\t\t\tDisplay Menu\n";
					cout<<"\t\t**********************\n";
					cout<<"\t\t\t1. First Polynomial\n\t\t\t2. Second Polynomial\n\t\t\t3. Sum\n\t\t\t4. Exit\n";
					cout<<"\t\t**********************\n";
					cout<<"Enter Your choice: ";
					cin>>ch2;
					switch(ch2)
					{
						case 1:
							p1.Display(1);
							break;
						case 2:
							p1.Display(2);
							break;
						case 3:
							p1.Display(3);
							break;
						case 4:
							cout<<"Returing to the Main Menu"<<endl;
							flag2 = false;
							break;
						default:
							cout<<"Enter a Wrong choice"<<endl;
							break;
					}
				}
				break;
			case 3:
				p1.Get_Sum();
				//p1.Display(3);
				break;
			case 4:
				cout<<"Exiting from the Program\n";
				flag1 = false;
				break;
			default:
				cout<<"Enter a Wrong Option\n";
				break;
		}
	}
	return 0;
}
