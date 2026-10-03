class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    rob(nums) {
        let n=nums.length;
        let dp= new Array(n).fill(-1);
        return this.helper(nums,n-1,dp);
    }
    helper(nums,ind,dp){
        if(ind==0) return nums[0];
        if(ind < 0) return 0;

        if(dp[ind]!=-1) return dp[ind];

        let pick=nums[ind]+ this.helper(nums,ind-2,dp);
        let notpick=this.helper(nums,ind-1,dp);

        return dp[ind]=Math.max(pick,notpick);
    }
}
