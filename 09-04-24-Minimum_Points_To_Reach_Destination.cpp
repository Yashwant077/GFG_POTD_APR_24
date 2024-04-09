/*
Problem Description: Minimum Points To Reach Destination

Given a m*n grid with each cell consisting of positive, negative, or zero point. We can move across a cell only if we have positive points. Whenever we pass through a cell, points in that cell are added to our overall points, the task is to find minimum initial points to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :
1. From a cell (i, j) we can move to (i + 1, j) or (i, j + 1).
2. We cannot move from (i, j) if your overall points at (i, j) are <= 0.
3. We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.

Example 1:

Input: 
m = 3, n = 3 
points = {{-2,-3,3}, 
          {-5,-10,1},
          {10,30,-5}} 
Output: 
7 
Explanation: 7 is the minimum value to reach the destination with positive throughout the path. Below is the path. (0,0) -> (0,1) -> (0,2) -> (1, 2) -> (2, 2) We start from (0, 0) with 7, we reach (0, 1) with 5, (0, 2) with 2, (1, 2) with 5, (2, 2) with and finally we have 1 point (we needed greater than 0 points at the end).
Example 2:
Input:
m = 3, n = 2
points = {{2,3},  
          {5,10},  
          {10,30}} 
Output: 
1 
Explanation: Take any path, all of them are positive. So, required one point at the start
Your Task:  
You don't need to read input or print anything. Complete the function minPoints() which takes m,n and 2-d vector points as input parameters and returns the minimum initial points to reach cell (m-1, n-1) from (0, 0).

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ m ≤ 10^3  
1 ≤ n ≤ 10^3
-10^3 ≤ points[i][j] ≤ 10^3

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int solve(vector<vector<int>>&points,int m,int n,int i,int j,vector<vector<int>>&dp)
	{
        if(i>=m || j>=n)
        return INT_MAX;
        
        if(i==m-1 && j==n-1){
            return 1-points[i][j];
        }
        
        if(dp[i][j]!=-1)
        return dp[i][j];
    
        int ans1=solve(points,m,n,i+1,j,dp);
        int ans2=solve(points,m,n,i,j+1,dp);
        
         return dp[i][j]=max(1,min(ans1,ans2)-points[i][j]);
    }
    
    int minPoints(int m, int n, vector<vector<int>> points) 
    { 
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=solve(points,m,n,0,0,dp);
        return ans;
    } 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
