#include<iostream>
using namespace std;
class CircularQueue {

	int queue[30], front, rear, n;
	public:
		CircularQueue()
		{
			n=5;
			front=-1;
			rear=-1;
		}
	void enqueue(int data)
	{
		if(front==-1&&rear==-1)
		{
			front=0 ;
			rear= 0;
			queue[rear]=data;
		}
		else if((rear+1)%n==front)
		{
			cout << "Queue is full" ;
		}
		else
		{
			rear=(rear+1)%n;
			queue[rear] = data;
		}
	}
	void dequeue()
	{
		if(front==-1)
		{
			cout << "UnderFlow" ;
		}
		else if(front==rear)
		{
			front=-1;
			rear=-1;
			cout << "Queue is empty";
		}
		else
		{
			cout << "Deleted Element:" << queue[front];
			front=(front+1)%n;
		}
	}
	void display()
	{
		int i=front;
		while(i!=rear+1)
		{
			cout << queue[i];
			i=(i+1)%n;
		}
	}
};	
	int main ()
	{
		int ch, data;
		CircularQueue q;
		do
		{
			cout << "\n1. Enqueue ";
			cout << "\n2. Dequeue ";
			cout << "\n3. Display ";
			cout << "\n4. Exit";
			cout << "\nEnter your choice: ";
			cin>>ch;
			switch(ch)
			{
			case 1: cout << "\nEnter Data: ";
			     cin>>data;
			     q.enqueue(data);
			     break;
			case 2: 
			     q.dequeue();
			     break;
			case 3: cout << "\nQueue:";
			     q.display();
			     break;
			
			}
		
		}
		while(ch!=4);
		return 0;
		
	}