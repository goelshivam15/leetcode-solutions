//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    
	    vector<int> temp = nums;
	    sort(temp.begin(),temp.end());
	    unordered_map<int,int> mp;
	    for(int i =0;i<nums.size();i++){
	        mp[nums[i]]=i;
	    }
	    
	    int count =0;
	    for(int i =0;i<nums.size();i++){
	        if(nums[i]!=temp[i]){
	            
	            count++;
	            int init = nums[i];
	            swap(nums[i],nums[mp[temp[i]]]);
	            mp[init]= mp[temp[i]];
	            mp[temp[i]]= i;
	            
	        }
	        else{
	            mp[nums[i]]=i;
	        }
	    }
	    
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends