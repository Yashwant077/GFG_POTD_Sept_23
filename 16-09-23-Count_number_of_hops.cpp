/*
Problem Description: Count number of hops

A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top of Nth step. As the answer will be large find the answer modulo 1000000007.

Example 1:

Input:
N = 1
Output: 1
Example 2:

Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step
Your Task:
Your task is to complete the function countWays() which takes 1 argument(N) and returns the answer%(10^9 + 7).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 10^5
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int MOD = 1e9+7;
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // your code here
        
        vector<long long> dp;
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(2);
        dp.push_back(4);
        
        if(n<4){
            return dp[n];
        }else{
            for(int i=4;i<=n;i++){
                long long sum = (dp[i-1]%MOD + dp[i-2]%MOD + dp[i-3]%MOD )%MOD;
                dp.push_back(sum);
            }
        }
        
        return dp[n];
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
