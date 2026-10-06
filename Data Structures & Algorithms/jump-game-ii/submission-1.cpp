class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
         return dfs(nums,0,dp);
    }
    int dfs(vector<int>& nums,int i,vector<int>& dp){
        int n=nums.size();
        if(i==n-1) return 0;

        if(nums[i]==0) return INT_MAX;

        if(dp[i]!=-1) return dp[i];

        int res=INT_MAX;
        int end=min(n-1,i+nums[i]);
        for(int j=i+1;j<=end;j++){
            int ans=dfs(nums,j,dp);
            if(ans!=INT_MAX){
            res=min(res,1+ans);
        }
        }
        
        return dp[i]=res;
    }
};
