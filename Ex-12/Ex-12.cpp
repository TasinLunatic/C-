#include <iostream>
#include <algorithm>

using namespace std;

// Sequential Search with Sentinel
int sequentialSearch(int a[], int n, int key)
{
    a[0] = key;        // sentinel
    int i = n;

    while (a[i] != key)
    {
        i--;
    }

    if (i == 0)
        return 0;     // not found
    else
        return i;     // 1-based index
}

// Binary Search (array must be sorted)
int binarySearch(int a[], int n, int key)
{
    int left = 1;
    int right = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return 0; // not found
}

int main()
{
    int n;
    cin >> n;

    int a[1005];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int key;
    cin >> key;

    // Sequential Search (with sentinel)
    int seqPos = sequentialSearch(a, n, key);

    // Sort array for Binary Search
    sort(a + 1, a + n + 1);

    // Binary Search
    int binPos = binarySearch(a, n, key);

    cout << seqPos << " " << binPos << endl;

    return 0;
}

