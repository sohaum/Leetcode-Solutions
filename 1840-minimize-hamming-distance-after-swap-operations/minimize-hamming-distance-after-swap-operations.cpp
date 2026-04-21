class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);
        // 1. Group indices that can be swapped
        for (auto& swap : allowedSwaps) dsu.unite(swap[0], swap[1]);
        // 2. Group source values by their component root
        unordered_map<int, unordered_map<int, int>> components;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            components[root][source[i]]++;
        }
        int hammingDistance = 0;
        // 3. For each target[i], check if its value exists in its component's source pool
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            int val = target[i];
            if (components[root][val] > 0) components[root][val]--;
            else hammingDistance++;
        }
        return hammingDistance;
    }
};