//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    
    bool issafe(int nx , int ny , vector<vector<int>>&vis,vector<vector<int>>&m , int n ){
        if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]==0 && m[nx][ny]==1){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    void solve(int x ,int y ,vector<vector<int>>&m , int n ,vector<string>&ans, vector<vector<int>>&vis, string path){
        
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            
            return ;
        }
        
        vis[x][y]=1;
        
        if(issafe(x+1,y,vis,m,n)){
            solve(x+1,y,m,n,ans,vis,path+'D');
        }
        
         if(issafe(x,y-1,vis,m,n)){
            solve(x,y-1,m,n,ans,vis,path+'L');
        }
        
         if(issafe(x,y+1,vis,m,n)){
            solve(x,y+1,m,n,ans,vis,path+'R');
        }
        
         if(issafe(x-1,y,vis,m,n)){
            solve(x-1,y,m,n,ans,vis,path+'U');
        }
        
        
        vis[x][y]=0;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
    
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        
        string path = "";
        
        if(m[0][0]==0){
            return ans;
        }
        solve(0,0,m,n,ans,vis,path);
        
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends