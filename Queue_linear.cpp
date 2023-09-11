//PROGRAM TO IMPLEMENT QUEUE USING ARRAYS
#include<iostream>
#include <stdlib.h>
using namespace std;
#define MAX 50

int queue_arr[MAX];
int rear = -1;
int front =-1;
int isEmpty();
//This function will insert an element to the queue
void Enqueue ()
{
 int added_item;
 if (rear==MAX-1)
 {
 cout<<"\nQueue Overflow\n";
 return;
 }
 else
 {
 if (isEmpty() == 1) /*If queue is initially empty */
 {
 cout<<"Queue is Empty, Your are going to create a queue\n";
 front = 0;
 }
 cout<<"\nInput the element for adding in queue:";
 cin>>added_item;
 rear=rear+1;
//Inserting the element
 queue_arr[rear] = added_item ;
 }
}/*End of insert()*/
//This function will delete (or pop) an element from the queue
void Dequeue()
{
 if (isEmpty() == 1)
 {
 cout <<"\nQueue Underflow or Queue is Empty\n";
 return;
 }
 else
 {
 //deleteing the element
 cout <<"\nElement deleted from queue is :"<<queue_arr[front];
 front=front+1;
 }
}/*End of del()*/
//Displaying all the elements of the queue
void Traverse()
{
 int i;
 //Checking whether the queue is empty or not
 if (isEmpty() ==1)
 {
 cout <<"\nQueue is empty\n";
 return;
 }
 else
 {
 cout<<"\nFront is"<<front<<" and Queue is :\n";
 for(i=front;i<= rear;i++)
 cout<<queue_arr[i];
 cout<<"\n";
 }
}/*End of display() */
/*Checks whether the Queue is Empty or not */
int isEmpty()
{
 if (front > rear) // if(front == -1 && rear == -1)
 {
 return 1; // True
 }
 else 
 return 0; //False
 
}
/*End if isEmpty() */
int main()
{
 int choice;
 while (1)
{
 //system("cls");
 //Menu options
 cout<<"\n1.Enqueue\n";
 cout<<"2.Dequeue\n";
 cout<<"3.Traverse\n";
 cout<<"4.Size\n";
 cout<<"5.Quit";
 cout<<"\nEnter your choice:";
 cin>>choice;
 switch(choice)
 {
 case 1 :
 Enqueue();
 break;
 case 2:
 Dequeue();
 break;
 case 3:
 Traverse();
 break;
 case 4:
 cout<<"The size of the queue is:\n"<<rear-front+1;
 break;
 case 5:
 exit(1);
 default:
 cout<<"\n Wrong choice\n";
 
 }/*End of switch*/
 }/*End of while*/
 return 0;
 //return NAN;
}/*End of main()*/
