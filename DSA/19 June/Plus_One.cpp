// Time Complexity: O(n)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for (int i=n-1; i>=0; --i) {
            if(digits[i]==9){
                digits[i]=0; // doesn't return condition
            }
            else{
                digits[i]++;
                return digits;
            }
        }
        digits.insert(digits.begin(),1);   // if the for loop didn't return digits, all the numbers were 9, as the if condition doesn't return digits
        return digits;
    }
};
