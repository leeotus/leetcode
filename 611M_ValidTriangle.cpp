#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 不能借鉴三数之和那样的写法
    int triangleNumber(vector<int>& nums) {
        int ret{0};

        sort(nums.begin(), nums.end());
        
        int i;
        for(i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i-1] == nums[i]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                if (isValidTriangle(nums[i], nums[j], nums[k])) {
                    ret += 1;
                }
                while (j + 1 < nums.size() && nums[j + 1] == nums[j]) {
                    ++j;
                }
                while (k - 1 >= 0 && nums[k - 1] == nums[k]) {
                    --k;
                }
                ++j;
                --k;
            }
        }

        return ret;
    }
    
    int triangleNumber2(vector<int> &nums) {
        ret = 0;
        triangle.clear();
        travel(nums, 0);
        return ret;
    }
    
    int triangleNumer3(vector<int> &nums) {
        if(nums.size() < 3) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i <= nums.size() - 3; ++i) {
            if(nums[i] == 0 || (i > 1 && nums[i-1] == nums[i])) {
                return;
            }

            int j, k = nums[nums.size() - 1];
            for (j = i + 1; j < k; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if (nums[i] + nums[j] <= nums[k]) {
                    // 不满足三角形的条件
                    while (k - 1 >= j && nums[k - 1] == nums[k]) {
                        --k;
                    }
                    --k;
                } else if (isValidTriangle(nums[i], nums[j], nums[k])) {
                    ret += 1;
                    while (k - 1 >= j && nums[k - 1] == nums[k]) {
                        --k;
                    }
                    --k;
                }
            }
        }
    }

private:
    int ret{0};
    vector<int> triangle{};
    void travel(vector<int> &nums, int index) {
        if(triangle.empty() && (index > 1 && nums[index] == nums[index - 1])) {
            travel(nums, index + 1);
            return;
        }
        if(triangle.size() == 3) {
            if(isValidTriangle(triangle)) {
                ret += 1;
            }
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            triangle.push_back(nums[i]);
            travel(nums, i + 1);
            triangle.pop_back();
        }
    }

    bool isValidTriangle(vector<int> t) {
        int a = t[0];
        int b = t[1];
        int c = t[2];
        return isValidTriangle(a, b, c);
    }
    bool isValidTriangle(int a, int b, int c) {
        if(a == 0 || b == 0 || c == 0) {
            return false;
        }
        if((a + b <= c) || (a + c <= b) || (b + c <= a)) {
            return false;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {0, 1, 1, 1};
    Solution slt;
    auto ret = slt.triangleNumber2(nums);
    cout << "result:" << ret << "\r\n";
    return 0;
}