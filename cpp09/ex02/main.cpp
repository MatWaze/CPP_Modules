// #include <chrono>
// #include <algorithm>
// #include <climits>
// #include <cmath>
// #include <iostream>
// #include <vector>
// #include <time.h>
// #include <iostream>
// #include <vector>
// #include <climits>

// void sortPairs(std::vector<std::pair<int, int>> &nums)
// {
//     std::vector<std::pair<int, int>> ans;

//     for (size_t i = 0; i < nums.size(); i++)
//     {
//         if (nums[i].first > nums[i].second)
//         {
//             int temp = nums[i].first;
//             nums[i].first = nums[i].second;
//             nums[i].second = temp;
//         }
//     }
// }

// std::vector<int> pairSmall(std::vector<int> &nums)
// {
//     std::vector<int> ans;
//     for (size_t i = 0; i < nums.size(); i += 2)
//     {
//         if ((i + 1) >= nums.size())
//             break;
//         int first = nums[i];
//         int second = nums[i + 1];

//         if (first < second)
//             ans.push_back(first);
//         else
//             ans.push_back(second);
//     }

//     return ans;
// }

// std::vector<int> pairGreat(std::vector<int> &nums)
// {
//     std::vector<int> ans;
//     for (size_t i = 0; i < nums.size(); i += 2)
//     {
//         if ((i + 1) >= nums.size())
//             break;
//         int first = nums[i];
//         int second = nums[i + 1];

//         if (first > second)
//             ans.push_back(first);
//         else
//             ans.push_back(second);
//     }

//     return ans;
// }

// std::vector<std::pair<int, int>> pairSort(std::vector<int> nums)
// {
//     std::vector<std::pair<int, int>> ans;
//     std::vector<int>::iterator it = nums.begin();

//     for (size_t i = 0; i < nums.size() / 2; i++)
//     {
//         std::pair<int, int> pair;

//         int first = *it++;
//         int second = *it++;

//         pair.first = first;
//         pair.second = second;

//         if (first > second)
//         {
//             pair.first = second;
//             pair.second = first;
//         }

//         ans.push_back(pair);
//     }

//     return ans;
// }

// std::vector<int> getGreatest(std::vector<std::pair<int, int>> pairs)
// {
//     std::vector<int> ans;

//     for (size_t i = 0; i < pairs.size(); i++)
//         ans.push_back(pairs[i].second);

//     return ans;
// }

// std::vector<int> getSmallest(std::vector<std::pair<int, int>> pairs)
// {
//     std::vector<int> ans;

//     for (size_t i = 0; i < pairs.size(); i++)
//         ans.push_back(pairs[i].first);

//     return ans;
// }

// std::vector<int> getSmallest2(std::vector<int> second, std::vector<std::pair<int, int>> pairs)
// {
//     std::vector<int> ans;

//     for (size_t i = 0; i < pairs.size(); i++)
//     {
//         for (size_t j = 0; j < pairs.size(); j++)
//         {
//             if (second[i] == pairs[j].second)
//             {
//                 ans.push_back(pairs[j].first);
//                 break;
//             }
//         }
//     }

//     return ans;
// }

// void binaryInsertion(std::vector<int> &nums, int target)
// {
//     int first = 0;
//     int last = nums.size() - 1;

//     while (first <= last)
//     {
//         int mid = first + (last - first) / 2;

//         if (nums[mid] == target)
//             return;
//         else if (nums[mid] > target)
//             last = mid - 1;
//         else
//             first = mid + 1;
//     }

//     nums.insert(nums.begin() + first, target);
// }

// void binaryInsertionPairs(std::vector<std::pair<int, int>> &nums, std::pair<int, int> target)
// {
//     int first = 0;
//     int last = nums.size() - 1;

//     while (first <= last)
//     {
//         int mid = first + (last - first) / 2;

//         // Avoid duplicates by checking both elements of the pair
//         if (nums[mid] == target || nums[mid].first == target.second || nums[mid].second == target.first)
//             return;

//         if (nums[mid].first > target.first) 
//             last = mid - 1;
//         else
//             first = mid + 1;
//     }

//     nums.insert(nums.begin() + first, target);
// }


// int getJacobsthalNumber(int num)
// {
//     return (pow(2, num) - pow(-1, num)) / 3;
// }

// void insertIntoMainChain(const std::vector<int> &b, std::vector<int> &a)
// {
//     // add b1 before the main chain
//     a.insert(a.begin(), b[0]);

//     // add the rest in this order: b3, b2 ; b5 b4 ; b11 ... b6
//     int count = 0;
//     int currentJacob = 1;
//     int num = b.size();

//     while (true)
//     {
//         int previousJacob = currentJacob;

//         count++;
//         currentJacob = getJacobsthalNumber(count);

//         if (currentJacob >= num)
//         {
//             currentJacob = previousJacob;
//             break;
//         }

//         for (int m = currentJacob; m > previousJacob; m--)
//             binaryInsertion(a, b[m - 1]);
//     }

//     // add the remaining
//     for (int i = num; i > currentJacob; i--)
//         binaryInsertion(a, b[i - 1]);
// }

// std::vector<int> mergeInsertion(std::vector<int> nums)
// {
//     std::vector<std::pair<int, int>> pairs = pairSort(nums);

//     int notPaired = INT_MIN;
//     if (nums.size() % 2 == 1)
//         notPaired = nums[nums.size() - 1];

//     // base case
//     if (pairs.size() == 1)
//     {
//         std::vector<int> ans;
//         ans.push_back(pairs.front().first);
//         ans.push_back(pairs.front().second);

//         if (notPaired != INT_MIN)
//             binaryInsertion(ans, notPaired);

//         return ans;
//     }

//     std::vector<int> g = getGreatest(pairs);
//     std::vector<int> aChain = mergeInsertion(g);
//     std::vector<int> bChain = getSmallest2(aChain, pairs);

//     insertIntoMainChain(bChain, aChain);

//     if (notPaired != INT_MIN)
//         binaryInsertion(aChain, notPaired);

//     return aChain;
// }

// std::vector<int> mergeInsertionNoPair(std::vector<int> &nums)
// {
//     int notPaired = INT_MIN;
//     if (nums.size() % 2 == 1)
//         notPaired = nums[nums.size() - 1];
    
//     // base case
//     if (nums.size() <= 2)
//         return nums;
 
//     std::vector<int> g = pairGreat(nums);
//     std::vector<int> s = pairSmall(nums);
//     std::vector<int> aChain = mergeInsertionNoPair(g);
//     std::vector<int> bChain = mergeInsertionNoPair(s);

//     insertIntoMainChain(bChain, aChain);
    
//     if (notPaired != INT_MIN)
//         binaryInsertion(aChain, notPaired);

//     return aChain;
// }


// std::vector<int> mergeInsertionPairs(std::vector<std::pair<int, int>> pairs)
// {
//     // base case
//     if (pairs.size() == 1)
//     {
//         std::vector<int> ans;
//         ans.push_back(pairs.front().first);
//         ans.push_back(pairs.front().second);

//         return ans;
//     }

//     std::vector<int> g = getGreatest(pairs);
//     std::vector<int> aChain = mergeInsertionPairs(pairSort(g));
//     std::vector<int> bChain = getSmallest2(aChain, pairs);

//     insertIntoMainChain(bChain, aChain);

//     return aChain;
// }

// int main(int argc, char **argv)
// {
//     std::vector<int> nums;

//     for (int i = 1; i < argc; i++)
//         nums.push_back(std::atoi(argv[i]));

//     // for (auto c : nums)
//     //     std::cout << c << " ";
//     // std::cout << "\n";
//     std::cout << "nums size: " << nums.size() << std::endl;
//     // clock_t	start = clock();


//     auto start = std::chrono::high_resolution_clock::now();

//     // Sorting code
//     auto ans = mergeInsertion(nums);

//     auto end = std::chrono::high_resolution_clock::now();
//     auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//     std::cout << "Time to process: " << duration << " milliseconds" << std::endl;
    
// 	// clock_t	end = clock();

// 	// double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0; 
//     // printf ("It took %f ms.\n", time);
//     bool b = std::is_sorted(ans.begin(), ans.end());

//     // for (size_t i = 0; i < ans.size(); i++)
//     //     std::cout << ans[i] << " ";
//     // std::cout << "\n";

//     if (!b)
//         std::cout << "Not sorted" << std::endl;
//     else
//         std::cout << "Sorted" << std::endl;

//     std::cout << "ans size: " << ans.size() << std::endl;

//     // int num = 22;
//     // int count = 0;
//     // int currentJacob = 1;
//     // while (true)
//     // {
//     //     int previousJacob = currentJacob;

//     //     count++;
//     //     currentJacob = getJacobsthalNumber(count);

//     //     if (currentJacob >= num)
//     //     {
//     //         currentJacob = previousJacob;
//     //         break;
//     //     }

//     //     for (int m = currentJacob; m > previousJacob; m--)
//     //         std::cout << m << std::endl;
//     // }

//     // for (int i = num; i > currentJacob; i--)
//     //     std::cout << i << std::endl;
//     // std::cout << getJacobsthalNumber(9) << std::endl;
//     return 0;
// }


// // int main(int argc, char **argv)
// // {
// //     std::vector<int> nums;

// //     for (int i = 1; i < argc; i++)
// //         nums.push_back(std::atoi(argv[i]));

// //     clock_t	start = clock();

// //     std::vector<std::pair<int, int>> pairs = pairSort(nums);

// //     // std::vector<std::pair<int, int>> sortedPairs = mergeInsertionPairs(pairs);
// //     auto ans = mergeInsertionPairs(pairs);

// // 	clock_t	end = clock();
// //     bool b = std::is_sorted(ans.begin(), ans.end());

// //     // for (size_t i = 0; i < ans.size(); i++)
// //     //     std::cout << ans[i] << " ";
// //     // std::cout << "\n";

// //     if (!b)
// //         std::cout << "Not sorted" << std::endl;
// //     else
// //         std::cout << "Sorted" << std::endl;

// //     // for (auto c : ans)
// //     //     std::cout << c << " ";
// //     // std::cout << "\n";
// // 	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0; 
// //     printf ("It took %f ms.\n", time);
// //     return 0;
// // }
    