// class Solution {
// public:
//     vector<int> di = {1, 0, -1, 0};
//     vector<int> dj = {0, 1, 0, -1};

//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();

//         vector<vector<int>> distance(m, vector<int> (n, -1));
//         queue<pair<int, int>> q;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (mat[i][j] == 0) {
//                     distance[i][j] = 0;
//                     q.push({i, j});
//                 }
//             }
//         }
        
//         while (!q.empty()) {
//             int i = q.front().first;
//             int j = q.front().second;
//             q.pop();
            
//             for (int dir = 0; dir < 4; ++dir) {
//                 int ii = i + di[dir];
//                 int jj = j + dj[dir];
//                 if (ii >= 0 and ii < m and jj >= 0 and jj < n and distance[ii][jj] == -1) {
//                     distance[ii][jj] = distance[i][j] + 1;
//                     q.push({ii, jj});
//                 }

//             }
//         }
        
//         return distance;
//     }
// };