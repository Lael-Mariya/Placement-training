// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
// If the town judge exists, then:
// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.
// Time Complexity: 0(n+m)
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trustByOthers(N+1, 0); // Counts the number of people who trust 'i'
        vector<int> trustsOthers(N+1, 0);  // Counts the number of people 'i' trusts
        for (const auto& relation:trust) {
            int truster=relation[0]; // Person who trusts
            int trustee=relation[1]; // Person being trusted
            trustsOthers[truster]++;  // Increment trust count for the truster
            trustByOthers[trustee]++; // Increment count of being trusted for the trustee
        }
        for (int i=1; i<=N; ++i) {
            if (trustsOthers[i]==0 && trustByOthers[i]==N-1) {  // The judge is the person who trusts no one else (trustsOthers[i]==0)
            // and is trusted by everyone else (trustByOthers[i]==N-1)
                return i;
            }
        }
        return -1;
    }
};
