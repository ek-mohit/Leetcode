class Solution {
public:

/*int solve (vector<int>& days, vector<int>& costs, int index, vector<int>&dp){
    
    int n=  days.size();

    if(index >= n){
        return 0;

    }
    
    if (dp[index]!= -1) 
        return dp[index];

        

    int option1 = costs[0] +solve(days, costs, index+1, dp);

    int i;
    for (i=index ; i<n && days[i] < days[index]+7 ; i++);

    int option2 = costs[1] + solve(days, costs, i, dp);

    for (i=index ; i<n && days[i] < days[index]+30 ; i++);

    int option3 = costs[2] +solve(days, costs, i, dp);

    dp[index]= min (option1, min (option2 , option3 ));
    return dp[index];






}
*/
/*int solveTab (vector<int>& days, vector<int>& costs){
    int n=  days.size();
    vector<int> dp(n+1, INT_MAX);
   
   
    dp[n]= 0;



    for (int k= n-1 ; k>=0 ; k--){
    int option1 = costs[0] +dp[k+1];

    int i;
    for (i= k  ; i<n && days[i] < days[k]+7 ; i++);

    int option2 = costs[1] + dp[i];

    for (i= k ; i<n && days[i] < days[k]+30 ; i++);

    int option3 = costs[2] + dp[i];

    

    dp[k]= min (option1, min (option2 , option3 ));
    }
    return dp[0];
}
*/
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        //vector<int> dp(days.size()+1 , -1);
        int ans=0;
        queue<pair<int,int>> month;
        queue<pair<int,int>> week;

        for (int day: days){

            while (!week.empty() && week.front().first +7  <= day){
                week.pop();
            }

             while (!month.empty() && month.front().first +30  <= day){
                month.pop();
            }

            week.push(make_pair(day , ans+costs[1]));
            month.push(make_pair(day, ans+costs[2]));


            ans = min (ans+costs[0] , min(month.front().second, week.front().second));

           
        }
         return ans;
        
    }
};