//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        
        vector<pair<int,int>> v;
        for(int i =0;i<n;i++){
            pair<int,int> p = make_pair(price[i],i+1);
            v.push_back(p);
        }
        
        sort(v.begin(),v.end());
        
        int ans =0;
        for(int i =0;i<v.size();i++){
            ans += min(v[i].second,k/v[i].first);
            k -= v[i].first*min(v[i].second,k/v[i].first);
        }
        
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends