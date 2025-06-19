#include <vector>
#include <algorithm>
class Solution {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookies) {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());
        int numChildren=children.size();
        int numCookies=cookies.size();
        int contentChildren=0;
        for (int childIndex=0, cookieIndex=0; childIndex<numChildren; ++childIndex) {
            while (cookieIndex<numCookies && cookies[cookieIndex]<children[childIndex]) {
                ++cookieIndex;
            }
            if (cookieIndex<numCookies) {
                ++contentChildren;
                ++cookieIndex;
            } 
            else{
                break;
            }
        }
        return contentChildren;
    }
};
