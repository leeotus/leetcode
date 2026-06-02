#include <iostream>
#include <vector>

#include <climits>

using namespace std;

using namespace std;

class Solution2 {
  public:
    int minScore(int n, vector<vector<int>> &roads) {
        vector<vector<pair<int, int>>> g(n);
        for (auto &road : roads) {
            int x = road[0] - 1, y = road[1] - 1, d = road[2];
            g[x].emplace_back(y, d);
            g[y].emplace_back(x, d);
        }
        int ans = INT_MAX;
        vector<bool> vis(n, false);

        auto dfs = [&](auto &&self, int x) -> void {
            vis[x] = true;
            for (auto &[y, d] : g[x]) {
                ans = min(ans, d);
                if (!vis[y]) {
                    self(self, y);
                }
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};

class Solution {
  public:
    int minScore(int n, vector<vector<int>> &roads) {
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
        for (auto &r : roads) {
            int x = r[0];
            int y = r[1];
            int d = r[2];
            graph[x][y] = d;
            graph[y][x] = d;
        }
        vector<int> scores(n + 1, INT32_MAX);
        dfs(graph, scores, 1, n);
        return res;
    }

  private:
    int res = INT32_MAX;
    void dfs(vector<vector<int>> &graph, vector<int> &scores, int x, int n) {
        for (int y = 1; y <= n; ++y) {
            if (graph[x][y] != 0 && graph[x][y] < scores[y]) {
                scores[y] = graph[x][y];
                int d = graph[x][y];
                res = min(res, d);
                dfs(graph, scores, y, n);
            }
        }
    }
};

int main(int argc, char **argv) {
    int n = 4;
    vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    Solution s;
    int sc = s.minScore(n, roads);
    cout << "result:" << sc << "\r\n";
    return 0;
}