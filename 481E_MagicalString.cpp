#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static constexpr char one = '1';
    static constexpr char two = '2';
    int magicalString(int n) {
        int ret = 1;
        if(n <= 3) {
            return 1;
        }

        vector<char> s(n, 0);
        s[0] = one;
        s[1] = two;
        s[2] = two;
        int left = 2, right = 3;
        bool useOne = true;
        while(right < n) {
            if(useOne) {
                // 用'1'填充
                int cnt = s[left] - '0';
                while(cnt-- && right < n) {
                    s[right] = one;
                    ++ret;
                    ++right;
                }
                useOne = false;
                ++left;
            } else {
                // 用'2'填充
                int cnt = s[left] - '0';
                while (cnt-- && right < n) {
                    s[right] = two;
                    ++right;
                }
                useOne = true;
                ++left;
            }
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    int n = 4;
    Solution slt;
    auto ret = slt.magicalString(n);
    cout << "result:" << ret << "\r\n";
    return 0;
}