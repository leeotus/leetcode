#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string reverseByType(string s) {
        if (s.empty()) {
            return s;
        }
        int leftc = 0, rightc = s.size() - 1;
        int lefts = 0, rights = s.size() - 1;
        for (; leftc < rightc; ++leftc) {
            if (isalpha(s[leftc])) {
                while (!isalpha(s[rightc])) {
                    rightc -= 1;
                }
                swap(s[leftc], s[rightc--]);
            }
        }
        for (; lefts < rights; ++lefts) {
            if (!isalnum(s[lefts])) {
                while (isalpha(s[rights])) {
                    rights -= 1;
                }
                swap(s[lefts], s[rights--]);
            }
        }
        return s;
    }
};

int main(int argc, char **argv) {
    Solution s;
    string str = ")ebc#da@f(";
    string o = s.reverseByType(str);
    cout << o << "\r\n";
}