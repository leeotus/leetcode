#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicate(vector<int> &nums) {
        int prev = 0, front = 0;
        while(front < nums.size()) {
            if(nums[front] != nums[prev]) {
                nums[++prev] = nums[front];
            }
            ++front;
        }
        return prev + 1;
    }
};

int main(int argc, char **argv) {
    
    return 0;
}