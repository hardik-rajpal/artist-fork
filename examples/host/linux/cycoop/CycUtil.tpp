#include <vector>
#ifndef CYC_UTIL_TPP
#define CYC_UTIL_TPP
template <typename T>
int indexOf(std::vector<T> list, T item)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == item)
        {
            return i;
        }
    }
}
#endif