class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int maxDist=0;
        // Compare the first house with everything from the end moving backwards
        for (int i=n-1;i>=0;i--) {
            if (colors[i]!=colors[0]) {
                maxDist=max(maxDist, i);
                break;
            }
        }
        // Compare the last house with everything from the start moving forwards
        for (int i=0;i<n;i++) {
            if (colors[i]!=colors[n - 1]) {
                maxDist=max(maxDist,(n-1)-i);
                break;
            }
        }
        return maxDist;
    }
};