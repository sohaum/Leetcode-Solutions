class Solution {
public:
    void twoSum(int target,vector<int>& nums,int i, int j,vector<vector<int>>& result) {
        while(i<j) {
            if ((nums[i]+nums[j])<target) i++;
            else if ((nums[i]+nums[j])>target) j--;
            else { // (nums[i]+nums[j]==target
                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;
                result.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> result;
        if (n<3) return {};
        // Sort
        sort(nums.begin(),nums.end());
        // Fix one element n1
        for (int i=0;i<n;i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int n1=nums[i];
            int target=-n1;
            twoSum(target,nums,i+1,n-1,result);
        }
        return result;
    }
};