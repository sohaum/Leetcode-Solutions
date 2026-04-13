class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int x=INT_MAX;
        for(int i=0;i<n;i++) {
            if(nums[i]==target) {
                x=min(x,abs(i-start));
            }
        }
        return x;
    }
};