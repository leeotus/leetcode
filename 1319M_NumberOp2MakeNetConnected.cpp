#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        vector<vector<int>> graph(n);
        for (auto &c : connections) {
            int x = c[0], y = c[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<bool> visited(n, false);
        vector<int> dumplicated;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // 没有被遍历过
                int bioedges = 0;
                int nodes = dfs(graph, visited, i, bioedges);
                dumplicated.push_back((bioedges / 2) + 1 - nodes);
            }
        }

        int n = dumplicated.size();
        int sum = 0;
        for (auto d : dumplicated) {
            sum += d;
        }
        if (sum < n - 1) {
            return -1;
        }
        return n - 1;
    }

  private:
    int dfs(vector<vector<int>> &graph, vector<bool> &visited, int x,
            int &bioedges) {
        int nodes = 1;
        visited[x] = true;
        bioedges += graph[x].size();
        for (auto y : graph[x]) {
            if (!visited[y]) {
                nodes += dfs(graph, visited, y, bioedges);
            }
        }
        return nodes;
    }
};

int main(int argc, char **argv) { return 0; }