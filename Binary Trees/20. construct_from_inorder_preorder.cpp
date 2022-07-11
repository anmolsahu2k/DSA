// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    //NOT WORKING???
    Node* create(int in[],int pre[], int inStart, int inEnd, unordered_map<int,int> mp)
    {
        static int preIndex=0;
        //Base
        if(inStart>inEnd)
            return NULL;
            
        //Additional statements
        int curr=pre[preIndex];
        preIndex++;
        Node* tNode=new Node(curr);
        if(inStart==inEnd)
            return tNode;
        int inIndex=mp[curr];
        
        
        //Hypothesis
        Node* lsubtree=create(in,pre,inStart,inIndex-1,mp);
        Node* rsubtree=create(in,pre,inIndex+1,inEnd,mp);
        
        //Induction
        tNode->left=lsubtree;
        tNode->right=rsubtree;
        return tNode;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        
        int inStart=0;
        int inEnd=n-1;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[in[i]]=i;
        Node* head=create(in, pre, inStart, inEnd, mp);
        return head;
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends