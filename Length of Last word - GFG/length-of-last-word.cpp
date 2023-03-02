//{ Driver Code Starts
//Initial Template for C++

// CPP program for implementation of efficient 
// approach to find length of last word 
#include <bits/stdc++.h> 
using namespace std; 

int findLength(string s);

// Driver code 
int main() 
{ 
	int t;
	cin>>t;
	t+=1;
	bool flag = false;
	while(t--){
	    string s;
	    getline(cin,s);
	    if(!flag){
	        flag = true;
	        continue;
	    }
	    cout<<findLength(s)<<endl;
	}
	return 0;
} 

// } Driver Code Ends


//User function Template for C++

int findLength(string s){
    //code
     int count =0;
        int j = s.size()-1;
        int flag =0;
        while(j>=0){
            if(s[j]==' '){
                j--;
            }
            else{
                while(j>=0){
                    if(s[j]==' '){
                        flag =1;
                        break;
                    }
                    else{
                        count++;
                        j--;
                    }
                }
            }
            if(flag==1){
                break;
            }
        }

        return count;
        
    
}