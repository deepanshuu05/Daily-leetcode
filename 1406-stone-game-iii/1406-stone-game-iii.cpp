class Solution {
public:
int solve(int i,vector<int>&stone,vector<int>&dp) {
    if(i>=stone.size())
    return 0;
    if(dp[i]!=INT_MIN)
    return dp[i];
    int take=0;
    dp[i]=INT_MIN;
    for(int k=0;k<3 && i+k<stone.size();k++ ) {
        take+=stone[i+k];
        dp[i]=max(dp[i],take-solve(i+k+1,stone,dp));
    }
    return dp[i];

}
    string stoneGameIII(vector<int>& stoneValue) {
        int n= stoneValue.size();
        vector<int>dp(n,INT_MIN);
        int ans=solve(0,stoneValue,dp);

        if(ans>0)
        return "Alice";
        if(ans<0)
        return "Bob";
        return"Tie";

        
    }
};