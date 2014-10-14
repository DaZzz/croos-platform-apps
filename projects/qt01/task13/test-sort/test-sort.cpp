#include "test-sort.h"

int main()
{
  static const int arr[] = {16,2,77,29};
  std::vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]));

  for(int i = 0; i < v.size(); ++i)
    std::cout << v[i] << std::endl;

  // swap_sort(v);

  for(int i = 0; i < v.size(); ++i)
    std::cout << v[i] << std::endl;

  return 0;
}