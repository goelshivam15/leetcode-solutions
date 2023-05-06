//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:


bool bfs(int start , int color[] , vector<int> adj[]){
    color[start]=0;
    
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto it : adj[node]){
            if(color[it]==-1){
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
    }
    
    return true;
}
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    
	    int color[v];
	    for(int i =0;i<v;i++){
	        color[i]= -1;
	    }
	    
	    
	    for(int i =0;i<v;i++){
	        if(color[i]==-1){
	            if(bfs(i,color,adj)==false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends