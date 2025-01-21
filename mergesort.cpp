#include <iostream>
#include <time.h>
#include <stack>
using namespace std;

void merge(unsigned int* p, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    unsigned int* L = new unsigned int[n1];
    unsigned int* R = new unsigned int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = p[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = p[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            p[k++] = L[i++];
        else
            p[k++] = R[j++];
    }

    while (i < n1)
        p[k++] = L[i++];

    while (j < n2)
        p[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void srt(unsigned int* p, unsigned int n)
{

    clock_t start, end;
    start = clock();

    stack<pair<int, int>> s;
    s.push({ 0, n - 1 });

    while (!s.empty())
    {
        int left = s.top().first;
        int right = s.top().second;
        s.pop();

        if (left < right)
        {
            int mid = left + (right - left) / 2;

            s.push({ left, mid });
            s.push({ mid + 1, right });

            merge(p, left, mid, right);
        }
    }
    end = clock();
    cout << ((double)end - start) / ((double)CLOCKS_PER_SEC) << endl;
}

int main()
{
    unsigned int n;
    cin >> n;
    unsigned int* a = new unsigned int[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
    srt(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    delete[] a;
}
