#include<iostream>
#include<cstddef>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* newNode(int x)
{
    Node* node=new Node();
    node->data=x;
    node->next=NULL;
    return node;
}

void push(Node** root,int x)
{
    Node* node=newNode(x);
    node->next=*root;
    *root=node;    
}

void pop(Node** root)
{
    if(*root==NULL)
    {
        cout<<"Stack empty";
        return;
    }
    Node* temp=NULL;
    temp=*root;
    *root=(*root)->next;
    delete temp;    
}

int peek(Node** root)
{
    if(*root==NULL)
        return -1;
    return (*root)->data;
}

int main()
{
    Node* root=NULL;
    push(&root,20); 
    pop(&root);
    cout<<peek(&root);
    return 0;
}
