//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int n){
        
        unordered_map<int,int> mp;
       priority_queue<int, vector<int> , greater<int>> pq;
       for(int i =0;i<n;i++){
           pq.push(arr[i]);
           
           
       }
       
       int rank =0;
      int prev =0;
       while(!pq.empty()){
           
          int curr = pq.top();
          if(curr!=prev){
              rank++;
              mp[curr] = rank;
              prev = curr;
              
          }
          
          pq.pop();
           
       }
       
       vector<int> ans;
       for(int i =0;i<n;i++){
           ans.push_back(mp[arr[i]]);
       }
       return ans;
       


    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends