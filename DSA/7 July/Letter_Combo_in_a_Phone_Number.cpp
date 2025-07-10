class Solution{
public:
    vector<string> letterCombinations(string digits){
        if(digits.empty())return{};
        vector<string> digitToChars={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> combinations={""};
        for(char digit:digits){
            string chars=digitToChars[digit-'2'];
            vector<string> tempCombinations;
            for(string &combination:combinations){
                for(char ch:chars){
                    tempCombinations.push_back(combination+ch);
                }
            }
            combinations=move(tempCombinations);
        }
        return combinations;
    }
};
