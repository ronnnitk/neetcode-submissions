class Solution {
     vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> curr;
        sort(nums.begin(),nums.end());
        backtrack(0,nums,target,curr);
        return res;
    }
    void backtrack(int i,vector<int>& nums, int target,vector<int>& curr){

        if(target==0){
            res.push_back(curr);
            return;
        }
        if(target<0 || i>=nums.size()){
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]) continue;

            if(nums[j]>target) break;

            curr.push_back(nums[j]);
            backtrack(j+1,nums,target-nums[j],curr);
            curr.pop_back();
        }
    }
};
