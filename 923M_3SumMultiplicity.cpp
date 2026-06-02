#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ret{0};
        if(arr.size() < 3) {
            return ret;
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i) {
            int j = i+1, k = arr.size() - 1;
            while(j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == target) {
                    // 分情况讨论, 如果arr[j] 不等于 arr[k]
                    if (arr[j] != arr[k]) {
                        int lc = 1; // left count
                        int rc = 1; // right count
                        while (j < k && arr[j] == arr[j + 1]) {
                            ++lc;
                            ++j;
                        }
                        ++j;
                        while (j < k && arr[k] == arr[k - 1]) {
                            ++rc;
                            --k;
                        }
                        --k;
                        ret += lc * rc;
                    } else if(arr[j] == arr[k]) {
                        // 如果arr[j] == arr[k]
                        ret += (k - j + 1) * (k - j) / 2;
                        break;
                    }
                } else if(sum < target) {
                    while(j < k && arr[j+1] == arr[j]) {
                        ++j;
                    }
                    ++j;
                } else {
                    while(j < k && arr[k-1] == arr[k]) {
                        --k;
                    }
                    --k;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    vector<int> arr{1,1,2,2,3,3,4,4,5,5};
    int target = 8;
    Solution slt;
    auto ret = slt.threeSumMulti(arr, target);
    cout << "result:" << ret << "\r\n";
    int64_t num = 10e9+7;
    cout << num << endl;
    return 0;
}