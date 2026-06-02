#include <vector>
#include <iostream>
#include <unordered_set>
#include <math.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(int &n : nums) {
            num_set.insert(n);
        }
        
        int longestSeq = 0;
        for(const int &num : num_set) {
            // 如果可以找到num-1,说明该数值不是seq的起始数值,直接跳过
            if (num_set.count(num - 1)) {
                continue;
            }
            int cur = num;
            int len = 1;
            while (num_set.find(cur + 1) != num_set.end()) {
                len += 1;
                cur += 1;
            }
            longestSeq = max(longestSeq, len);
        }
        return longestSeq;
    }
};

int main(int argc, char **argv) {
    return 0;
}