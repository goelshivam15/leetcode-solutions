//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        
        
          if(s.length()==0){
            return 0;
        }

        int l =0;
        int r =0;
        int maxlength = INT_MIN;
        int arr[256]={0};
        while(r<s.length()){
            arr[s[r]]++;
            while(arr[s[r]]>1){
                arr[s[l]]--;
                l++;
            }

            maxlength = max(maxlength,r-l+1);
            r++;
        }

        return maxlength;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends