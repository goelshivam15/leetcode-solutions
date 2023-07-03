//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        // code here
        vector<int> ans;
        
        
        for(int i =n-1;i>=0;i--){
            int temp = (i+1)%n;
            
            while(temp != i){
                
                if(arr[temp]>arr[i]){
                    ans.push_back(arr[temp]);
                    break;
                }
                else{
                    temp = (temp+1)%n;
                }
                
            }
            if(temp==i){
                ans.push_back(-1);
            }
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends