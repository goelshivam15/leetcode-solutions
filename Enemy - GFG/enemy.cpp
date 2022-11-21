//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            if(k<=0){
                return n*m;
            }
            vector<int> a;
            vector<int> b;
            a.push_back(0);
            b.push_back(0);
            
            for(int i =0;i<k;i++){
                a.push_back(enemy[i][0]);
                b.push_back(enemy[i][1]);
            }
            a.push_back(n+1);
            b.push_back(m+1);
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            int length = INT_MIN;
            int breadth = INT_MIN;
            for(int i =1;i<a.size();i++){
                
                int newlength = a[i]-a[i-1]-1;
                length = max(length,newlength);
                
            }
            for(int i =1;i<b.size();i++){
                
                int newbreadth = b[i]-b[i-1]-1;
                breadth = max(newbreadth,breadth);
                
            }
            
            int area = length*breadth;
            return area;
            
            
            
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends