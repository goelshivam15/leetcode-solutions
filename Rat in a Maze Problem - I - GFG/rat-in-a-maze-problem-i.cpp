//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool safe(int nx ,int ny , vector<vector<int>>&m, vector<vector<int>>&vis,int n ){
        if(nx<n && nx>=0 && ny<n && ny>=0 && vis[nx][ny]==0 && m[nx][ny]==1){
            return true;
        }
        
        
        return false;
    }
    void f(int i , int j , vector<vector<int>>&m ,vector<vector<int>>&vis,vector<string>&ans , int n,string path){
        if(i==n-1 && j==n-1){
            ans.push_back(path);
            return ;
        }
        
        vis[i][j]=1;
        // down
        if(safe(i+1,j,m,vis,n)){
            f(i+1,j,m,vis,ans,n,path+'D');
        }
        
        if(safe(i,j-1,m,vis,n)){
            f(i,j-1,m,vis,ans,n,path+'L');
        }
        
        if(safe(i,j+1,m,vis,n)){
            f(i,j+1,m,vis,ans,n,path+'R');
            
            
        }
        
        if(safe(i-1,j,m,vis,n)){
            f(i-1,j,m,vis,ans,n,path+'U');
        }
        
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>> vis(n,vector<int>(n,0));
        f(0,0,m,vis,ans,n,path);
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