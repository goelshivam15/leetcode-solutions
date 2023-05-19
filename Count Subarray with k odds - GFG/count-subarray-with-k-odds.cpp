//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        int i=0,j=0,odd=0,count=0,res=0;
        while(j<nums.size()){
            if(nums[j]%2!=0){
                odd++;
                count=0;
            }
            while(odd==k){
                if(nums[i++]%2!=0){
                    odd--;
                }
                count++;
            }
            res+=count;
            j++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends