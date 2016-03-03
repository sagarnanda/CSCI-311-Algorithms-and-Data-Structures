/*Any modifications to this file
 * will be overwritten with a copy
 * of the original file.
 * Version: 1.0
 */

#include<iostream>
#include "Sorter.h"
int main()
{
    int count;
    std::cin >> count;
    Sorter sordid(count);
    float num;
    for(int i=0; i<count; ++i)
    {
        std::cin >> num;
        sordid.add(num);
    }
    sordid.display();
    sordid.sort();
    sordid.display();
    return 0;
}
