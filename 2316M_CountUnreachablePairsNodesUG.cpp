#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    long long countPairs(int n, vector<vector<int>> &edges) {
        if (n == 0) {
            return 0;
        }

        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<int> parts;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int sz = dfs(graph, visited, i);
                parts.push_back(sz);
            }
        }
        long long res = 0;
        if (parts.empty() || parts.size() == 1) {
            return res;
        }
        for (int i = 0; i < parts.size(); ++i) {
            for (int j = i + 1; j < parts.size(); ++j) {
                res += parts[i] * parts[j];
            }
        }
        return res;
    }

  private:
    int dfs(vector<vector<int>> &graph, vector<bool> &visited, int x) {
        int res = 1;
        visited[x] = true;
        for (int y : graph[x]) {
            if (!visited[y]) {
                res += dfs(graph, visited, y);
            }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return 0;
}