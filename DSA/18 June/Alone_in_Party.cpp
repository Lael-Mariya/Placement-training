class Solution {
  public:
    int findSingle(vector<int> &arr) {
        int len= arr.size();
        int xr=0;
        for(int i=0; i<len; i++){
            xr=xr^arr[i];
        }
        return xr;
    }
};
