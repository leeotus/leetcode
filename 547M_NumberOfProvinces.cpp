#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int res = 0;
        if (isConnected.empty()) {
            return res;
        }

        int n = isConnected.size();
        vector<vector<int>> graph(n);
        for (auto &c : isConnected) {
            for (int i = 0; i < c.size(); ++i) {
                if (c[i] == 1) {
                    for (int j = i + 1; j < c.size(); ++j) {
                        if (c[j] == 1) {
                            graph[i].push_back(j);
                            graph[j].push_back(i);
                        }
                    }
                }
            }
        }
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                res += 1;
                dfs(graph, visited, i);
            }
        }
        return res;
    }

  private:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int x) {
        visited[x] = true;
        for (int y : graph[x]) {
            if (!visited[y]) {
                dfs(graph, visited, y);
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution s;

    return 0;
}