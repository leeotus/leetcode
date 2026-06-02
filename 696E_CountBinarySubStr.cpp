#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    enum {
        kFindBoundaryOf0or1,
        kFindNext0or1,
    };
    int countBinarySubstrings(string s) {
        int ret{0};
        if(s.size() <= 1) {
            return ret;
        }
        status_ = kFindBoundaryOf0or1;
        int left = 0, right = 0;
        int numsOf0or1 = 0;
        while(left < s.size()) {
            switch(status_) {
            case kFindBoundaryOf0or1: {
                numsOf0or1 = 0;
                while(right + 1 < s.size() && s[right + 1] == s[right]) {
                    numsOf0or1++;
                    ++right;
                }
                ++right;
                ++numsOf0or1;
                if(s.size() - right < numsOf0or1) {
                    ++left;
                    right = left;
                } else {
                    status_ = kFindNext0or1;
                }
                break;
            }
            case kFindNext0or1: {
                while (right + 1 < s.size() && s[right + 1] == s[right] && numsOf0or1 > 1) {
                    ++right;
                    --numsOf0or1;
                }
                --numsOf0or1;
                if(numsOf0or1 == 0) {
                    ret += 1;
                    ++left;
                } else {
                    left += numsOf0or1;
                }
                right = left;
                numsOf0or1 = 0;
                status_ = kFindBoundaryOf0or1;
                break;
            }
            }
        }
        return ret;
    }
    
    int countBinarySubstrings2(string s) {
        int ret{0};
        int left = 0, right = 0;
        vector<int> nums;
        int cnt = 0;
        while (right < s.size()) {
            if (s[right] == s[left]) {
                cnt += 1;
                ++right;
                continue;
            }
            nums.push_back(cnt);
            left = right;
            cnt = 0;
        }
        nums.push_back(cnt);
        
        if(nums.size() == 1) {
            return 0;
        }
        for(int i = 1; i < nums.size(); ++i) {
            ret += min(nums[i-1], nums[i]);
        }

        return ret;
    }
private:
    int status_;
};

int main(int argc, char **argv) {
    string s = "00111011";
    Solution slt;
    auto ret = slt.countBinarySubstrings2(s);
    cout << "result:" << ret << "\r\n";
    return 0;
}