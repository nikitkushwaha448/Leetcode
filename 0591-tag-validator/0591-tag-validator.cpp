class Solution {
public:
    bool validTag(string &tag) {
        if (tag.empty() || tag.size() > 9)
            return false;

        for (char c : tag) {
            if (c < 'A' || c > 'Z')
                return false;
        }

        return true;
    }

    bool isValid(string code) {
        stack<string> st;
        int n = code.size();

        for (int i = 0; i < n;) {

            
            if (i > 0 && st.empty())
                return false;

            
            if (i + 9 <= n && code.substr(i, 9) == "<![CDATA[") {

                if (st.empty())
                    return false;

                int j = code.find("]]>", i + 9);

                if (j == string::npos)
                    return false;

                i = j + 3;
            }

            // End Tag
            else if (i + 2 <= n && code.substr(i, 2) == "</") {

                int j = code.find('>', i);

                if (j == string::npos)
                    return false;

                string tag = code.substr(i + 2, j - i - 2);

                if (!validTag(tag))
                    return false;

                if (st.empty() || st.top() != tag)
                    return false;

                st.pop();
                i = j + 1;

                
                if (st.empty() && i != n)
                    return false;
            }

            // Start Tag
            else if (code[i] == '<') {

                int j = code.find('>', i);

                if (j == string::npos)
                    return false;

                string tag = code.substr(i + 1, j - i - 1);

                if (!validTag(tag))
                    return false;

                st.push(tag);
                i = j + 1;
            }

            
            else {

                if (st.empty())
                    return false;

                i++;
            }
        }

        return st.empty();
    }
};