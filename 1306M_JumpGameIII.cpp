#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canReach(vector<int> &arr, int start) {
        if (arr.empty()) {
            return false;
        }
        int n = arr.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            int a = arr[i];
            int r = i + a;
            int l = i - a;
            if (r < n && a != 0) {
                graph[i].push_back(r);
            }
            if (l >= 0 && a != 0) {
                graph[i].push_back(l);
            }
        }

        vector<bool> visited(n, false);
        dfs(graph, visited, start, arr);

        return res;
    }

  private:
    bool res = false;
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int x,
             vector<int> &arr) {
        if (arr[x] == 0) {
            res = true;
            return;
        }
        visited[x] = true;
        for (auto y : graph[x]) {
            if (!visited[y]) {
                dfs(graph, visited, y, arr);
            }
        }
    }
};

int main(int argc, char **argv) {}