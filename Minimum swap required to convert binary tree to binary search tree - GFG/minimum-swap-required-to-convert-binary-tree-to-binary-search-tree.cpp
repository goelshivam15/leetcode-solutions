//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  
  
  void inorder(int index  , vector<int>&a,int n , vector<int>&in){
      if(index>=n){
          return ;
      }
      
      inorder(2*index+1,a,n,in);
      in.push_back(a[index]);
      inorder(2*index+2,a,n,in);
  }
  
 
    int minSwaps(vector<int>&a, int n){
        //Write your code here
       vector<int> in;
       int index = 0;
       inorder(index,a,n,in);
       vector<int> temp ;
       temp = in;
       sort(temp.begin(),temp.end());
       int cnt = 0;
       unordered_map<int,int> mp;
       for(int i =0;i<n;i++){
           mp[in[i]] = i;
       }
       
       for(int i =0;i<n;i++){
           if(temp[i]!=in[i]){
               cnt++;
               int curr = in[i];
               
               swap(in[i],in[mp[temp[i]]]);
               mp[curr] = mp[temp[i]];
               mp[temp[i]] = i;
           }
       }
       
       return cnt;
       
        
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
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends