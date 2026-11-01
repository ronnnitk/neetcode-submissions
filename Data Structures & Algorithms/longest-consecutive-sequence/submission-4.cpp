class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len=1;
        int count=1;
        if(nums.size()==0) return 0;
        unordered_set<int> set(nums.begin(),nums.end());
        for(int num : set){
            if(set.find(num-1)==set.end()) {
                len=1;
                while(set.find(num+len)!=set.end()){
                    len++;
                }
                count=max(count,len);
            }
        }
        return count;
    }
};
