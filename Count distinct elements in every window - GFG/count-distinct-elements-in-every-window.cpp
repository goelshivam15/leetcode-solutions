//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        
        vector<int>  ans;
        unordered_map<int,int> mp;
        int left =0;
        int right =0;
        for(int i =0;i<k;i++){
            mp[A[i]]++;
        }
        ans.push_back(mp.size());
        for(right =k;right<n;right++){
            mp[A[left]]--;
            if(mp[A[left]]==0){
                mp.erase(A[left]);
            }
            
            left++;
            mp[A[right]]++;
            ans.push_back(mp.size());
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends