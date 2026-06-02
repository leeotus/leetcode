#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res{0};
        if(s.empty()) {
            return res;
        }

        set<char> unique_chars;
        queue<char> str_queue;
        for(int i=0; i<s.size(); ++i) {
            char c = s[i];
            if(unique_chars.find(c) != unique_chars.end()) {
                while(!str_queue.empty()) {
                    char front = str_queue.front();
                    unique_chars.erase(front);
                    str_queue.pop();
                    if(front == c) {
                        break;
                    }
                }
            }
            unique_chars.insert(c);
            str_queue.push(c);
            res = max(res, (int)str_queue.size());
        }
        return res;
    }
};

int main(int argc, char **argv) {
    string s = "abcabcbb";
    Solution slt;
    auto res = slt.lengthOfLongestSubstring(s);
    cout << "result: " << res << "\r\n";
    return 0;
}
