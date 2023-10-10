#include <bits/stdc++.h>
#include "E:\Codes\debug.h"
using namespace std;
void merge(vector<int> &arr, int l, int m, int h)
{
    debug(arr);
    int n1 = m - l + 1, n2 = h - m;
    vector<int> a1(n1), a2(n2);
    for (int i = 0; i < n1; ++i)
    {
        a1[i] = arr[l + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        a2[i] = arr[m + 1 + i];
    }
    debug(a1, a2);
    int i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {
        if (a1[i] <= a2[j])
        {
            arr[k++] = a1[i++];
        }
        else
        {
            arr[k++] = a2[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = a1[i++];
    }
    while (j < n2)
    {
        arr[k++] = a2[j++];
    }
    debug(arr, a1, a2);
}
void mergeSort(vector<int> &arr, int l, int h)
{
    if (l >= h)
        return;
    int m = (l + h) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, h);
    merge(arr, l, m, h);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;
    mergeSort(arr, 0, n - 1);
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
}