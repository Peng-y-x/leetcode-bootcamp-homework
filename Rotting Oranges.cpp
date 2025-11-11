class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0, minute = 0;
        
        // 初始化：统计新鲜橙数量，并把腐烂橙加入队列
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i,j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        
        if (fresh == 0) return 0; // 没有新鲜橙
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while (!q.empty()) {
            int s = q.size();
            bool hasRot = false;
            for (int i = 0; i < s; i++) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                        hasRot = true;
                    }
                }
            }
            if (hasRot) minute++;
        }
        
        return fresh == 0 ? minute : -1;
    }
};
