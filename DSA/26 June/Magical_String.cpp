class Solution {
public:
    int magicalString(int n){
        vector<int> magical_seq = {1, 2, 2};
        for (int i=2; magical_seq.size()<n; ++i) {
            int last=magical_seq.back();
            int next=3-last;
            for (int count=0; count<magical_seq[i]; ++count) {
                magical_seq.emplace_back(next);
            }
        }
        return count(magical_seq.begin(), magical_seq.begin() + n, 1);
        
    }
};
