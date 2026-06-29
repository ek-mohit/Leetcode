class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py])
            swap(px, py);

        parent[py] = px;

        if (rank[px] == rank[py])
            rank[px]++;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        parent.resize(n);
        rank.assign(n, 0);

        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j])
                    Union(i, j);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                ans++;
        }

        return ans;
    }
};