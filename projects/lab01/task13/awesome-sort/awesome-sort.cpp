#include "awesome-sort.h"

// Swap Sort Function for Asscending Order
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
  return;
}

// Insertion Sort Function for Asscending Order
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
  return;
}