//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++



class disjointset{

    public :
    vector<int> parent, rank,size;
        disjointset(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            size.resize(n+1);
            for(int i =0;i<=n;i++){
                parent[i] = i;
                size[i]=1;
            }
        }


        int findpar(int node){
            if(parent[node]== node){
                return node;
            }
            return parent[node] = findpar(parent[node]);
        }

        void unionbyrank(int u , int v){
            int ulp_u = findpar(u);
            int ulp_v = findpar(v);
            if(ulp_u==ulp_v){
                return;
            }
            if(rank[ulp_u]< rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionbysize(int u , int v){
            int ulp_u = parent[u];
            int ulp_v = parent[v];
            if(ulp_u==ulp_v){
                return ;
            }
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }


        }


};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        disjointset ds(n);
        int extras =0;
        for(auto it : edge){
            int u = it[0];
            int v = it[1];
            if(ds.findpar(u) == ds.findpar(v)){
                extras++;
            }
            else{
                ds.unionbysize(u,v);
            }
        }
        int cnt=0;
        
        for(int i =0;i<n;i++){
            if(ds.parent[i]==i){
                
                cnt++;
                
            }
        }
        
        int ans = cnt-1;
        if(extras>=ans){
            return ans;
        }
        
        return -1;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends