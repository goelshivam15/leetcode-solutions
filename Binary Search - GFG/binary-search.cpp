//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        
        int i =0;
        int j = n-1;
        int ans = -1;
        int mid = (i+j)/2;
        while(i<=j){
            if(arr[mid]==k){
                ans = mid;
                break;
            }
            else if(arr[mid]>k){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
            
            mid = (i+j)/2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends