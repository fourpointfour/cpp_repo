// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
bool isSafe(int m[MAX][MAX], int x, int y, int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n &&
            m[x][y] == 1);
}
void solveMaze(int n, vector< list< pair<int, int> > >& res, list< pair<int, int> > l, int i, int j, int m[MAX][MAX], int sol[MAX][MAX])
{
    if(i == n - 1 && j == n - 1 && m[i][j] == 1 && sol[i][j] == 1)
    {
        res.push_back(l);
        return;
    }
    if(isSafe(m, i, j, n))
    {
        sol[i][j] = 1;
        l.push_back(make_pair(i, j));
        solveMaze(n, res, l, i+1, j, m, sol);
        solveMaze(n, res, l, i, j+1, m, sol);
        sol[i][j] = 0;
        l.pop_back();
        return;
    }
}
vector<string> printPath(int m[MAX][MAX], int n) {
    vector< list< pair<int, int> > > res;
    vector<string> final_vec;
    int sol[MAX][MAX];
    memset(sol, 0, sizeof(sol));
    solveMaze(n, res, {}, 0, 0, m, sol);
    if(res.empty())
        return {};
    for(int i = 0; i < res.size(); ++i)
    {
        string str;
        auto it = res[i].begin();
        auto itr = it;
        itr++;
        while(itr != res[i].end())
        {

            if((*it).first == (*itr).first)
                str += 'R';
            else
                str += 'D';
            it = itr;
            ++itr;
        }
        final_vec.push_back(str);
    }
    return final_vec;
}
