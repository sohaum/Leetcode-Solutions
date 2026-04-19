class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0, j=0, count=0;
        while (i<n1 && j<n2) {
            if(nums1[i]<=nums2[j]) {
                count=max(count,j-i);
                j++;
            } else {
                i++;
                if(i>j) j=i;
            }
        }
        return count;
    }
};