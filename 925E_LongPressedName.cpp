#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.empty() || typed.empty() || (typed.size() < name.size())) {
            return false;
        }

        vector<char> nameChars;
        vector<char> typedChars;
        vector<int> nameCnt;
        vector<int> typedCnt;

        countCharsAndCnt(name, nameChars, nameCnt);
        countCharsAndCnt(typed, typedChars, typedCnt);
        
        if(nameChars.size() != typedChars.size()) {
            return false;
        }

        for(int i = 0; i<nameChars.size(); ++i) {
            if(typedChars[i] != nameChars[i]) {
                return false;
            }
            if(typedCnt[i] < nameCnt[i]) {
                return false;
            }
        }

        return true;
    }
private:
  void countCharsAndCnt(string &in, vector<char> &outChars,
                        vector<int> &outCnts) {
      int left = 0, right = 0;
      int cnt = 0;
      while (right < in.size()) {
          if (in[right] == in[left]) {
              cnt += 1;
              right += 1;
          } else {
              outChars.push_back(in[left]);
              outCnts.push_back(cnt);
              left = right;
              cnt = 0;
          }
      }
      outChars.push_back(in[left]);
      outCnts.push_back(cnt);
  }
};

int main(int argc, char **argv) {
    string name = "alexxxx";
    string typed = "aaleeeexx";
    Solution slt;
    auto ret = slt.isLongPressedName(name, typed);
    cout << "result:" << (ret ? "true" : "false") << "\r\n";
    return 0;
}