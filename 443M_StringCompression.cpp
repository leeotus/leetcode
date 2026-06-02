#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    struct CharItem {
        CharItem(char c, int cnt) : c_(c), cnt_(cnt) {}
        char c_;
        int cnt_;
    };
    int compress(vector<char>& chars) {
        int ret = 0;
        int cur = 0, idx = 0;
        int cnt = 0;
        vector<CharItem> items{};
        while(idx < chars.size()) {
            cnt = 0;
            while (idx < chars.size() && chars[idx] == chars[cur]) {
                ++cnt;
                idx += 1;
            }
            CharItem i(chars[cur], cnt);
            items.push_back(i);
            cur = idx;
        }

        for (auto &it : items) {
            // chars数组的长度一定大于items
            chars[ret++] = it.c_;
            if(it.cnt_ > 1) {
                string num = to_string(it.cnt_);
                for(int i = 0; i < num.size(); ++i) {
                    chars[ret++] = num[i];
                }
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution slt;
    vector<char> chars = {'a', 'a', 'b'};
    auto ret = slt.compress(chars);
    cout << "result:" << ret << "\r\n";
    return 0;
}