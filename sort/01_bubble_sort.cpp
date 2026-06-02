#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> &in) {
    for (int i = 0; i < in.size() - 1; ++i) {
        for (int j = 0; j < in.size() - 1 - i; ++j) {
            if (in[j] > in[j + 1]) {
                int tmp = in[j];
                in[j] = in[j + 1];
                in[j + 1] = tmp;
            }
        }
    }
    return in;
}

int main(int argc, char **argv) {
    vector<int> nums = {2, 6, 5, 1, 3, 4, 9, 0};
    vector<int> res = bubbleSort(nums);
    for (auto &n : res) {
        cout << n << " ";
    }
    cout << "\r\n";
    return 0;
}
