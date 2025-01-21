#include <iostream>
#include <time.h>
using namespace std;

void srt(unsigned int* p, unsigned int n)
{
    clock_t start, end;
    start = clock();
    for (int i = 1; i < n; i++)
    {
        unsigned int key = p[i];
        int j = i - 1;
        for (; j >= 0 && p[j] > key; j--)
        {
            p[j + 1] = p[j];
        }
        p[j + 1] = key;
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