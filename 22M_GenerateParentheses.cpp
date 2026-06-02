#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // 1 <= n <= 8
        vector<string> ret{};
        if(n == 1) {
            ret = collect[0];
            return ret;
        }
        if(n < collect.size()) {
            return collect[n];
        }
        for(int i = 1; i <= n; ++i) {
            ret.clear();
            for(int j = 0; j < collect[i-1].size(); ++j) {
                if (j == 0) {
                    string in1 = collect[i-1][j] + string{"()"};
                    ret.emplace_back(in1);

                    string in2 = string{"("} + collect[i-1][j] + string{')'};
                    ret.emplace_back(in2);
                    continue;
                }

                string part = collect[i-1][j];
                string in1 = string{"()"} + part;
                string in2 = part + string{"()"};
                string in3 = string{"("} + part + string{')'};
                ret.emplace_back(in1);
                ret.emplace_back(in2);
                ret.emplace_back(in3);
            }
            collect.emplace_back(ret);
        }
        return collect[n-1];
    }
private:
    vector<vector<string>> collect{{"()"}};
};

int main(int argc, char **argv) {
    Solution slt;
    auto ret = slt.generateParenthesis(3);
    for(auto s : ret) {
        cout << s << " ";
    }
    cout << "\r\n";
    return 0;
}