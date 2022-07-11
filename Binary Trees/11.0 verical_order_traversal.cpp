// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


 // } Driver Code Ends
class Solution
{
    public:
    //level order traversal to maintain vertical order
    vector<int> verticalOrder(Node *root)
    {
        queue<pair<Node*,int>> q;
        map<int,vector<int>> mp;
        int hd=0;
        q.push(make_pair(root,hd));
        Node* curr=root;
        while(!q.empty())
        {
            curr=q.front().first;
            hd=q.front().second;
            q.pop();
            //push node value with hd key
            //each hd key contains node values which lie in same vertical line
            mp[hd].push_back(curr->data);
            if(curr->left)
                q.push(make_pair(curr->left,hd-1));
            if(curr->right)
                q.push(make_pair(curr->right,hd+1));
        }
        vector<int> arr;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
            for(int i=0;i<itr->second.size();i++)
                arr.push_back(itr->second[i]);
        
        return arr;
    }

    //          1
    //       /     \
    //      2       3
    //     /  \    /  \
    //    4    5  6    7
    //             \  /  \
    //              8 10  9 
    //                  \
    //                  11
    //                    \
    //                     12  
    //--------------RECURSIVE(since we're using preorder traversal(left then right), 12 comes before 9)
    // void findMinMax (Node* root, int &min, int &max, int hd)
    // {
    //     if(root==NULL)
    //         return;
    //     if(hd<min)
    //         min=hd;
    //     else if(hd>max)
    //         max=hd;
    //     findMinMax(root->left, min, max, hd-1);
    //     findMinMax(root->right, min, max, hd+1);
    // }
    // void vertical(Node* root, int line_no, int hd, vector<int> &arr)
    // {
    //     if(root==NULL)
    //         return;
    //     if(hd==line_no)
    //         arr.push_back(root->data);
    //     vertical(root->left, line_no,hd-1,arr);
    //     vertical(root->right, line_no,hd+1,arr);
    // }
    // //Function to find the vertical order traversal of Binary Tree.
    // vector<int> verticalOrder(Node *root)
    // {
    //     vector<int> arr;
    //     int hd=0, min=INT_MAX, max=INT_MIN;
    //     findMinMax(root,min,max,hd);
    //     for(int i=min;i<=max;i++)
    //     {
    //         hd=0;
    //         vertical(root, i, hd,arr);
    //     }
    //     return arr;
    // }




    //-----------------MAP(since we're using preorder traversal(left then right), 12 comes before 9)
    // void vertical(Node* root, int hd, map<int, vector<int>> &mp)
    // {
    //     if(root==NULL)
    //         return;
    //     mp[hd].push_back(root->data);
    //     vertical(root->left,hd-1,mp);
    //     vertical(root->right,hd+1,mp);
    // }
    // //Function to find the vertical order traversal of Binary Tree.
    // vector<int> verticalOrder(Node *root)
    // {
    //     map<int, vector<int>> mp;
    //     vector<int> arr;
    //     int hd=0;
    //     vertical(root, hd, mp);
    //     for(auto itr=mp.begin();itr!=mp.end();itr++)
    //     {
    //         for(int i=0;i<itr->second.size();i++)
    //         {
    //             arr.push_back(itr->second[i]);
    //         }
    //     }
    //     return arr;
    // }
};



// { Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


  // } Driver Code Ends