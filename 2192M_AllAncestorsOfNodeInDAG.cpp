#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<vector<int>> res(n, vector<int>{});
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            graph[x].push_back(y);
        }

        // 有向无环图, 无需visited数组
        vector<set<int>> ancs(n, set<int>{});
        auto dfs = [&](auto &&self, int x) -> void {
            for (auto &y : graph[x]) {
                for (auto anc : ancs[x]) {
                    ancs[y].insert(anc);
                }
                ancs[y].insert(x);
                self(self, y);
            }
        };

        for (int i = 0; i < n; ++i) {
            dfs(dfs, i);
        }

        for (int i = 0; i < n; ++i) {
            auto anc = ancs[i];
            for (auto a : anc) {
                res[i].push_back(a);
            }
        }

        return res;
    }
};

int main(int argc, char **argv) { return 0; }