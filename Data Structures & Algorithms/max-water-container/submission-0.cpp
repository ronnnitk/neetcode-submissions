class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=INT_MIN;
        int j=n-1;
        for(int i=0;i<n;i++){
            int h=min(heights[i],heights[j]);
            int w=j-i;
            int area=h*w;
            maxarea =max(maxarea,area);
            while(heights[i]>heights[j]){
                j--;
                int h=min(heights[i],heights[j]);
                int w=j-i;
                int area=h*w;
                maxarea =max(maxarea,area);
            }
        }
        return maxarea;
    }
};
