/* Any modifications to this file
 * will be overwritten with a copy
 * of the original file.
 * Version: 1.1
 */

#include<iostream>
using namespace std;
#include "PartitionSort.h"
int main()
{
  int count;
  std::cin >> count;
  PartitionSort part_sorter(count);
  float num;
  for(int i=0; i<count; ++i)
  {
    std::cin >> num;
    part_sorter.add(num);
  }
  part_sorter.display();
  part_sorter.sort();
  part_sorter.display();
  return 0;
}
