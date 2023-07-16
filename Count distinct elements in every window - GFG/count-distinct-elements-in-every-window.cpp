//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
        //code here.
        int i =0;
        
        map<int,int> mp;
        for(int j =0;j<k;j++){
            mp[a[j]]++;
            
        }
        vector<int> ans;
        ans.push_back(mp.size());
        for(int j = k;j<n;j++){
            
           mp[a[i]]--;
          if(mp[a[i]]==0){
              mp.erase(a[i]);
          }
          i++;
           mp[a[j]]++;
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