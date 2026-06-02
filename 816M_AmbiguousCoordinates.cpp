#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        sts.clear();
        vector<string> ret{};

        // 去掉括号
        string st = s.substr(1, s.size() - 2);
        
        // 回溯

        return ret;
    }
private:
    vector<vector<string>> sts;
    
    void backtracking(string &str, int index, vector<string> &cur) {
        if(cur.size() == 2 && index == str.size() - 1) {
            sts.push_back(cur);
        }
        
        for(int i = index; i < str.size(); ++i) {
            string s{};
            s.push_back(str[i]);
        }
    }
};

int main(int argc, char **argv) {
    std::string s = "(123)";
    Solution slt;
    auto ret = slt.ambiguousCoordinates(s);
    return 0;
}