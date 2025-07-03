// The top element of the stack should have the opening bracket of the next closing bracket we have traversed through. This way we have found a pair and we pop out the top element.
// Time Complexity: O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                if ((st.top() == '(' && c == ')') ||
                    (st.top() == '[' && c == ']') ||
                    (st.top() == '{' && c == '}')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
