/*
Problem Description: Add two numbers represented by linked lists

Given two decimal numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Example 1:

Input:
n = 2
num1 = 45 (4->5->null)
m = 3
num2 = 345 (3->4->5->null)
Output: 
3->9->0->null  
Explanation: 
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Example 2:

Input:
n = 4
num1 = 0063 (0->0->6->3->null)
m = 2
num2 = 07 (0->7->null)
Output: 
7->0->null
Explanation: 
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(max(n,m)) for the resultant list.

Constraints:
1 <= n, m <= 10^4

*/

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    public:
    struct Node* rev(struct Node* n1)
    {
        Node* curr=n1;
        Node* prev=NULL;
        while(curr)
        {
            Node* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
         while(num1 && num1->data==0 )
        {
            num1=num1->next;
        }
        while(num2 && num2->data==0)
        {
            num2=num2->next;
        }
        if(num1==NULL && num2==NULL)
        {
            Node *y=new Node(0);
            return y;
        }
        Node* n1=rev(num1);
        Node* n2=rev(num2);
        Node* dummy=new Node(0);
        Node* d1=dummy;
        int dig1,dig2,carry=0,sum;
        while(n1||n2||carry)
        {
            if(n1==NULL)
            {
                dig1=0;
            }
            else
            {
                dig1=n1->data;
            }
            if(n2==NULL)
            {
                dig2=0;
            }
            else
            {
                dig2=n2->data;
            }
            sum=dig1+dig2+carry;
            carry=sum/10;
            sum=sum%10;
            Node* new1=new Node(sum);
            d1->next=new1;
            d1=d1->next;
            if(n1!=NULL)
            {
                n1=n1->next;
            }
            if(n2!=NULL)
            {
                n2=n2->next;
            }
        }
        return rev(dummy->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
