// sum of subset and print subset

#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int> arr;
int n;
void fun(int in, int s)
{
    if (s == 0)
    {
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
        return;
    }
    if (in == n)
        return;
    if (arr[in] <= s)
    {
        ans.push_back(arr[in]);
        fun(in + 1, s - arr[in]);
        ans.pop_back();
    }
    fun(in + 1, s);
}
int main()
{
    cin >> n;
    arr.resize(n);
    for (auto &it : arr)
        cin >> it;
    int sum;
    cin >> sum;
    fun(0, sum);
}