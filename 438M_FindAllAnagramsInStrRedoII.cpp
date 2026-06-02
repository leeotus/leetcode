#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res{};
        if(s.size() < p.size()) {
            return res;
        }
        int plen = p.size();
        sort(p.begin(), p.end());
        for (int i = 0; i < s.size() - plen + 1; ++i) {
            string sub = s.substr(i, plen);
            if(p.find(sub[0]) == string::npos) {
                continue;
            }
            sort(sub.begin(), sub.end());
            if(sub == p) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    string s = "cbaebabacd";
    string p = "abc";
    Solution slt;
    auto res = slt.findAnagrams(s, p);
    for(auto &i : res) {
        cout << i << " ";
    }
    cout << "\r\n";
    return 0;
}