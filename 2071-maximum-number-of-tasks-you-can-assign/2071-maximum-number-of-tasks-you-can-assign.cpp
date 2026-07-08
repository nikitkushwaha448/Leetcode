class Solution {
public:
    bool canAssign(vector<int>& tasks, vector<int>& workers,
                   int pills, int strength, int k) {

        deque<int> dq;
        int j = 0;

        for (int i = workers.size() - k; i < workers.size(); i++) {

            while (j < k && tasks[j] <= workers[i] + strength) {
                dq.push_back(tasks[j]);
                j++;
            }

            if (dq.empty()) return false;

            if (dq.front() <= workers[i]) {
                dq.pop_front();
            } else {
                if (pills == 0) return false;
                pills--;
                dq.pop_back();
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers,
                      int pills, int strength) {

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0;
        int high = min(tasks.size(), workers.size());

        while (low < high) {
            int mid = (low + high + 1) / 2;

            if (canAssign(tasks, workers, pills, strength, mid))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};