class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        long long perim = 4LL * side;
        // Convert each point to 1D perimeter position
        auto toPos = [&](int x, int y) -> long long {
            if (y == 0) return x;               // bottom
            if (x == side) return side + y;         // right
            if (y == side) return 2LL*side + (side - x); // top
            return 3LL*side + (side - y);                  // left
        };
        int n = points.size();
        vector<long long> pos(n);
        for (int i = 0; i < n; i++)
            pos[i] = toPos(points[i][0], points[i][1]);
        
        sort(pos.begin(), pos.end());
        
        // Check if min distance 'd' is achievable
        auto check = [&](long long d) -> bool {
            // Try each point as the starting point
            for (int start = 0; start < n; start++) {
                // Greedy: pick points with gap >= d
                int count = 1;
                long long cur = pos[start];
                long long first = pos[start];
                int idx = start;
                while (count < k) {
                    // Binary search for next point >= cur + d
                    // Search in [start, start+n) using doubled array
                    int lo = idx + 1, hi = start + n - 1, nxt = -1;
                    while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        long long p = pos[mid % n] + (mid >= n ? perim : 0);
                        if (p - cur >= d) {
                            nxt = mid;
                            hi = mid - 1;
                        } else lo = mid + 1;
                    }
                    if (nxt == -1) break;
                    idx = nxt;
                    cur = pos[idx % n] + (idx >= n ? perim : 0);
                    count++;
                }
                if (count == k) {
                    // Check wrap-around: gap from last back to first
                    long long wrap = (first + perim) - cur;
                    if (wrap >= d) return true;
                }
            }
            return false;
        };
        // Binary search on answer
        long long lo = 1, hi = 2LL * side, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};