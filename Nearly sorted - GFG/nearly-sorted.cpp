//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
        
        vector<int> ans;
        priority_queue<int,vector<int> , greater<int>> pq;
        for(int i =0;i<=k;i++){
            
            pq.push(arr[i]);
            
        }
        
        ans.push_back(pq.top());
        for(int i = k+1;i<n;i++){
            pq.pop();
            pq.push(arr[i]);
            ans.push_back(pq.top());
        }
        pq.pop();
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends