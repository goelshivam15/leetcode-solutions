//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> left(n);
        vector<int> right(n);
        
        int leftmaxi = INT_MIN;
        
        for(int i =0;i<n;i++){
            if(arr[i]>leftmaxi){
                left[i] = arr[i];
                leftmaxi = arr[i];
            }
            else{
                left[i] = leftmaxi;
            }
        }
        
        int rightmaxi = INT_MIN;
        for(int i = n-1;i>=0;i--){
            if(arr[i]>rightmaxi){
                right[i] = arr[i];
                rightmaxi = arr[i];
            }
            else{
                right[i] = rightmaxi;
            }
        }
        
        long long ans = 0;
        for(int i =0;i<n;i++){
            ans += min(left[i],right[i])-arr[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends