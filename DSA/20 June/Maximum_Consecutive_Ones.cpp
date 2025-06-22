#include <vector>
#include <algorithm>
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currentCount=0, maxCount=0;
        for (int value:nums) {
            if (value==1) {
                ++currentCount;
            } else {
                maxCount=max(maxCount, currentCount);
                currentCount = 0;
            }
        }
        return max(maxCount, currentCount);
    }
};
