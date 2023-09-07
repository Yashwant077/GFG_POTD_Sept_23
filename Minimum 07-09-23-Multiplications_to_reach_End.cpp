/*
Problem Description: Minimum Multiplications to reach End

Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30

Example 2:

Input:
arr[] = {3, 4, 65}
start = 7, end = 66175
Output:
4
Explanation:
Step 1: 7*3 = 21 % 100000 = 21 
Step 2: 21*3 = 63 % 100000 = 63 
Step 3: 63*65 = 4095 % 100000 = 4095 
Step 4: 4095*65 = 266175 % 100000 = 66175

Your Task:
You don't need to print or input anything. Complete the function minimumMultiplications() which takes an integer array arr, an integer start and an integer end as the input parameters and returns an integer, denoting the minumum steps to reach in which end can be achieved starting from start.

Expected Time Complexity: O(10^5)
Expected Space Complexity: O(10^5)

Constraints:

1 <= n <= 10^4
1 <= arr[i] <= 10^4
1 <= start, end < 10^5

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mod = 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end)
            return 0;
            
        int n = arr.size();
        vector<int> dp(mod,-1);
        
        dp[start]=0;
        
        queue<int>q;
        q.push(start);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int i=0; i<n; i++){
                long long next = (1LL*curr*arr[i])%mod;
                
                if(dp[next]==-1){
                    dp[next] = dp[curr]+1;
                    q.push(next);
                    
                    if(next == end)
                        return dp[next];
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
