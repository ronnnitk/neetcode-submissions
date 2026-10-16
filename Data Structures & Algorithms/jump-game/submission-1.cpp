class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, n, dp);
    }

    bool helper(int i, vector<int>& nums, int n, vector<int>& dp) {
        if (i >= n - 1) return true;

        if (dp[i] != -1) return dp[i];

        for (int j = 1; j <= nums[i]; j++) {
            if (helper(i + j, nums, n, dp)) {
                return dp[i] = 1;
            }
        }

        return dp[i] = 0;
    }
};