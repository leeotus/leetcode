#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int countCompleteComponents(int n, vector<vector<int>> &edges) {
        int res = 0;
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            graph[x][y] = 1;
            graph[y][x] = 1;
        }

        vector<bool> visited(n, false);
        for (int x = 0; x < n; ++x) {
            vector<int> cpn{};
            if (!visited[x]) {
                int cnt = dfs(graph, visited, x, cpn);
                bool ok = true;
                int sz = -1;
                for (int &c : cpn) {
                    if (sz == -1) {
                        sz = cntLine(graph, c);
                    } else {
                        int l = cntLine(graph, c);
                        if (sz != l) {
                            ok = false;
                        }
                    }
                    if (sz != cnt - 1) {
                        ok = false;
                    }
                }
                if (ok) {
                    res += 1;
                }
            }
        }

        return res;
    }

  private:
    int cntLine(vector<vector<int>> &graph, int x) {
        int res = 0;
        int n = graph.size();
        for (int y = 0; y < n; ++y) {
            if (graph[x][y] != 0) {
                res += 1;
            }
        }
        return res;
    }
    int dfs(vector<vector<int>> &graph, vector<bool> &visited, int x,
            vector<int> &cpn) {
        int res = 1;
        visited[x] = true;
        cpn.push_back(x);
        for (int y = 0; y < graph.size(); ++y) {
            if (graph[x][y] != 0 && !visited[y]) {
                res += dfs(graph, visited, y, cpn);
            }
        }
        return res;
    }
};

int main(int argc, char **argv) { return 0; }