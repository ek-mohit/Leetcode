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

    int solveTab(string &a, string &b){
        int n1 =  a.size();
        int n2 =  b.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for ( int j=0; j<b.length() ;j++){
            dp[a.length()][j] = b.size()-j;
        }

        
        for ( int i=0; i<a.length() ;i++){
            dp[i][b.size()] = a.size()-i;
        }

        for( int i= n1-1 ; i>=0 ; i--){
            for (int j=n2-1 ; j>=0; j--){

        int ans=0;

        if (a[i] == b[j]){
            ans = dp[i+1][j+1];
        }

        else{
        //insert
        int insertans= 1+ dp[i][j+1];
        //delete
        int deleteans = 1 + dp[i+1][j];
        //replace
        int replaceans = 1+ dp[i+1][j+1];

        ans = min(insertans, min(deleteans, replaceans));

        

        }
        dp[i][j]= ans;



            }
        }

        return dp[0][0];





        
    }
    
    int minDistance(string word1, string word2) {
         //int n1 =  word1.size();
         //int n2 =  word2.size();

        //vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return  solveTab(word1 , word2);
        
    }
};