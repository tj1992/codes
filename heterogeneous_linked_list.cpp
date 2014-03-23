#include<iostream>
#include<cstdlib>
#include<cctype>
#include<cstdio>

using namespace std;

enum Type{CHAR,INT,DOUBLE};

struct node
{
	void *p;
	enum Type type;
	node *next;

};

node *create_char(char a)
{
	node *pt;
	//pt->p = (char*)(pt->p);
	pt =(node*)malloc(sizeof(node));
	pt->p=malloc(sizeof(char));
	*(char*)pt->p =a;
	return pt;
}

node *create_int(int a)
{
	node *pt;
	//pt->p = (char*)(pt->p);
	pt = (node*)malloc(sizeof(node));
	pt->p=malloc(sizeof(int));
	*(int *)pt->p=a;
	return pt;
}

node *create_double(double a)
{
	node *pt;
	//pt->p = (char*)(pt->p);
	pt = (node*)malloc(sizeof(node));
	pt->p=malloc(sizeof(double));
	*(double *)pt->p=a;
	return pt;
}
	

 node * create(node *head,Type typ)
{
	
	node *a;
	char x;int y;double z;

	switch(toupper(typ))
	{
		case CHAR:	cin>>x;
				 a = create_char(x);
				a->type = CHAR;
				break;
		
		case INT :	
				cin>>y;
				a =create_int(y);
				a->type = INT;
				break;
		
		case DOUBLE:
				cin>>z;
				a = create_double(z);
				a->type = DOUBLE;
				break;

		
	}

//	cout<<(char*)a->p<<'\n';
	if(head==NULL)
		{
			head = a;
			head->next = NULL;
			return head;
		}

	else
	{
			a->next = head;
			head = a;
			 head->next =NULL;
			
		return head 	;
	}

}

void print_list (node* front) {

node* temp = NULL;int i =0;
for (temp = front;temp!=NULL; temp = temp->next)
 {
	switch (temp->type) {
	case INT:
	printf ("%d ", *(int*)temp->p);
	break;
	case CHAR:
	printf ("%c ", *(char*)temp->p);
	break;
	case DOUBLE:
	printf ("%g ", *(double*)temp->p);
	break;
	}

putchar ('\n');
}
putchar ('\n');
}
	

int main()
{

	node *p ;
	p = create(p,CHAR);
	p->next = create(p,INT);
	p->next->next = create(p,DOUBLE);
	p->next->next->next = create(p,INT);
	print_list(p);
}
