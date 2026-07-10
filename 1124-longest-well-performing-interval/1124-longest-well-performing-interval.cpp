class Solution {
public:
    int longestWPI(vector<int>& hours) {

        unordered_map<int,int> mp;

        int sum = 0;
        int ans = 0;

        for(int i=0;i<hours.size();i++){

            if(hours[i] > 8)
                sum++;
            else
                sum--;

            if(sum > 0)
                ans = i + 1;
            else{

                if(mp.count(sum-1))
                    ans = max(ans, i - mp[sum-1]);
            }

            if(!mp.count(sum))
                mp[sum] = i;
        }

        return ans;
    }
};