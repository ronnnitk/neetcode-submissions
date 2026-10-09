class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        int case1=helper(nums,n-2,0,dp1);
        int case2=helper(nums,n-1,1,dp2);

        return max(case1,case2);
    }
    int helper(vector<int>& nums ,int ind,int start, vector<int>& dp){
        if(ind==start) return nums[start];
        if(ind<start) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int pick=nums[ind]+ helper(nums,ind-2,start,dp);
        int not_pick=helper(nums,ind-1,start,dp);

        return dp[ind]=max(pick,not_pick);
    }
};

