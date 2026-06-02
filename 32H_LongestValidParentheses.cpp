#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
            }
        }
    }
};

int main(int argc, char **argv) {
    string s = "(()";
    return 0;
}