#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 拿后面的较大值和前面的较小值交换, 从交换的位置往后做排序
    int nextGreaterElement(int n) {
        // s= "hello world"
        //      前 - 后
        string s{};
        while(n != 0) {
            char c = n % 10 + '0';
            s = string{c} + s;
            n = n / 10;
        }
        int large = s.size() - 1;
        int small{0};
        while (large - 1 >= 0 && (s[large] - '0') <= (s[large - 1] - '0')) {
            --large;
        }
        if(large == 0) {
            // 没有更大值了
            return -1;
        }
        small = large - 1;  // 找到前面的较小值了
        // 跟后面的较大值交换
        int k = large;
        while (k + 1 < s.size() && (s[small] - '0') < (s[k + 1] - '0')) {
            ++k;
        }
        // 找到前后要互相交换的两个值了
        char tmp = s[k];
        s[k] = s[small];
        s[small] = tmp;
        
        // reverse 从index=large之后的位置
        reverse(s.begin() + large, s.end());

        // 从字符串转换为数字，还需要判断在32位整数以内
        int ret{0};
        if(s.size() == 10) {
            if(s >= maxNum) {
                return -1;
            }
        }
        for(auto n : s) {
            ret = ret * 10 + (n - '0');
        }
        return ret;
    }
private:
    string maxNum{"2147483648"};
};

int main(int argc, char **argv) {
    int n = 2147483486;
    Solution slt;
    auto ret = slt.nextGreaterElement(n);
    cout << "result:" << ret << "\r\n";
    return 0;
}