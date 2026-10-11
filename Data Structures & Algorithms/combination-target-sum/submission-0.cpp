class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0,nums,target,curr,res);
        return res;
    }
    void backtrack(int i,vector<int>& nums, int target,vector<int>& curr,vector<vector<int>>& res){

        if(target==0){
            res.push_back(curr);
            return;
        }
        if(target<0 || i>=nums.size()){
            return;
        }
        curr.push_back(nums[i]);
        backtrack(i,nums,target-nums[i],curr,res);
        curr.pop_back();
        backtrack(i+1,nums,target,curr,res);
    }
};
