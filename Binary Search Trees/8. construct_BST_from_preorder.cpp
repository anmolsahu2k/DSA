/* A O(n) program for construction
of BST from preorder traversal */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

// A utility function to create a node
node* newNode(int data)
{
	node* temp = new node();

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

// A recursive function to construct
// BST from pre[]. preIndex is used
// to keep track of index in pre[].
node* constructTreeUtil(int pre[], int* preIndex, int key, int min, int max, int size)
{
	if(*preIndex>size)
        return NULL;
    node* root=NULL;
    if(key>min && key<max)
    {
        root=newNode(key);
        *preIndex++;
        if(*preIndex<size)
            root->left=constructTreeUtil(pre,preIndex,pre[*preIndex],min,key, size);
        if(*preIndex<size)
            root->right=constructTreeUtil(pre,preIndex,pre[*preIndex],key,max, size);
    }
    return root;
}

// The main function to construct BST
// from given preorder traversal.
// This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, pre[0],
							INT_MIN, INT_MAX, size);
}

// A utility function to print inorder
// traversal of a Binary Tree
void printInorder(node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

// Driver code
int main()
{
	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int size = sizeof(pre) / sizeof(pre[0]);

	// Function call
	node* root = constructTree(pre, size);

	cout << "Inorder traversal of the constructed tree: \n";
	printInorder(root);

	return 0;
}

// This is code is contributed by rathbhupendra
