class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return -1;
        // abs(i-j) + abs(j-k) + abs(k-i) = (j-i) + (k-j) + (k-i) = 2(k-i)
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++) m[nums[i]].push_back(i);
        int t=INT_MAX;
        for(auto const& [val,idx]:m) {
            if(idx.size()>=3) {
                for(int j=0;j<=idx.size()-3;j++) {
                    t=min(t, 2*( idx[j+2]-idx[j] ));
                }
            }
        }
        if(t==INT_MAX) return -1;
        else return t;
    }
};