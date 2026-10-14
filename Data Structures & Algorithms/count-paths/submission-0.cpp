class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return help(0,0,dp);
    }
    int help(int i ,int j, vector<vector<int>>& dp){
        if(i>=dp.size() || j>=dp[0].size()) return 0;

        if(i==dp.size()-1 && j==dp[0].size()-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];
        int down=help(i+1,j,dp);
        int right=help(i,j+1,dp);

        return dp[i][j]=down+right;
    }
};
