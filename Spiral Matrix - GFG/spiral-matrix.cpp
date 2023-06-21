//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &matrix, int n, int m, int k)
    {
        // Your code goes here
         int top =0;
        int left = 0;
        int bottom = n-1;
        int right = m-1;
        vector<int> ans;

        while(top<=bottom && left<=right){

            for(int i = left;i<=right;i++){
                k--;
                if(k==0){
                    return matrix[top][i];
                    break;
                }
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top;i<=bottom;i++){
                k--;
                if(k==0){
                    return matrix[i][right];
                    break;
                }
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){

                  for(int i = right;i>=left;i--){
                      k--;
                      if(k==0){
                          return matrix[bottom][i];
                          break;
                      }
                    ans.push_back(matrix[bottom][i]);
                }

            }
            bottom--;
            if(left<=right){

                 for(int i = bottom;i>=top;i--){
                     k--;
                     if(k==0){
                         return matrix[i][left];
                         break;
                     }
                    ans.push_back(matrix[i][left]);
                }

            }
            left++;

        }

        return 0;
        
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends