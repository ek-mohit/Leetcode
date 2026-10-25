class Solution {
public:
    int solve (string & a, string & b, int i, int j , vector<vector<int>> &dp ){

        if(i == a.size() ) return b.size()-j ;
        
        if (j == b.size()) return a.size() -i;

        int ans=0;

        if (a[i] == b[j]){
            return solve(a,b, i+1, j+1, dp);
        }

        if(dp[i][j] != -1) return dp[i][j];

        else{
        //insert
        int insertans= 1+ solve (a,b , i, j+1, dp);
        //delete
        int deleteans = 1 + solve (a,b, i+1, j, dp);
        //replace
        int replaceans = 1+ solve (a,b, i+1, j+1, dp);

        ans = min(insertans, min(deleteans, replaceans));

        }
        return dp[i][j]= ans;

        
    }

    /*int solveTab(string &a, string &b){
        int n1 =  word1.size();
        int n2 =  word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));




        
    }
    */
    int minDistance(string word1, string word2) {
         int n1 =  word1.size();
         int n2 =  word2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return  solve(word1 , word2, 0,0,dp);
        
    }
};