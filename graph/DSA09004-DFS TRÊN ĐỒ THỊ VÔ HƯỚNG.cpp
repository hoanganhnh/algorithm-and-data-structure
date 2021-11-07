#include<bits/stdc++.h>

using namespace std;
/**
 * @note: V_vertices: đỉnh
 * @note: E_edgw: cạnh
 * 
 * - Biểu diễn bằng ma trận kề: O(v * v)
 * - Biểu diễn bằng danh sách cạnh: O(v * e)
 * - Biểu diễn bằng danh sách kề: O(v + e)
*/

int n, m, k;
bool visited[1001];
vector<int> adj[1001];

void init() {
    cin >> n >> m >> k;
    for (int i = 0; i <m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int k) {
    cout << k << " ";
    visited[k] = true;
    for (int x: adj[k]) {
        if (!visited[x]) {
            DFS(x);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        DFS(k);
        for (int i = 0; i < 1002; i++){
			adj[i].clear();
		}
        cout << endl;
    }
}