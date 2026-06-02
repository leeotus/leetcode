#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        if (graph.empty()) {
            return vector<vector<int>>();
        }

        int n = graph.size();
        vector<int> path{};
        dfs(graph, 0, n - 1, path);
        return res;
    }

  private:
    vector<vector<int>> res;
    void dfs(vector<vector<int>> &graph, int x, int dst, vector<int> &path) {
        path.push_back(x);
        if (x == dst) {
            res.push_back(path);
            path.pop_back();
            return;
        }
        for (int y : graph[x]) {
            // 有向无环图, 无需visited数组
            dfs(graph, y, dst, path);
        }
        path.pop_back();
    }
};