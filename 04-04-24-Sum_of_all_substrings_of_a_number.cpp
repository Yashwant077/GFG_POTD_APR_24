/*
Problem Description: Sum of all substrings of a number

Given an integer s represented as a string, the task is to get the sum of all possible sub-strings of this string.
As the answer will be large, return answer modulo 109+7. 

Note: The number may have leading zeros.

Example 1:

Input:
s = "1234"
Output: 
1670
Explanation: 
Sum = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234 = 1670

Example 2:

Input:
s = "421"
Output: 
491
Explanation: 
Sum = 4 + 2 + 1 + 42 + 21 + 421 = 491
Your Task:
You only need to complete the function sumSubstrings that takes s as an argument and returns the answer modulo 109+7.

Expected Time Complexity: O(|s|).
Expected Auxiliary Space: O(|s|).

Constraints:
1 <= |s| <= 10^5

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        long long mod = 1e9+7;
        int n = s.size();
        long long dp[n];
        dp[0] = (s[0]-'0');
        long long sum=dp[0];
        for(int i=1; i<s.size(); i++)
        {
            dp[i]=((i+1)*(s[i]-'0')+10*dp[i-1])%mod;
            sum=(sum+dp[i])%mod;
        }
        return sum%mod;
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends

