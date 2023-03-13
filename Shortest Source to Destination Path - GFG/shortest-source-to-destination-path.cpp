//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> a, int x, int y) {
        // code here
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        if(a[0][0]==0){
            return -1;
        }
        
        dist[0][0]= 0;
        
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        q.push({0,{0,0}});
        while(!q.empty()){
           auto it = q.front();
           q.pop();
           int row = it.second.first;
           int col = it.second.second;
           int dis = it.first;
            for(int i =0;i<4;i++){
                
                int nrow = row+ delrow[i];
                int ncol = col+ delcol[i];
                if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && a[nrow][ncol]==1 && dist[nrow][ncol]>dis+1){
                    dist[nrow][ncol]=dis+1;
                    if(nrow==x && ncol==y){
                        return dis+1;;
                    }
                    
                    q.push({dis+1,{nrow,ncol}});
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends