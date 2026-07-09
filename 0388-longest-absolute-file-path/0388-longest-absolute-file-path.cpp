class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> st(1, 0); 
        int ans = 0;

        stringstream ss(input);
        string line;

        while (getline(ss, line, '\n')) {
            int depth = 0;

            while (depth < line.size() && line[depth] == '\t')
                depth++;

            string name = line.substr(depth);

            while (st.size() > depth + 1)
                st.pop_back();

            if (name.find('.') != string::npos) {
                ans = max(ans, st.back() + (int)name.size());
            } else {
                st.push_back(st.back() + name.size() + 1);
            }
        }

        return ans;
    }
};