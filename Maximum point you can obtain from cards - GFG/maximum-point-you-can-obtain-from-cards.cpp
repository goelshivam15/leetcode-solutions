//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int n, int k) {
        // code here
        
        long long sum =0;
        for(int i =0;i<k;i++){
            sum += cardPoints[i];
        }
        
        long long maxsum = sum;
        for(int i = k-1,j=n-1;i>=0;i--,j--){
            sum -= cardPoints[i];
            sum += cardPoints[j];
            maxsum = max(maxsum,sum);
        }
        
        return maxsum;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends