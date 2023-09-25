/*
Problem Description: Maximum Sum Combination

Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.

Example 1:

Input:
N = 2
K = 2
A [ ] = {3, 2}
B [ ] = {1, 4}
Output: {7, 6}
Explanation: 
7 -> (A : 3) + (B : 4)
6 -> (A : 2) + (B : 4)

Example 2:

Input:
N = 4
K = 3
A [ ] = {1, 4, 2, 3}
B [ ] = {2, 5, 1, 6}
Output: {10, 9, 9}
Explanation: 
10 -> (A : 4) + (B : 6)
9 -> (A : 4) + (B : 5)
9 -> (A : 3) + (B : 6)
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCombinations() which takes the interger N,integer K and two integer arrays A [ ] and B [ ] as parameters and returns the maximum K valid distinct sum combinations .

Expected Time Complexity: O(Nlog(N))
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤  10^5
1 ≤ K ≤  N
1 ≤ A [ i ] , B [ i ] ≤ 10^4

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // code here
        vector<int> ans;
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        priority_queue<pair<int,pair<int,int>>>p;
        p.push({a[0]+b[0],{0,0}});
        set<pair<int,int>>st;
        
        while(!p.empty()){
            auto it=p.top();
            int val = it.first;
            
            int i=it.second.first;
            int j=it.second.second;
            
            ans.push_back(val);
            p.pop();
            
            if(ans.size()==k)
                return ans;
                
            if(i+1<n&&j<n){
                if(st.find({i+1,j})==st.end()){
                    p.push({a[i+1]+b[j],{i+1,j}});
                    st.insert({i+1,j});
                }
            }
            
            if(i<n && j+1<n){
                if(st.find({i,j+1})==st.end()){
                    p.push({a[i]+b[j+1],{i,j+1}});
                    st.insert({i,j+1});
                }
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
