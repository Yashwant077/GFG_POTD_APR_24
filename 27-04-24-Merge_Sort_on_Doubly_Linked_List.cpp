/*
Problem Description: Merge Sort on Doubly Linked List

Given Pointer/Reference to the head of a doubly linked list of n nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

Example 1:

Input:
n = 8
value[] = {7,3,5,2,6,4,1,8}
Output:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
Explanation: After sorting the given
linked list in both ways, resultant
matrix will be as given in the first
two line of output, where first line
is the output for non-decreasing
order and next line is for non-
increasing order.
Example 2:

Input:
n = 5
value[] = {9,15,0,-1,0}
Output:
-1 0 0 9 15
15 9 0 0 -1
Explanation: After sorting the given
linked list in both ways, the
resultant list will be -1 0 0 9 15
in non-decreasing order and 
15 9 0 0 -1 in non-increasing order.
Your Task:
The task is to complete the function sortDoubly() which takes reference to the head of the doubly linked and Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing. The printing is done automatically by the driver code.

Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(logn)

Constraints:
1 <= n <= 10^4
0 <= values[i] <= 10^5


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    struct Node* merge(struct Node* node1, struct Node* node2) {
        struct Node* ptr;
        while(node1 && node2) {
            ptr = node1;
            if(node1->data <= node2->data) {
                node1 = node1->next;
            } else {
                struct Node* tmp = node2->next;
                node2->next = node1;
                if(node1->prev) {
                    node1->prev->next = node2;
                    node2->prev = node1->prev;
                }
                node1->prev = node2; 
                node2 = tmp;
                if(node2) node2->prev = NULL;
            }
        }
        if(node2 != NULL) {
            node2->prev = ptr;
            ptr->next = node2;
        }
        while(ptr->prev) {
            ptr = ptr->prev;    
        }
        return ptr;
    }
    
    struct Node* mergeSort(struct Node* node, int len) {
        if(len == 1) return node;
        struct Node *node2 = node;
        for(int i = 1; i <= len/2; i++) {
            node2 = node2->next;
        }
        node2->prev->next = NULL;
        node2->prev = NULL;
        node = mergeSort(node, len/2);
        node2 = mergeSort(node2, len-len/2);
        node = merge(node, node2);
        return node;
    }  
  
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        int len = 0;
        struct Node* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        head = mergeSort(head, len);
        return head;
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends
