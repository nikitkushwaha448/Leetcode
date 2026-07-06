class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int,int>> dq; 
        int ans = INT_MIN;

        for (auto &p : points) {
            int x = p[0];
            int y = p[1];

            // Remove points farther than k
            while (!dq.empty() && x - dq.front().first > k)
                dq.pop_front();

            
            if (!dq.empty())
                ans = max(ans, dq.front().second + x + y);

            int value = y - x;

            // Maintain decreasing order of (y-x)
            while (!dq.empty() && dq.back().second <= value)
                dq.pop_back();

            dq.push_back({x, value});
        }

        return ans;
    }
};