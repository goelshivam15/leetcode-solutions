//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        
        priority_queue<pair<int,char>> pq;
        map<char,int> mp;
        for(auto ch : s){
            mp[ch]++;
        }
        
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        
        while(k--){
            auto it = pq.top();
            int cnt = it.first;
            int ch = it.first;
            pq.pop();
            cnt--;
            pq.push({cnt,ch});
        }
        
        int ans = 0;
        while(!pq.empty()){
            int temp = pq.top().first;
            ans += temp*temp;
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends