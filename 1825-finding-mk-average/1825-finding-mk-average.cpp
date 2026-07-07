class MKAverage {
public:
    int m, k;
    queue<int> q;

    multiset<int> low, mid, high;
    long long sumMid = 0;

    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void balance() {
        while (low.size() > k) {
            auto it = prev(low.end());
            mid.insert(*it);
            sumMid += *it;
            low.erase(it);
        }

        while (low.size() < k && !mid.empty()) {
            auto it = mid.begin();
            low.insert(*it);
            sumMid -= *it;
            mid.erase(it);
        }

        while (high.size() > k) {
            auto it = high.begin();
            mid.insert(*it);
            sumMid += *it;
            high.erase(it);
        }

        while (high.size() < k && !mid.empty()) {
            auto it = prev(mid.end());
            high.insert(*it);
            sumMid -= *it;
            mid.erase(it);
        }
    }

    void addElement(int num) {
        if (low.empty() || num <= *prev(low.end()))
            low.insert(num);
        else if (high.empty() || num < *high.begin()) {
            mid.insert(num);
            sumMid += num;
        }
        else
            high.insert(num);

        if (q.size() == m) {
            int x = q.front();
            q.pop();

            auto it = low.find(x);
            if (it != low.end()) {
                low.erase(it);
            }
            else if ((it = mid.find(x)) != mid.end()) {
                sumMid -= x;
                mid.erase(it);
            }
            else {
                it = high.find(x);
                high.erase(it);
            }
        }

        q.push(num);
        balance();
    }

    int calculateMKAverage() {
        if (q.size() < m)
            return -1;

        return sumMid / (m - 2 * k);
    }
};