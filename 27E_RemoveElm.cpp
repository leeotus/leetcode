#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int prev = 0, front = 0;
        while(front < nums.size()) {
            if(nums[front] != val) {
                nums[prev] = nums[front];
                prev += 1;
            }
            ++front;
        }
        return prev;
    }
};

int main(int argc, char **argv) {

    return 0;
}