// C++ program for iterative postorder traversal using one
// stack
#include <bits/stdc++.h>
using namespace std;

// A tree node
struct Node {
	int data;
	struct Node *left, *right;
};

// A utility function to create a new tree node
struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// An iterative function to do postorder traversal of a
// given binary tree
vector<int> postOrderIterative(struct Node* root)
{
	vector<int> arr;
    if(root==NULL)
        return arr;
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        Node* node=st.top();
        st.pop();
        arr.push_back(node->data);
        if(node->left)
            st.push(node->left);
        if(node->right)
            st.push(node->right);
    }
    reverse(arr.begin(),arr.end());
    return arr;
}

// Driver program to test above functions
int main()
{
	// Let us construct the tree shown in above figure
	struct Node* root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	printf("Post order traversal of binary tree is :\n");
	printf("[");
	vector<int> postOrderList = postOrderIterative(root);
	for (auto it : postOrderList)
		cout << it << " ";
	printf("]");
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
