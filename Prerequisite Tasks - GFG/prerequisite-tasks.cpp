//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:


vector<int> toposort(vector<int> adj[],int n){
    
    
    
    vector<int> indegree(n);
    
    
    for(int i =0;i<n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
    
    queue<int> q;
    
    vector<int> topo;
    for(int i =0;i<n;i++){
        
        if(indegree[i]==0){
            q.push(i);
        }
        
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return topo;
    
    
    
    
}
	bool isPossible(int n,int p, vector<pair<int, int> >& pre) {
	    
	    
	    
	    
	    vector<int> indegree(n);
	    
	    vector<int> adj[n];
	    
	    
	    for(auto it : pre){
	        
	        
	        adj[it.second].push_back(it.first);
	        
	    }
	    
	    
	    
	    
	    vector<int> topo = toposort(adj,n);
	    
	    
	    if(topo.size()==n){
	        return true;
	    }
	    
	    return false;
	    // Code here
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends