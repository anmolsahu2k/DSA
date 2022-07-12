#include<iostream>
#define MAX 200
using namespace std;
class Stack{
    public :
    int top=-1;
    int arr[MAX];

    void push(int num)
    {
        if(top==MAX-1)
            cout<<"Stack overflow";
        else
            arr[++top]=num;
    }

    void pop()
    {
        if(top==-1)
            cout<<"Stack underflow";
        else
            top--;
    }
    int peek()
    {
        if(top==-1)
            cout<<"Stack empty";
        else
            return arr[top];
        return 0;
    }
    bool isEmpty()
    {
        return top<0;
    }
};
int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    cout<<s.peek();
    cout<<s.isEmpty();
    return 0;
}