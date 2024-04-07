/*
Problem Description: Maximize dot product

Given two arrays a and b of positive integers of size n and m where n >= m, the task is to maximize the dot product by inserting zeros in the second array but you cannot disturb the order of elements.

Dot product of array a and b of size n is a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1].

Example 1:

Input: 
n = 5, a[] = {2, 3, 1, 7, 8} 
m = 3, b[] = {3, 6, 7}
Output: 
107
Explanation: 
We get maximum dot product after inserting 0 at first and third positions in second array.
Therefore b becomes {0, 3, 0, 6, 7}. 
Maximum dot product = 2*0 + 3*3 + 1*0 + 7*6 + 8*7 = 107.
Example 2:

Input: 
n = 3, a[] = {1, 2, 3}
m = 1, b[] = {4} 
Output: 
12 
Explanation: 
We get maximum dot product after inserting 0 at first and second positions in second array.
Therefore b becomes {0, 0, 4}. 
Maximum Dot Product = 1*0 + 2*0 + 3*4 = 12.
Your Task:  
You don't need to read input or print anything. Complete the function maxDotProduct() which takes n, m, array a and b as input parameters and returns the maximum value.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ m ≤n ≤ 10^3
1 ≤ a[i], b[i] ≤ 10^3

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	
	int solve(int i, int j, int a[], int b[], vector<vector<int>> &dp) 
    { 
        if(j<0){
            return 0;
        }
        
        if(i<0){
            return -1e9;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
      
        int notpick = 0 + solve(i-1, j, a, b, dp);
        int pick = a[i]*b[j] + solve(i-1, j-1, a, b, dp);
        
        return dp[i][j] = max(notpick, pick);
    }
    
    int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, a, b, dp);
    } 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
