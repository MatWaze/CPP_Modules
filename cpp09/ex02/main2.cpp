#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <time.h>
#include <climits>

#define VECTOR "std::vector<int>"

template<typename T>
void    sortWith(std::string containerName, int argc, char **argv)
{
    PmergeMe    pm(argc, argv);

    std::cout << "Sequence before sorting: ";

    T notSorted;

    if (containerName == VECTOR)
        notSorted = pm.notSorted();
    else
        notSorted = pm.notSorted();

    for (size_t i = 0; i < notSorted.size(); i++)
        std::cout << notSorted[i] << " ";
    std::cout << std::endl;

    clock_t	start = clock();

    T   sorted;
    if (containerName == VECTOR)
        sorted = pm.sorted();
    else
        sorted = pm.sorted();

    clock_t	end = clock();

    std::cout << "Sequence after sorting:  ";

    for (size_t i = 0; i < sorted.size(); i++)
        std::cout << sorted[i] << " ";
    std::cout << std::endl;

    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0; 

    bool b = std::is_sorted(sorted.begin(), sorted.end());

    if (!b)
        std::cout << "The sequence is not sorted" << std::endl;
    else
        std::cout << "It took " << time << " ms to sort the " << containerName << " of size " << sorted.size() << std::endl;
}

int main(int argc, char **argv)
{
    try
    {
        sortWith<std::vector<int>>(VECTOR, argc, argv);
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}