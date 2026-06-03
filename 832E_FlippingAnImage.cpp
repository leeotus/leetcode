#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
        if (image.empty()) {
            return image;
        }
        int x = image.size();
        int y = image[0].size();
        for (int i = 0; i < x; ++i) {
            int left = 0, right = y - 1;
            while (left <= right) {
                if (left == right) {
                    image[i][left] ^= 1;
                    break;
                }
                image[i][left] ^= 1;
                image[i][right] ^= 1;
                swap(image[i][left], image[i][right]);
                ++left;
                --right;
            }
        }
        return image;
    }
};

int main(int argc, char **argv) { return 0; }