#include "PmergeMe.hpp"
#include <climits>
#include <cmath>
#include <stdexcept>
#include <string>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pm) : _nums(pm._nums) {}

PmergeMe    PmergeMe::operator=(const PmergeMe &pm)
{
    if (this != &pm)
    {
        this->_nums = pm._nums;
    }

    return *this;
}

bool    isValidNumber(const std::string &str)
{
    unsigned int i = 0;

    for (; i < str.length() && std::isdigit(str[i]); i++) ;

    if (str.length() != 0 && str.length() < 11 && str.length() == i)
    {
        long num = atol(str.c_str());
        
        if (num > INT_MAX)
            return false;

        return true;
    }
    return false;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    if (argc < 2)
        throw std::runtime_error("Not enough arguments");
    for (int i = 1; i < argc; i++)
    {
        std::string s(argv[i]);

        if (isValidNumber(s))
        {
            this->_nums.push_back(atoi(argv[i]));
        }
        else
        {
            std::string msg = "Invalid input: " + s;
            throw std::runtime_error(msg);
        }
    }
}

std::vector<std::pair<int, int>> PmergeMe::pairSort(const std::vector<int> &nums)
{
    std::vector<std::pair<int, int>> ans;
    std::vector<int>::const_iterator it = nums.begin();

    for (size_t i = 0; i < nums.size() / 2; i++)
    {
        std::pair<int, int> pair;

        int first = *it++;
        int second = *it++;

        pair.first = first;
        pair.second = second;

        if (first > second)
        {
            pair.first = second;
            pair.second = first;
        }

        ans.push_back(pair);
    }

    return ans;
}

void    PmergeMe::binaryInsertion(std::vector<int> &nums, int target)
{
    int first = 0;
    int last = nums.size() - 1;

    while (first <= last)
    {
        int mid = first + (last - first) / 2;

        if (nums[mid] == target)
        {
            first = mid;
            break;
        }
        else if (nums[mid] > target)
            last = mid - 1;
        else
            first = mid + 1;
    }

    nums.insert(nums.begin() + first, target);
}

int PmergeMe::getJacobsthalNumber(int num)
{
    return (pow(2, num) - pow(-1, num)) / 3;
}

void    PmergeMe::insertIntoMainChain(const std::vector<std::pair<int, int>> &pairs, std::vector<int> &mainChain)
{
    mainChain.insert(mainChain.begin(), pairs[0].first);

    int count = 0;
    int currentJacob = 1;
    int numPairs = pairs.size();

    while (true)
    {
        int previousJacob = currentJacob;

        count++;
        currentJacob = getJacobsthalNumber(count);

        if (currentJacob >= numPairs)
        {
            currentJacob = previousJacob;
            break;
        }

        for (int m = currentJacob; m > previousJacob; m--)
            binaryInsertion(mainChain, pairs[m - 1].first);
    }

    for (int i = numPairs; i > currentJacob; i--)
        binaryInsertion(mainChain, pairs[i - 1].first);
}

std::vector<int> PmergeMe::getGreatest(const std::vector<std::pair<int, int>> &pairs)
{
    std::vector<int> ans;

    for (size_t i = 0; i < pairs.size(); i++)
        ans.push_back(pairs[i].second);

    return ans;
}

std::vector<std::pair<int, int>> PmergeMe::sortPairs(std::vector<std::pair<int, int>> &pairs)
{
    if (pairs.size() <= 1)
        return pairs;

    size_t mid = pairs.size() / 2;
    std::vector<std::pair<int, int>> left(pairs.begin(), pairs.begin() + mid);
    std::vector<std::pair<int, int>> right(pairs.begin() + mid, pairs.end());

    left = sortPairs(left);
    right = sortPairs(right);

    std::vector<std::pair<int, int>> sortedPairs;
    size_t i = 0;
    size_t j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i].second < right[j].second)
        {
            sortedPairs.push_back(left[i]);
            i++;
        }
        else
        {
            sortedPairs.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size())
    {
        sortedPairs.push_back(left[i]);
        i++;
    }
    while (j < right.size())
    {
        sortedPairs.push_back(right[j]);
        j++;
    }

    return sortedPairs;
}

std::vector<int>    PmergeMe::mergeInsertion(std::vector<std::pair<int, int>> &pairs, int notPaired)
{
    if (pairs.size() <= 1)
    {
        std::vector<int> ans;
        if (!pairs.empty())
        {
            ans.push_back(pairs.front().first);
            ans.push_back(pairs.front().second);
        }

        if (notPaired != INT_MIN)
            binaryInsertion(ans, notPaired);

        return ans;
    }

    pairs = sortPairs(pairs);

    std::vector<int> greatestElements = getGreatest(pairs);

    int newNotPaired = INT_MIN;
    if (greatestElements.size() % 2 == 1)
        newNotPaired = greatestElements[greatestElements.size() - 1];

    std::vector<std::pair<int, int>> newPairs = pairSort(greatestElements);
    std::vector<int> mainChain = mergeInsertion(newPairs, newNotPaired);

    insertIntoMainChain(pairs, mainChain);

    if (notPaired != INT_MIN)
        binaryInsertion(mainChain, notPaired);

    return mainChain;
}

std::vector<int>    PmergeMe::sorted()
{
    if (this->_nums.size() > 1)
    {
        std::vector<std::pair<int, int>> pairs = pairSort(this->_nums);

        int notPaired = INT_MIN;
        if (this->_nums.size() % 2 == 1)
            notPaired = this->_nums[this->_nums.size() - 1];

        return PmergeMe::mergeInsertion(pairs, notPaired);
    }
    else
        return this->_nums;
}

std::vector<int>    PmergeMe::notSorted() const
{
    return this->_nums;
}