#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

#include "awesome-sort.h"

#define VECTOR_SIZE 10000
#define FILE_NAME "numbers.txt"

void test_sort(void (*sort_function)(std::vector<int>&), const std::string &label)
{
  // Init
  std::ifstream file(FILE_NAME);
  if (!file)
  {
    std::cout << "Failed to open file." << std::endl;
    return;
  }

  // Reading
  std::vector<int> v;
  while (!file.eof())
  {
    int n;
    file >> n;
    v.push_back(n);
  }
  file.close();

  // Measuring
  std::clock_t begin = std::clock();

  sort_function(v);

  std::clock_t end = std::clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << label << elapsed_secs << "s" << std::endl;
}


int main()
{
  // Filling array
  std::vector<int> numbers;
  for (int i = 0; i < VECTOR_SIZE; ++i)
    numbers.push_back(i);

  // Shuffle array
  std::srand(unsigned(std::time(0)));
  std::random_shuffle(numbers.begin(),numbers.end());

  // Write array to file
  std::ofstream file;
  file.open(FILE_NAME);
  for (int i = 0; i < numbers.size(); ++i)
    file << numbers[i] << std::endl;
  file.close();

  std::cout << "################################" << std::endl;
  std::cout << "#         Start testing        #" << std::endl;
  std::cout << "################################" << std::endl;
  std::cout << "Amount of elements: " << VECTOR_SIZE << std::endl;
  test_sort(&swap_sort, "Swap sort time: ");
  test_sort(&insertion_sort, "Insert sort time: ");
  test_sort(&quick_sort, "Quick sort time: ");
  test_sort(&select_sort, "Select sort time: ");

  return 0;
}