// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. 
// If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
// you can't assign the same cookie again.
// Perform greedy algorithm, basically if g[i]=1, we will check for s[j]>=1 and fortunately 1 is present in s then assign 1 cookie to that child with the greed factor 1, we don't have to go for something bigger than 1
// Because of the above reason, we will sort both the arrays to make it easier.
// Time Complexity: O(n1 log n1 + n2 log n2 + n2)
class Solution {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookies){   
        int n1=children.size();
        int n2=cookies.size();
        sort(children.begin(),children.end());
        sort(cookies.begin(),cookies.end());
        int i=0; // pointer for children
        int j=0; // pointer for cookie
        int count=0;
        while (i<n1 && j<n2){
            if(children[i]<=cookies[j]){  // checking if the cookie is sufficient to satisfy the greed factor, g[i]<=s[j]
                count++;
                i++;
                j++;
            } 
            else{
                j++; // we check for the next cookie as the last one wasn't sufficient enough to satisfy the greed factor
            }
        }
        return count;
    }
};
