#include "awesome-sort.h"

// Swap Sort
void swap_sort(std::vector <int> &v)
{
  int vLength = v.size();
  for(int i = 1; i < vLength - 1; ++i)
  {
    for (int j = 0; j < (vLength -1); ++j)
    {
      if (v[j+1] < v[j])
      {
        int temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;
      }
    }
  }
}

// Insertion Sort
void insertion_sort(std::vector<int> &v)
{
  int vLength = v.size();
  for (int i = 1; i < vLength; ++i)
  {
    int j;
    int x = v[i];

    for (j = i - 1; j >= 0 && v[j] > x; --j)
    {
      v[j+1] = v[j];
    }
    v[j+1] = x;
  }
}

// Quick Sort
void _quick_sort(std::vector<int> &v, int first, int last)
{
    int i = first, j = last, x = v[(first + last) / 2];

    do {
        while (v[i] < x) i++;
        while (v[j] > x) j--;

        if(i <= j) {
            if (v[i] > v[j])
            {
              int temp = v[j];
              v[j] = v[j+1];
              v[j+1] = temp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        _quick_sort(v, i, last);
    if (first < j)
        _quick_sort(v, first, j);
}

void quick_sort(std::vector<int> &v)
{
  _quick_sort(v, 0, v.size() - 1);
}