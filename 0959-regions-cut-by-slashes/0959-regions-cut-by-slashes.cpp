class Solution {
private:
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    void dfs(int cy, int cx, vector<vector<int>> &matrix, vector<vector<bool>> &visit) {
        
        visit[cy][cx] = true;

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || nx < 0 || ny >= matrix.size() || nx >= matrix[0].size())
                continue;
            
            if (matrix[ny][nx] == 1 || visit[ny][nx] == true)
                continue;
            
            dfs(ny, nx, matrix, visit);
        }
    }

public:
    int regionsBySlashes(vector<string>& grid) {

        int grid_size = grid.size();
        int matrix_size = grid_size * 3;

        vector<vector<int>> matrix(matrix_size, vector<int>(matrix_size, 0));

        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                
                if (grid[i][j] == '/') {
                    matrix[i * 3][j * 3 + 2] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    matrix[i * 3][j * 3] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        vector<vector<bool>> visit(matrix_size, vector<bool>(matrix_size, false));

        int answer = 0;

        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {

                if (matrix[i][j] == 0 && visit[i][j] == false) {
                    answer++;
                    dfs(i, j, matrix, visit);
                }
            }
        }

        return answer;
    }
};