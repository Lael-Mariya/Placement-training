// You are given an integer n. Your task is to reverse the digits, ensuring that the reversed number has no leading zeroes.
// Time Complexity: O(log n)
class Solution {
public:
    int reverseDigits(int n) {
        int rev =0;
        int rem;
        while (n>0) {
            rem=n%10;
            rev =rev* 10 + rem;
            n = n/10;
        }
        return rev;
    }
};
