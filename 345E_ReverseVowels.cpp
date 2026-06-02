#include <ctype.h>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        if(s.size() <= 1) {
            return s;
        }
        int left = 0, right = s.size() - 1;
        while(right > left) {
            while(left < s.size() && vowels.find((char)tolower(s[left])) == vowels.end()) {
                ++left;
            }
            while(right >= 0 && vowels.find((char)tolower(s[right])) == vowels.end()) {
                --right;
            }
            if(right > left) {
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                ++left;
                --right;
            }
        }
        return s;
    }
private:
    set<char> vowels{'a', 'e', 'i', 'o', 'u'};
};

int main(int argc, char **argv) {
    Solution slt;
    string s = "leetcode";
    auto ret = slt.reverseVowels(s);
    cout << "result:" << ret << "\r\n";
    return 0;
}