#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> uniqueNums;
        vector<int> ret{};
        if(nums1.empty() || nums2.empty()) {
            return ret;
        }
        if(nums2.size() > nums1.size()) {
            swap(nums1, nums2);
        }

        for(int i = 0; i < nums1.size(); ++i) {
            uniqueNums.insert(nums1[i]);
        }

        sort(nums2.begin(), nums2.end());
        for(int j = 0; j < nums2.size(); ++j) {
            if(j > 0 && nums2[j-1] == nums2[j]) {
                continue;
            }
            if(uniqueNums.find(nums2[j]) != uniqueNums.end()) {
                ret.push_back(nums2[j]);
            }
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    vector<int> nums1 = {2, 2};
    vector<int> nums2 = {1, 2, 2, 1};
    Solution slt;
    auto ret = slt.intersection(nums1, nums2);
    for(auto num : ret) {
        cout << num << " ";
    }
    cout << "\r\n";
    return 0;
}