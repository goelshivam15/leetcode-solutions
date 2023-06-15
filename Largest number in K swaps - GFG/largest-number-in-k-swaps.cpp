//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    void f(string&ans , string str, int k, int index){
        if(k==0){
            return ;
        }
        
        int n = str.length();
        
        
        char maxchar = str[index];
        for(int i =index+1;i<n;i++){
            if(str[i]>maxchar){
                maxchar = str[i];
                
            }
        }
        if(maxchar != str[index]){
            k--;
        }
        
        
        for(int i = n-1;i>=index;i--){
            if(str[i]==maxchar){
                swap(str[index],str[i]);
                if(ans<str){
                    ans = str;
                }
                
                f(ans,str,k,index+1);
                swap(str[index],str[i]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       
       string ans = str;
       f(ans,str,k,0);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends