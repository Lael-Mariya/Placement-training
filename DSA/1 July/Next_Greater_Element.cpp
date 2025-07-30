class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> ng;
        vector<int> res;
        for(int num:nums2) {
            while(!st.empty()&&st.top()<num) {
                ng[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        for(int num:nums1) {
            res.push_back(ng.count(num)?ng[num]:-1);
        }
        return res;
    }
};
