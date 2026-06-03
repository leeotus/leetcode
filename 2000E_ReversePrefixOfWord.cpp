#include <string>

using namespace std;

class Solution {
  public:
    string reversePrefix(string word, char ch) {
        if (word.empty()) {
            return word;
        }
        int right;
        for (right = 0; right < word.size(); ++right) {
            if (word[right] == ch) {
                break;
            }
        }
        if (right == word.size()) {
            return word;
        }
        int left = 0;
        while (left < right) {
            swap(word[left], word[right]);
            ++left;
            --right;
        }
        return word;
    }
};