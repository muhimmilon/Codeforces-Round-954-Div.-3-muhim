#include<bits/stdc++.h>
using namespace std;

// local check
bool ismax(const vector<vector<int>>& matrix,int i,int j)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    for (int k = 0; k < 4; ++k)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] >= matrix[i][j])
        {
            return false;
        }
    }
    return true; // local max sure
}

void mats(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (ismax(matrix, i, j))
                {
                    matrix[i][j] = max(matrix[i][j] - 1, 1);
                    changed = true;
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n,m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> matrix[i][j];
            }
        }

        mats(matrix);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
