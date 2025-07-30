class Solution {
 public:
  int calPoints(vector<string>& operations) {
    vector<int> scores;

    for (const string& opr : operations)
      if (opr == "+")
        scores.push_back(scores.back() + scores[scores.size() - 2]);
      else if (opr == "D")
        scores.push_back(scores.back() * 2);
      else if (opr == "C")
        scores.pop_back();
      else
        scores.push_back(stoi(opr));

    return accumulate(scores.begin(), scores.end(), 0);
  }
};
