#include<iostream>
using namespace std;

class Queue{
    public:
    int front=-1,rear=-1;
    int N=5;
    int arr[5];
    void enQueue(int x)
    {
        if((rear+1)%N==front)
        {
            cout<<"Queue Full";
            return;
        }
        if(front==-1)
            front=0,rear=0;
        else
            rear=(rear+1)%N;
        arr[rear]=x;
    }
    int deQueue()
    {
        if(front==-1)
        {
            cout<<"Queue Empty";
            return -1;
        }
        int x=arr[front];
        if(front==rear)
            front=-1,rear=-1;
        else
            front=(front+1)%N;
        return x;
    }
    void displayQueue()
	{
		// Finding number of elements in queue  
		int count = (rear+N-front)%N + 1;
		cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % N; // Index of element while traversing circularly from front
			cout<<arr[index]<<" ";
		}
		cout<<"\n\n";
	}
};
int main()
{
    Queue q;
 
    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);
 
    // Display elements present in Circular Queue
    q.displayQueue();
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());
 
    q.displayQueue();
 
    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);
 
    q.displayQueue();
 
    q.enQueue(20);
    return 0;
}