//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    void f(int i, vector<vector<string>>&ans,vector<vector<string>>&list,vector<string>&temp){
        int n = list.size();
        int m = list[0].size();
        if(i==n){
            ans.push_back(temp);
            return;
        }
        
        
        for(int j =0;j<m;j++){
            temp.push_back(list[i][j]);
            f(i+1,ans,list,temp);
            temp.pop_back();
        }
    }
    vector<vector<string>> sentences(vector<vector<string>>&list){
        //Write your code here
        vector<vector<string>> ans;
        vector<string> temp;
        int i =0;
        f(i,ans,list,temp);
        return ans;
        
        
        
    }
};


//{ Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<vector<string>>list(m, vector<string>(n));
	    for(int i = 0 ; i < m; i++){
	        for(int j = 0; j < n; j++){
	            cin >> list[i][j];
	        }
	    }
	    Solution ob;
	    vector<vector<string>>ans = ob.sentences(list);
	    for(auto it : ans){
	        for(auto it1 : it){
	            cout << it1 << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}

// } Driver Code Ends