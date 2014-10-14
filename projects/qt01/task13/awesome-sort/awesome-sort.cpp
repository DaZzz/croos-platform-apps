#include "awesome-sort.h"

// Swap Sort Function for Descending Order
void swap_sort(std::vector <int> &v)
{
    int numLength = v.size();
    for(int i = 1; i < numLength - 1; ++i)
    {
      for (int j = 0; j < (numLength -1); ++j)
      {
        if (v[j+1] > v[j])
        {
          int temp = v[j];
          v[j] = v[j+1];
          v[j+1] = temp;
        }
      }
    }
    return;
}