#include<bits/stdc++.h>
using namespace std;
int n;
int ans = 0;
int row[100];
int col[100];
int diag1[100];
int diag2[100];
bool check(int r,int c)
{
    if (row[r] == 0 && col[c] == 0 && diag1[r + c] == 0 && diag2[r - c + n - 1] == 0)
        return true;
    return false;
}
void fun(int r)
{
    if (r == n)
    {
        ans++;
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (check(r,c))
        {
            row[r] = 1;
            col[c] = 1;
            diag1[r + c] = 1;
            diag2[r - c + n - 1] = 1;
            fun(r + 1);
            row[r] = 0;
            col[c] = 0;
            diag1[r + c] = 0;
            diag2[r - c + n - 1] = 0;
        }
    }
}
int main()
{
    cin >> n;
    fun(0);
    cout << ans << endl;
    return 0;
}