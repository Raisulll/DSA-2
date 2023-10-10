#include <bits/stdc++.h>
#include "E:\Codes\debug.h"
using namespace std;
int findPivot(vector<int> &arr, int l, int h)
{
    int p = arr[l], i = l, j = h;
    while (i <= j)
    {
        while (arr[i] <= p)
        {
            i++;
        }
        while (arr[j] > p)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[l]);
    return j;
}
void quickSort(vector<int> &arr, int l, int h)
{
    if (l >= h)
        return;
    int p = findPivot(arr, l, h);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, h);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;
    quickSort(arr, 0, n - 1);
    for (auto it : arr)
        cout << it << " ";
}