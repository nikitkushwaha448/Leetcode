class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] > b[0];
             });

        long long profit = 0;
        long long ans = 0;

        unordered_set<int> categories;
        vector<int> duplicate;

        for (int i = 0; i < k; i++) {
            profit += items[i][0];

            if (categories.count(items[i][1]))
                duplicate.push_back(items[i][0]);
            else
                categories.insert(items[i][1]);
        }

        ans = profit + 1LL * categories.size() * categories.size();

        for (int i = k; i < items.size() && !duplicate.empty(); i++) {

            if (categories.count(items[i][1]))
                continue;

            profit -= duplicate.back();
            duplicate.pop_back();

            profit += items[i][0];
            categories.insert(items[i][1]);

            long long elegance =
                profit +
                1LL * (long long)categories.size() * (long long)categories.size();

            ans = std::max(ans, elegance);
        }

        return ans;
    }
};