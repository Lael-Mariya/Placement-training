class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n+1, 0);  
        vector<int> trusts(n+1, 0);   
        for (const auto& relation:trust){
            int truster =relation[0];
            int trustee =relation[1];
            trusts[truster]++;
            trusted[trustee]++;
        }
        for (int i=1; i<=n; ++i){
            if (trusts[i]==0 && trusted[i]==n-1) {
                return i;
            }
        }
        return -1;
    }
};

