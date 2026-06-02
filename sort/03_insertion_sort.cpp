#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> &in) {
    for (int i = 1; i < in.size(); ++i) {
        int cur = in[i];
        int j = i - 1;
        while (j >= 0 && in[j] > cur) {
            in[j + 1] = in[j];
            --j;
        }
        in[j + 1] = cur;
    }
    return in;
}

int main(int argc, char **argv) {
    vector<int> nums = {3, 5, 1, 6, 9, 0, 2};
    auto out = insertionSort(nums);
    for (auto &o : out) {
        cout << o << " ";
    }
    cout << "\r\n";
    return 0;
}