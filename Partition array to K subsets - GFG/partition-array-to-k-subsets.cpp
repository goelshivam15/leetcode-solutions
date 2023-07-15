//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
    private:
    bool solve(int a[], vector<bool>& visited, int k, int startIdx, int currSum, int target, int n) {
        if (k == 1) return true;
        if (currSum > target) return false;
        if (currSum == target) {
            return solve(a, visited, k-1, 0, 0, target,n);
        }

        for (int i = startIdx; i < n; i++) {
            if (visited[i]) continue;
            if (a[i] > target) return false; 

            visited[i] = true;
            if (solve(a, visited, k, i + 1, currSum + a[i], target,n)) return true;
            visited[i] = false;
        }

        return false;
    }
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
           int sum =0;
           for(int i =0;i<n;i++){
               sum += a[i];
           }
        if (sum % k != 0) return false;

        sort(a,a+n);
        vector<bool> visited(n, false);
        return solve(a, visited, k, 0, 0, sum / k,n);
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends