#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> res{};
    unordered_map<char, int> dict;
    for(const auto &c : p) {
        dict[c] += 1;
    }
    int len = p.size();
    int right = 0;
    int left = 0;
    for(;right < s.size(); ++right) {
        if(dict.find(s[right]) == dict.end()) {

        }
    }
    return res;
  }
};

int main(int argc, char **argv) {

    return 0;
}
