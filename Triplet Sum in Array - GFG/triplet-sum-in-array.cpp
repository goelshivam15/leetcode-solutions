//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int a[], int n, int x)
    {
        //Your Code Here
        sort(a,a+n);
        for(int k = 0;k<n;k++){
            int i = k+1;
            int j = n-1;
            while(i<j){
                if(a[i]+a[j]+a[k]==x){
                    return true;
                }
                else if(a[i]+a[j]+a[k]>x){
                    
                    j--;
                    
                    
                }
                else{
                    i++;
                }
            }
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends