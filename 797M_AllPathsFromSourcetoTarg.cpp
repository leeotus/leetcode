#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        ret.clear();
        path_len = graph.size();
        if(graph.empty()) {
            return ret;
        }
        // 回溯
        vector<int> path{};
        backtracking(graph, path);
        return ret;
    }
private:
    int path_len;
    vector<vector<int>> ret;

    void backtracking(vector<vector<int>> &graph, vector<int> &path) {
        if (path.size() == path_len ||
            (path.size() > 0 && path.back() == path_len - 1)) {
            ret.push_back(path);
            return;
        }

        int last = 0;
        if(path.size() > 0) {
            last = path.back();
        } else if(path.size() == 0) {
            path.push_back(0);
        }
        for(int i = 0; i < graph[last].size(); ++i) {
            path.push_back(graph[last][i]);
            backtracking(graph, path);
            path.pop_back();
        }
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {}
    };
    Solution slt;
    auto ret = slt.allPathsSourceTarget(graph);
    for(auto &v : ret) {
        for(auto &n : v) {
            cout << n << " ";
        }
        cout << "\r\n";
    }
    return 0;
}