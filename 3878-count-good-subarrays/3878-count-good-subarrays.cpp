class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, -1);
        vector<int> st;

        // Previous invalid position
        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                   nums[st.back()] < nums[i] &&
                   (nums[st.back()] | nums[i]) == nums[i]) {
                st.pop_back();
            }

            if (!st.empty())
                left[i] = st.back();

            st.push_back(i);
        }

        vector<int> right(n, n);
        st.clear();

        // Next invalid position
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&
                   (nums[st.back()] | nums[i]) == nums[i]) {
                st.pop_back();
            }

            if (!st.empty())
                right[i] = st.back();

            st.push_back(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * (i - left[i]) * (right[i] - i);
        }

        return ans;
    }
};