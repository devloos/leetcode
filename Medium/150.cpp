class Solution {
 public:
  int evalRPN(vector<string> &tokens) {
    std::stack<int> s;
    for (auto c : tokens) {
      if (isOperator(c)) {
        int v1 = s.top();
        s.pop();
        int v2 = s.top();
        s.pop();

        if (c == "*") {
          s.push(v2 * v1);
        } else if (c == "-") {
          s.push(v2 - v1);
        } else if (c == "/") {
          s.push(v2 / v1);
        } else if (c == "+") {
          s.push(v2 + v1);
        }
      } else {
        s.push(stoi(c));
      }
    }

    return s.top();
  }

  bool isOperator(const std::string &c) {
    return c == "*" || c == "-" || c == "/" || c == "+";
  }
};
