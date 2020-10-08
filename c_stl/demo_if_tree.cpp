class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if (edges.size() != n - 1) return false;
        vector<vector<int>> map(n, vector<int>(n, 0));
        for (int i = 0; i < edges.size(); ++i) {
            int p1 = edges[i][0], p2 = edges[i][1];
            map[p1][p2] = map[p2][p1] = 1;
        }
        vector<bool> visited(n, false);
        dfs(map, 0, visited);
        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>> &map, int curr, vector<bool> &visited) {
        visited[curr] = true;
        for (int i = 0; i < map[curr].size(); ++i) {
            if (map[curr][i] && !visited[i]) {
                dfs(map, i, visited);
            }
        }
    }
};
