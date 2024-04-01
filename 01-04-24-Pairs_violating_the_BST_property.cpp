/*
Problem Description: Pairs violating the BST property

Given a binary tree with n nodes, find the number of pairs violating the BST property.
BST has the following properties:-

Every node is greater than its left child and less than its right child.
Every node is greater than the maximum value of in its left subtree and less than the minimum value in its right subtree.
The maximum in the left sub-tree must be less than the minimum in the right subtree.


Example 1:

Input : 
n = 5
Input tree
    
Output :
5
Explanation : 
Pairs violating BST property are:-
(10,50), 10 should be greater than its left child value.
(40,30), 40 should be less than its right child value.
(50,20), (50,30) and (50,40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.


Example 2:

Input : 
n = 6
Input tree

Output :
8
Explanation :
There are total 8 Pairs which violation the BST properties.
Your task :
You don't have to read input or print anything. Your task is to complete the function pairsViolatingBST() that takes the root of the tree and n as input and returns number of pairs violating BST property.
 
Expected Time Complexity: O(n*logn)
Expected Space Complexity: O(n)
 
Your Task :
1 <= n <= 2*10^4
-10^9 <= node->data <= 10^9


*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
    vector<int> arr;
    int ans=0;
    
    void inorder(Node* root) {
        if(!root) return;
        inorder(root->left);
        arr.push_back(root->data);
        inorder(root->right);
    }
    
    void mergeSort(int i,int j) {
        if(i>=j)return;
        int m=i+(j-i)/2;
        mergeSort(i,m);
        mergeSort(m+1,j);
        int k=m+1, start=i;
        while(i<k and k<=j) {
            if(arr[i]<=arr[k])i++;
            else {
                ans+=m-i+1;
                k++;
            }
        }
       sort(arr.begin() + start, arr.begin() + j + 1);
    }
    int pairsViolatingBST(int n, Node *root) {
        inorder(root);
        mergeSort(0,n-1);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends
