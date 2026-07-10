class DinnerPlates {
public:
    int cap;

    vector<stack<int>> stacks;

    priority_queue<int, vector<int>, greater<int>> available;

    DinnerPlates(int capacity) {
        cap = capacity;
    }

    void push(int val) {

        while (!available.empty()) {

            int idx = available.top();

            if (idx >= stacks.size() || stacks[idx].size() == cap)
                available.pop();
            else
                break;
        }

        if (available.empty()) {

            stack<int> st;
            st.push(val);

            stacks.push_back(st);

            if (cap > 1)
                available.push(stacks.size() - 1);
        }
        else {

            int idx = available.top();

            stacks[idx].push(val);

            if (stacks[idx].size() == cap)
                available.pop();
        }
    }

    int pop() {

        while (!stacks.empty() && stacks.back().empty())
            stacks.pop_back();

        if (stacks.empty())
            return -1;

        int val = stacks.back().top();

        stacks.back().pop();

        available.push(stacks.size() - 1);

        while (!stacks.empty() && stacks.back().empty())
            stacks.pop_back();

        return val;
    }

    int popAtStack(int index) {

        if (index >= stacks.size())
            return -1;

        if (stacks[index].empty())
            return -1;

        int val = stacks[index].top();

        stacks[index].pop();

        available.push(index);

        return val;
    }
};