#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>> &invocations) {
        vector<vector<int>> graph(n);
        for (auto &iv : invocations) {
            int x = iv[0], y = iv[1];
            graph[x].push_back(y);
        }

        // 无法确定是否是有向无环图
        vector<bool> visited(n, false);
        set<int> funpath;
        auto dfs_lambda = [&](auto &&self, int x, set<int> &funpath) -> void {
            visited[x] = true;
            funpath.insert(x);
            for (auto &y : graph[x]) {
                if (!visited[y]) {
                    self(self, y, funpath);
                }
            }
        };
        dfs_lambda(dfs_lambda, k, funpath);

        vector<int> res{};
        bool keep = false;
        for (int i = 0; i < n; ++i) {
            if (funpath.find(i) != funpath.end()) {
                continue;
            }
            for (auto &y : graph[i]) {
                if (funpath.find(y) != funpath.end()) {
                    keep = true;
                }
            }
            res.push_back(i);
        }
        if (keep) {
            for (auto &y : funpath) {
                res.push_back(y);
            }
        }
        if (res.empty() && funpath.size() != n) {
            for (int i = 0; i < n; ++i) {
                res.push_back(i);
            }
        }
        return res;
    }

  private:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int x,
             set<int> &funpath) {
        visited[x] = true;
        funpath.insert(x);
        for (auto &y : graph[x]) {
            if (!visited[y]) {
                dfs(graph, visited, y, funpath);
            }
        }
    }
};

int main(int argc, char **argv) { return 0; }