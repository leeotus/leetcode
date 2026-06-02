#include <iostream>
#include <vector>

using namespace std;

// @note 构造大根堆, 可以实现升序排序
void heapify(vector<int> &in, int index, int len) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int maxIndex = index;

    // 向其叶子节点找寻是否有更大的数值
    if ((left < len) && in[maxIndex] < in[left]) {
        maxIndex = left;
    }
    if ((right < len) && in[maxIndex] < in[right]) {
        maxIndex = right;
    }

    if (maxIndex != index) {
        // 发生了改动
        int tmp = in[index];
        in[index] = in[maxIndex];
        in[maxIndex] = tmp;

        // 发生了改动,需要继续向下排序子树
        heapify(in, maxIndex, len);
    }
}

void heapSort(vector<int> &in, int size) {
    // 需要构造大根堆
    for (int i = size / 2 - 1; i >= 0; --i) {
        // 从最后一个非叶子节点开始构造大根堆完全二叉树
        heapify(in, i, size);
    }

    // 开始做排序, 只要每次将大根堆的第一个元素取出来放到数组的最后即可
    // 通过调整len的参数来控制叶子节点的范围
    for (int i = size - 1; i >= 1; --i) {
        int tmp = in[0];
        in[0] = in[i];
        in[i] = tmp;

        // 然后做调整, 从堆顶开始
        heapify(in, 0, i);
    }
}

vector<int> sortArray(vector<int> &in) {
    heapSort(in, in.size());
    return in;
}

void heap_push(vector<int> &heap, int elem) {
    heap.push_back(elem);
    int cur = heap.size() - 1;
    while ((cur - 1) / 2 >= 0 && heap[(cur - 1) / 2] < elem) {
        swap(heap[cur], heap[(cur - 1) / 2]);
        cur = (cur - 1) / 2;
    }

    if (cur == 0) {
        heapify(heap, 0, heap.size());
    }
}

void heap_pop(vector<int> &heap) {
    if (!heap.empty()) {
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(heap, 0, heap.size());
    }
}

int main(int argc, char **argv) {
    vector<int> nums = {3, 6, 1, 2, 5, 7, 0};
    auto out = sortArray(nums);
    for (auto &o : out) {
        cout << o << "\r\n";
    }
    cout << "\r\n";
    return 0;
}