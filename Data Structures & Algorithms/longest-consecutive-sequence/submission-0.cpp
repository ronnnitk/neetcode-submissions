class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=0;
        unordered_set<int> numset(nums.begin(),nums.end());

        for(int num : numset){
            if(numset.find(num-1)==numset.end()){
                int length=1;
                while(numset.find(num+length)!=numset.end()){ length++;}
                count=max(count,length);
            }
        }
        return count;
    }
};
