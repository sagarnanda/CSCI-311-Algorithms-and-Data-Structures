/* Any modifications to this file
 * will be overwritten with a copy
 * of the original file.
 * Version: 1.0
 */

#include<iostream>
using namespace std;
#include "HeapSort.h"
int main()
{
  int count;
  std::cin >> count;
  HeapSort heap_sorter(count);
  float num;
  for(int i=0; i<count; ++i)
  {
    std::cin >> num;
    heap_sorter.add(num);
  }
  heap_sorter.display();
  heap_sorter.sort();
  heap_sorter.display();
  return 0;
}
