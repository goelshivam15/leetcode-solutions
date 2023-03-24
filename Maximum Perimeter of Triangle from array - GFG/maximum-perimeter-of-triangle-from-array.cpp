//{ Driver Code Starts
// Efficient solution to find
// out maximum perimeter triangle which
// can be formed using the elements
// of the given array
#include <iostream>
#include <algorithm>

using namespace std;

// Function to find out maximum perimeter
int maxPerimeter(int arr[], int n);


// Driver Program
int main()
{
	int t,n;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout << maxPerimeter(arr,n) << endl;
    }
	return 0;
}


// } Driver Code Ends


int maxPerimeter(int arr[], int n){

    // Complete the function
     
        sort(arr,arr+n, greater<int>());
        for(int i =0;i<n-2;i++){
            int a = arr[i];
            int b = arr[i+1];
            int c = arr[i+2];
            if(b+c>a){
                return a+b+c;
            }
        }

        return -1;
    
}