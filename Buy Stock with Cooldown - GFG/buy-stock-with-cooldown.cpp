//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
   
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        
        vector<long long> prev2(2,0);
        vector<long long> prev1(2,0);
        vector<long long> curr(2,0);
        prev1[0]=0;
        prev1[1]=0;
        for(int index = n-1;index>=0;index--){
            for(int buy =0;buy<=1;buy++){
                
                    long long  profit =0;
                    if(buy==1){
                        profit = max(-prices[index]+prev1[0],prev1[1]);
                    }
                    else{
                        profit = max(prices[index]+prev2[1],prev1[0]);
                    }
                
                curr[buy]= profit;
                
            }
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1[1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends