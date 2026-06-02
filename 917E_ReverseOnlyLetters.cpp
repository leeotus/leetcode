#include <ctype.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        if(s.empty()) {
            return s;
        }
        int left = 0, right = s.size() - 1;
        while(left < right) {
            while (left < right && !((s[left] >= 'a' && s[left] <= 'z') ||
                   (s[left] >= 'A' && s[left] <= 'Z'))) {
                ++left;
            }
            while (right > left && !((s[right] >= 'a' && s[right] <= 'z') ||
                   (s[right] >= 'A' && s[right] <= 'Z'))) {
                --right;
            }
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            
            left += 1;
            right -= 1;
        }
        return s;
    }
};

int main(int argc, char **argv) {
    string s = "a-bC-dEf-ghIj";
    Solution slt;
    auto out = slt.reverseOnlyLetters(s);
    cout << "string:" << s << "\r\n";
    cout << "result:" << out << "\r\n";
    return 0;
}