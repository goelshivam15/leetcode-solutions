//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        vector<int> dist(100000,1e9);
        
        queue<pair<int,int>> q;
        int mod = 1e5;
        dist[start]=0;
        
        
        q.push({0,start});
        while(!q.empty()){
            int dis = q.front().first;
            int node = q.front().second;
            q.pop();
            for(auto it : arr){
                
                int adjacent = (node*it)%mod;
                if(dis+1<dist[adjacent]){
                    
                    dist[adjacent] = dis+1;
                    if(adjacent==end){
                        return dis+1;
                    }
                    q.push({dis+1,adjacent});
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