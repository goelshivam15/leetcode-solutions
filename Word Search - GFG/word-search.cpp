//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:


bool f(int i , int j , vector<vector<bool>>&vis , vector<vector<char>>&board, string word , int index){
    
    int n = board.size();
    int m= board[0].size();
    if(index==word.length()){
        return true;
    }
    if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==true || word[index]!=board[i][j]){
        return false;
    }
    
    bool temp = false;
    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0,+1,0,-1};
    
    
    vis[i][j]= true;
    for(int ptr = 0;ptr<4;ptr++){
        temp = temp || f(i+delrow[ptr],j+delcol[ptr],vis,board,word,index+1);
        
    }
    
    vis[i][j]= false;
    return temp;
    
    
}
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(f(i,j,vis,board,word,0)==true){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends