#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &in, int left, int right) {
    int pivot = in[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (in[j] <= pivot) {
            i = i + 1;
            int tmp = in[i];
            in[i] = in[j];
            in[j] = tmp;
        }
    }
    int tmp = in[i + 1];
    in[i + 1] = pivot;
    in[right] = tmp;
    return i + 1;
}

void quicksort(vector<int> &in, int left, int right) {
    if (left >= right) {
        return;
    }

    int pos = partition(in, left, right);
    quicksort(in, left, pos - 1);
    quicksort(in, pos + 1, right);
}

vector<int> sortArray(vector<int> &in) {
    quicksort(in, 0, in.size() - 1);
    return in;
}

int main(int argc, char **agrv) {
    vector<int> nums = {3, 5, 0, 6, 1, 7, 9};
    auto out = sortArray(nums);
    for (auto &o : out) {
        cout << o << " ";
    }
    cout << "\r\n";
    return 0;
}