class Solution {
     vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
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
        curr.push_back(nums[i]);
        backtrack(i,nums,target-nums[i],curr);
        curr.pop_back();
        backtrack(i+1,nums,target,curr);
    }
};
