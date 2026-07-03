class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths,
                                      string directions) {

        int n = positions.size();

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        // Sort indices by position
        sort(idx.begin(), idx.end(),
             [&](int a, int b) {
                 return positions[a] < positions[b];
             });

        stack<int> st; 

        for (int id : idx) {

            if (directions[id] == 'R') {
                st.push(id);
            } else {

                while (!st.empty() && healths[id] > 0) {

                    int r = st.top();

                    if (healths[r] < healths[id]) {
                        // Right robot dies
                        st.pop();
                        healths[id]--;
                        healths[r] = 0;
                    }
                    else if (healths[r] > healths[id]) {
                        // Left robot dies
                        healths[r]--;
                        healths[id] = 0;
                    }
                    else {
                        // Both die
                        st.pop();
                        healths[r] = 0;
                        healths[id] = 0;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0)
                ans.push_back(healths[i]);
        }

        return ans;
    }
};