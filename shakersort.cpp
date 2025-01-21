#include <iostream>
#include <time.h>
using namespace std;

void srt(unsigned int* p, unsigned int n)
{
    clock_t start, end;
    start = clock();
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                swap(p[j], p[j + 1]);
            }
        }
        for (int j = n - i - 2; j > i; j--)
        {
            if (p[j] < p[j - 1])
            {
                swap(p[j], p[j - 1]);
            }
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
