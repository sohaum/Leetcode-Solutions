class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Store obstacles
        unordered_set<long long> st;
        for (auto &o:obstacles) {
            long long key=((long long)o[0]<<32) | (o[1] & 0xffffffff);
            st.insert(key);
        }
        // Directions: North, East, South, West
        vector<int>dx = {0, 1, 0, -1};
        vector<int>dy = {1, 0, -1, 0};
        int dir=0; // start facing North
        int x=0, y=0;
        int maxDist=0;
        for (int cmd:commands) {
            if (cmd==-1) {
                dir=(dir+1)%4; // turn right
            } else if (cmd==-2) {
                dir=(dir+3)%4; // turn left
            } else {
                // move step by step
                for (int step=0; step<cmd; step++) {
                    int nx=x+dx[dir];
                    int ny=y+dy[dir];
                    long long key=((long long)nx<<32) | (ny & 0xffffffff);
                    if (st.count(key)) break; // obstacle
                    x=nx;
                    y=ny;
                    maxDist=max(maxDist,x*x+y*y);
                }
            }
        }
        return maxDist;
    }
};