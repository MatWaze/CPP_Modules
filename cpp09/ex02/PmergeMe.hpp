#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <vector>

class PmergeMe
{
    public:
        std::vector<int>    _nums;
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &pm);
        ~PmergeMe();

        PmergeMe    operator=(const PmergeMe &pm);

        // for vector

        static std::vector<std::pair<int, int>> pairSort(const std::vector<int> &nums);
        std::vector<int> getGreatest(const std::vector<std::pair<int, int>> &pairs);
        static std::vector<int> getSmallest(const std::vector<int> &second, const std::vector<std::pair<int, int>> &pairs);
        std::vector<int> mergeInsertion(std::vector<std::pair<int, int>> &pairs, int notPaired);

        std::vector<std::pair<int, int>>    sortPairs(std::vector<std::pair<int, int>> &pairs);
        static int getJacobsthalNumber(int num);
        static void binaryInsertion(std::vector<int> &nums, int target);
        static void insertIntoMainChain(const std::vector<std::pair<int, int>> &pairs, std::vector<int> &mainChain);

        std::vector<int>    sorted();
        std::vector<int>    notSorted() const;
};

#endif