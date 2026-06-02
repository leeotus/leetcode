#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    Solution() {
        phone[2] = {'a', 'b', 'c'};
        phone[3] = {'d', 'e', 'f'};
        phone[4] = {'g', 'h', 'i'};
        phone[5] = {'j', 'k', 'l'};
        phone[6] = {'m', 'n', 'o'};
        phone[7] = {'p', 'q', 'r', 's'};
        phone[8] = {'t', 'u', 'v'};
        phone[9] = {'w', 'x', 'y', 'z'};
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return res;
        }
        string cur{};
        backtracking(digits, 0, cur);
        return res;
    }

  private:
    vector<string> res{};
    unordered_map<int, vector<char>> phone;

    void backtracking(string &digits, int startIndex, string &cur) {
        if (cur.size() == digits.size()) {
            res.push_back(cur);
            return;
        }
        if (startIndex >= digits.size()) {
            return;
        }

        vector<char> cv = phone[digits[startIndex] - '0'];
        for (int i = 0; i < cv.size(); ++i) {
            cur.push_back(cv[i]);
            backtracking(digits, startIndex + 1, cur);
            cur.pop_back();
        }
    }
};

int main(int argc, char **argv) {
    string digits = "23";
    Solution slt;
    auto res = slt.letterCombinations(digits);
    for (auto s : res) {
        cout << s << " ";
    }
    cout << "\r\n";
    return 0;
}