#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int lb, int ub)
{
    int i = lb - 1;
    int piv = arr[ub];
    for (int j = lb; j < ub; j++)
    {
        if (arr[j] >= piv)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[ub]);
    return i + 1;
}
void QuickSelect(vector<int> &arr, int lb, int ub, int k)
{
    int pivot = partition(arr, lb, ub);
    if (k - 1 == pivot)
    {
        cout << k << " largest element is: " << arr[pivot] << endl;
        return;
    }
    else if (k - 1 < pivot)
    {
        QuickSelect(arr, lb, pivot - 1, k);
    }
    else
    {
        QuickSelect(arr, pivot + 1, ub, k);
    }
}
int main()
{
    int n;
    cout << "Enter the size of the Array: ";
    cin >> n;
    cout << "Enter the elements: \n";
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter the position: ";
    cin >> k;
    QuickSelect(arr, 0, n - 1, k);
}