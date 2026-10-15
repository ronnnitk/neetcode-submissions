class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsub=nums[0],cursum=0;
        for(int i : nums){
            if(cursum<0) cursum=0;
            cursum +=i;
            maxsub=max(maxsub,cursum);
        }
        return maxsub;
    }
};
