#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool validPath(int n, vector<vector<int>> &edges, int source,
                   int destination) {
        if (n == 0) {
            return false;
        }
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<bool> visited(n, false);
        dfs(graph, visited, source, destination);
        return res;
    }

  private:
    bool res{false};
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int x,
             int dst) {
        if (x == dst) {
            res = true;
            return;
        }
        visited[x] = true;
        for (int y : graph[x]) {
            if (!visited[y]) {
                dfs(graph, visited, y, dst);
            }
        }
    }
};

int main(int argc, char **argv) { return 0; }