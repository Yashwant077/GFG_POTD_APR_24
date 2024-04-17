/*
Problem Description: Count Pairs in an Array

Given an array arr of n integers, count all pairs (arr[i], arr[j]) in it such that i*arr[i] > j*arr[j] and 0 ≤ i < j < n.

Note: 0-based Indexing is followed.

Example 1:

Input :
n = 4
arr[] = {8, 4, 2, 1}
Output :
2
Explanation:
If we see the array after operations
[0*8, 1*4, 2*2, 3*1] => [0, 4, 4, 3]
Pairs which hold the condition i*arr[i] > j*arr[j] are (4,1) and (2,1), so in total 2 pairs are available.
Example 2:

Input :
n = 7
arr[] = {5, 0, 10, 2, 4, 1, 6}
Output:
5
Explanation :
Pairs which hold the condition i*arr[i] > j*arr[j] are (10,2), (10,4), (10,1), (2,1) and (4,1), so in total 5 pairs are there.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function countPairs() which takes the array arr[] and its size n as inputs and returns the required result.

Expected Time Complexity: O(n*log(n))
Expected Auxiliary Space: O(n*log(n))

Constraints:
1 ≤ n ≤ 10^4
1 ≤ arr[i] ≤ 10^4

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int countPairs(int a[] , int n ) 
    {
        // Your code goes here 
        vector<int>b,s;
        
        for(int i=0;i<n;i++){
            b.push_back(i*a[i]);
            s.push_back(b[i]);
        }
        
        sort(s.begin(),s.end());
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int i1=lower_bound(s.begin(),s.end(),b[i])-s.begin();
            ans+=i1;
            s.erase(s.begin()+i1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends
