#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for (const string& token : tokens) {
            if (token.size()>1 || isdigit(token[0])) {
                num.push(stoi(token));
            } else {
                int operand2=num.top();
                num.pop();
                int operand1=num.top();
                num.pop();
                switch (token[0]) {
                    case '+':
                        num.push(operand1+operand2);
                        break;
                    case '-':
                        num.push(operand1-operand2);
                        break;
                    case '*':
                        num.push(operand1*operand2);
                        break;
                    case '/':
                        num.push(operand1/operand2);
                        break;
                }
            }
        }
        return num.top();
    }
};
