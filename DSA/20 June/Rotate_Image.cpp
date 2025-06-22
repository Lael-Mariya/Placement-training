#include <vector>
#include <algorithm>
using std::vector;
using std::swap;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len=matrix.size();
        for (int r=0; r<len/2; ++r) {
            for (int c=0; c<len; ++c) {
                swap(matrix[r][c], matrix[len-r-1][c]);
            }
        }
        for (int i=0; i<len;++i) {
            for (int j=0; j<i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
