#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string reverseWords(string s) {
        string ret{};
        int prev = 0, front = 0;
        bool wordFound = false;
        while (front < s.size()) {
            if (prev < s.size() && s[prev] == ' ') {
                while (s[prev] == ' ') {
                    prev++;
                }
                front = prev;
                if (!ret.empty() && front < s.size()) {
                    ret = string{' '} + ret;
                }
            }

            if (!wordFound) {
                while (front < s.size() && s[front] != ' ') {
                    ++front;
                }
                if (front < s.size() && s[front] == ' ') {
                    wordFound = true;
                }
            }
            if (wordFound) {
                // found a word
                string sub = s.substr(prev, front - prev);
                ret = sub + ret;
                prev = front;
                // front++;
                wordFound = false;
            }
        }
        if(front > prev) {
            string sub = s.substr(prev, front - prev);
            ret = sub + ret;
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    string in{"the sky is blue"};
    Solution slt;
    string ret = slt.reverseWords(in);
    cout << "result:" << ret << "\r\n";
    return 0;
}