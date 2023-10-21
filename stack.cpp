 #include<iostream>
 #include <stdlib.h>
 #define MAXSIZE 100
 using namespace std;
 
 struct stack
 {
 	int stack [MAXSIZE];
 	int top;
 	
 	
 };
 
 void push (struct stack *pu )
 {
 	
 	int item;
 	if (pu->top==MAXSIZE-1)
		{
		cout<<"\n The stack is Full";
		exit(0);
		}
	else
	{
		cout<<"\n Enter the Element to be Inserted= ";
		cin>>item;
		pu->stack [++pu->top]=item;
	}
	
 }
 
 void pop (struct stack *po)
 {
 	
 	int item;
 	if(po->top==-1)
 	{
		cout<<"\n The stack is empty";
		exit(0);
	}
	else
	{
		item=po->stack[po->top--];
		cout<<"\n The Deleted Element is="<<item;	
		
	}
 }
 
 void traverse (struct stack *pt)
 {
 	int i;
 	
 	if(pt->top==-1)
 	{
 		
 		cout<<"\n The stack is empty";
	}
	else
	{
		cout<<"\nThe Elements in the stack is/are...: ";
		for (i=pt->top;i>=0;i--)
		{
		cout<< pt->stack[i];	
		}
	}
 }
 
 
 int main()
 
 {
 	int choice;
 	int check=1;
 	
 	struct stack *ps;
 	
 	ps=(struct stack *) malloc (100* sizeof(struct stack));
 	
 	ps->top=-1;
 	
 	do
 	{
		cout<<"\n 1. PUSH Operation";
		cout<<"\n 2. POP Operation";
		cout<<"\n 3. Traverse Operation";
		cout<<"\n Enter Your Choice= ";
		cin>>choice;
		
		switch(choice)
		{
			
			case 1: 
					push(ps);
					break;
			case 2: 
					pop(ps);
					break;
			case 3:
					traverse(ps);
					break;
			default:
					cout<<"\n You Entered wrong choice";
		}
		
		cout<<"\n\n Press 1 for continue and 2 for Exit the environment= ";
		cin>>check;
	
	}
	
	
	while (check!=2);
 
 	return 0;
 	
 	
 }
