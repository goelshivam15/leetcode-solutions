//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        int sum =0;
        pq.push({0,0});
        int vis[v]={0};
        
        while(!pq.empty()){
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if(vis[node]==1){
                continue;
            }
            else{
                vis[node]=1;
                sum += weight;
                for(auto it : adj[node]){
                    int adjacent = it[0];
                    int edgeweight = it[1];
                    if(!vis[adjacent]){
                        pq.push({edgeweight,adjacent});
                    }
                    
                    
                }
            }
            
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends