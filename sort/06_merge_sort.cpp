#include <iostream>
#include <vector>

using namespace std;

vector<int> Merge(vector<int> &left, vector<int> right);

vector<int> MergeSort(vector<int> &in) {
    int n = in.size();
    if (n < 2) {
        return in;
    }

    int mid = n / 2;
    vector<int> L(mid, 0);
    vector<int> R(n - mid, 0);

    for (int i = 0; i < mid; ++i) {
        L[i] = in[i];
    }

    for (int i = mid; i < n; ++i) {
        R[i - mid] = in[i];
    }

    auto sortedL = MergeSort(L);
    auto sortedR = MergeSort(R);
    return Merge(sortedL, sortedR);
}

vector<int> Merge(vector<int> &left, vector<int> right) {
    int len1 = left.size();
    int len2 = right.size();
    vector<int> res(len1 + len2, 0);

    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (left[i] < right[j]) {
            res[k++] = left[i++];
        } else {
            res[k++] = right[j++];
        }
    }

    while (i < len1) {
        res[k++] = left[i++];
    }

    while (j < len2) {
        res[k++] = right[j++];
    }
    return res;
}

int main(int argc, char **argv) {
    vector<int> nums = {3, 8, 1, 2, 5, 7, 9, 0};
    auto res = MergeSort(nums);
    for (auto &n : res) {
        cout << n << " ";
    }
    cout << "\r\n";
    return 0;
}