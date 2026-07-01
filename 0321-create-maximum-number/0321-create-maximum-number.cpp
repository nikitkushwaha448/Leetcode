class Solution {
public:

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int remove = nums.size() - k;

        for (int num : nums) {

            while (!st.empty() && remove > 0 && st.back() < num) {
                st.pop_back();
                remove--;
            }

            st.push_back(num);
        }

        
        st.resize(k);

        return st;
    }

    // Compare remaining parts of two arrays
    bool greater(vector<int>& a, int i, vector<int>& b, int j) {

        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }

        if (j == b.size()) return true;
        if (i == a.size()) return false;

        return a[i] > b[j];
    }

    // Greedily merge two maximum subsequences
    vector<int> merge(vector<int>& a, vector<int>& b) {

        vector<int> ans;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {

            if (greater(a, i, b, j))
                ans.push_back(a[i++]);
            else
                ans.push_back(b[j++]);
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> ans;

        int m = nums1.size();
        int n = nums2.size();

        for (int i = max(0, k - n); i <= min(k, m); i++) {

            vector<int> first = maxSubsequence(nums1, i);
            vector<int> second = maxSubsequence(nums2, k - i);

            vector<int> candidate = merge(first, second);

            if (ans.empty() || greater(candidate, 0, ans, 0))
                ans = candidate;
        }

        return ans;
    }
};