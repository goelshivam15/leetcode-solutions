//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        vector<int> ans;
        int i =0;
        int j = n-1;
        int min =0;
        sort(candies,candies+n);
        while(i<=j){
            min+=candies[i];
            i++;
            j= j-k;
        }
        ans.push_back(min);
        int max =0;
        i=0;
        j=n-1;
        while(i<=j){
            max+=candies[j];
            i=i+k;
            j--;
        }
        ans.push_back(max);
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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends