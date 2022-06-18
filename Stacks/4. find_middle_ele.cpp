#include<iostream>

using namespace std;
class MyStack{
    public:
    struct Node{
        int data;
        Node* next;
        Node* prev;
    };
    Node* head=NULL;
    Node* mid=NULL;
    int size=0;
    Node* newNode(int x)
    {
        Node* node=new Node();
        node->data=x;
        node->next=NULL;
        node->prev=NULL;
    }

    void push(int x)
    {
        Node* node=newNode(x);
        node->next=head;
        if(head==NULL)
        {
            mid=node;
        }
        else
        {
           (head)->prev=node;
        }
        head=node;
        size++;
        if(size%2==0)
            mid=mid->prev;
    }

    int pop()
    {
        if(head==NULL)
            return -1;
        Node* temp=head;
        int x=temp->data;
        head=(head)->next;
        (head)->prev=NULL;
        size--;
        if(size%2!=0)
            mid=mid->next;        
        delete temp;
        return x;
    }

    int findMiddle()
    {
        if(head==NULL)
            return -1;
        return mid->data;
    }

    void deleteMiddle()
    {
        if(mid==NULL)
            return;
        else if(size==1)
        {
            head=NULL;
            delete mid;
            mid=NULL;
        }
        else if(size==2)
        {
            head=head->next;
            head->prev=NULL;
            delete mid;
            mid=head;
        }
        else
        {
            Node* temp=mid;
            if(size%2==0)
                mid=mid->next;
            else
                mid=mid->prev;
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }
        size--;
    }

};
int main()
{
    MyStack st; 
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Middle Element : "<< st.findMiddle() << endl;
    st.deleteMiddle();
    cout <<"New Middle Element : "<< st.findMiddle() << endl;
    return 0;
}