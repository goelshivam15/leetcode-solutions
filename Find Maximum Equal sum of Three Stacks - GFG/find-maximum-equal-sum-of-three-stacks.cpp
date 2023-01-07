//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        
        int sum1=0;
        int sum2=0;
        int sum3=0;
        int top1=0;
        int top2=0;
        int top3 =0;
        
        for(int i =0;i<n1;i++){
            sum1+=s1[i];
            
        }
        for(int i =0;i<n2;i++){
            sum2+=s2[i];
        }
        for(int i =0;i<n3;i++){
            sum3+=s3[i];
        }
        int ans =0;
        while(true){
            if(sum1==sum2 && sum2==sum3){
                
                ans =sum1;
                break;
            }
            if(top1==n1 || top2==n2 || top3==n3){
                ans= 0;
                break;
            }
            if(sum1>=sum2 && sum1>=sum3){
                sum1-=s1[top1];
                top1++;
            }
            else if(sum2>=sum1 && sum2>=sum3){
                sum2-=s2[top2];
                top2++;
            }
            else if(sum3>=sum2 && sum3>=sum1){
                sum3-=s3[top3];
                top3++;
            }
            
        }
        return ans;
    
        
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends