class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();

        vector<int> nextHigher(n,-1);
        vector<int> nextLower(n, -1);

        vector<int> idx(n);
        iota(idx.begin(),idx.end(),0);

        // nextHigher
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (arr[a] == arr[b]) return a < b;
            return arr[a] < arr[b];
        });

        stack<int> st;

        for(int i :idx){
            while(!st.empty() && i> st.top()){
                nextHigher[st.top()] = i;
                st.pop(); 
            }
            st.push(i);
        }

        // nextLower
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (arr[a] == arr[b]) return a < b;
            return arr[a] > arr[b];
        });

        while (!st.empty()) st.pop();

        for (int i : idx) {
            while (!st.empty() && i > st.top()) {
                nextLower[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<bool> odd(n,false), even(n,false);

        odd[n-1] = true;
        even[n-1] = true;

        int ans = 1;

        for(int i = n-2; i>=0; i--){
            if(nextHigher[i] != -1)
            odd[i] =even[nextHigher[i]];

            if(nextLower[i] != -1)
            even[i] = odd[nextLower[i]];
            
            if(odd[i]) ans++;
        
        }
        return ans;

    }
};