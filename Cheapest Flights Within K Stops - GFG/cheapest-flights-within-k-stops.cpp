//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int v, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>> adj[v];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dist(v,1e9);
        dist[src] =0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int curr = it.second.second;
            if(stops>k) continue;
            
            for(auto iter : adj[node]){
                int adjacent = iter.first;
                int edgeweight = iter.second;
                if(curr + edgeweight < dist[adjacent] && stops<=k){
                    dist[adjacent] = curr + edgeweight;
                    q.push({stops+1,{adjacent,curr + edgeweight}});
                }
            }
            
        }
        
        if(dist[dst]==1e9){
            return -1;
        }
        
        return dist[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends