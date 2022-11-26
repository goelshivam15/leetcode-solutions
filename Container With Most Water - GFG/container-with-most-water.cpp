//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long a[], int len)
{
    // Your code goes here
    long long i =0;
    long long j =len-1;
    long long maxarea = INT_MIN;
    while(i<=j){
        long long area = min(a[i],a[j])*(j-i);
        maxarea = max(area,maxarea);
        if(a[i]<a[j]){
            i++;
        }
        else{
            j--;
        }
    }
    
    return maxarea;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends