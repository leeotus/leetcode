#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> &in) {
    for (int i = 0; i < in.size(); ++i) {
        int minId = i;
        for (int j = i + 1; j < in.size(); ++j) {
            if (in[j] < in[minId]) {
                minId = j;
            }
        }
        int tmp = in[i];
        in[i] = in[minId];
        in[minId] = tmp;
    }
    return in;
}

int main(int argc, char **argv) {
    vector<int> nums = {3, 2, 6, 7, 9, 5, 4};
    auto out = selectionSort(nums);
    for (auto &o : out) {
        cout << o << " ";
    }
    cout << "\r\n";
    return 0;
}