//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int f(int a[] , int pages, int n ){
        int students = 1;
        int currpages = 0;
        for(int i =0;i<n;i++){
            if(currpages + a[i]<=pages){
                currpages += a[i];
            }
            else{
                students++;
                currpages = a[i];
            }
        }
        
        return students;
    }
    int findPages(int a[], int n, int m) 
    {
        //code here
        if(m>n){
            return -1;
        }
        int low = *max_element(a,a+n);
        int high = 0;
        for(int i=0;i<n;i++){
            high += a[i];
        }
        
        while(low<=high){
            int mid = (low+high)/2;
            int students = f(a,mid,n);
            if(students<=m){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends