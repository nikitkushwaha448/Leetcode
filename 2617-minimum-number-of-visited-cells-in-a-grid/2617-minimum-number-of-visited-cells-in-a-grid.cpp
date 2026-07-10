class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        const int INF = 1e9;

        vector<vector<int>> dp(m, vector<int>(n, INF));

        using T = tuple<int,int>;   // {dp, farthest}

        vector<priority_queue<T, vector<T>, greater<T>>> row(m);
        vector<priority_queue<T, vector<T>, greater<T>>> col(n);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                while(!row[i].empty() && get<1>(row[i].top()) < j)
                    row[i].pop();

                while(!col[j].empty() && get<1>(col[j].top()) < i)
                    col[j].pop();

                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    if(!row[i].empty())
                        dp[i][j] = min(dp[i][j], get<0>(row[i].top()) + 1);

                    if(!col[j].empty())
                        dp[i][j] = min(dp[i][j], get<0>(col[j].top()) + 1);
                }

                if(dp[i][j] != INF) {
                    row[i].push({dp[i][j], j + grid[i][j]});
                    col[j].push({dp[i][j], i + grid[i][j]});
                }
            }
        }

        return dp[m-1][n-1] == INF ? -1 : dp[m-1][n-1];
    }
};