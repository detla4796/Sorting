#include <iostream>
#include <time.h>
#include <stack>
using namespace std;

void srt(unsigned int* p, unsigned int n)
{
    clock_t start, end;
    start = clock();
  stack<pair<int, int>> s;
    s.push({ 0, n - 1 });
  while (!s.empty())
  {
    int l = s.top().first;
    int r = s.top().second;
    s.pop();
    if (l >= r)
      continue;
    int i = l;
    int j = r;
    int x = p[l + rand() % (r - l + 1)];
    while (i <= j)
    {
      while (p[i] < x)
        i++;
      while (p[j] > x)
        j--;
      if (i <= j)
      {
        swap(p[i], p[j]);
        i++;
        j--;
      }
    }
    if (l < j)
      s.push({ l, j });
    if (i < r)
      s.push({ i, r });
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
