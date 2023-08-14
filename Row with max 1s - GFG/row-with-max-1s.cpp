//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    
	    
	    int maxi  =INT_MIN;
	    int mini = INT_MAX;
	    for(int i =0;i<n;i++){
	        int index = lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
	        if(index!=m && index!=-1){
	           if(m-index>maxi){
	               maxi = m-index;
	               mini = i;
	               
	           }
	        }
	    }
	    
	    if(mini==INT_MAX){
	        return -1;
	    }
	    return mini;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends