/**
 * Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]



Constraints:

    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    All the integers of nums are unique.


*/

#include <vector>
#include <stdexcept>
#include <string>
#include <iostream>

class Solution
{
public:
    void gen_perms(std::vector<int> nums, std::vector<std::vector<int>> &perms, int idx = 0)
    {
        // base case:
        if (idx >= nums.size())
        {
            perms.push_back(nums);
            return;
        }

        // recursive case:
        for (int i = idx; i < nums.size(); ++i)
        {
            std::swap(nums[idx], nums[i]);
            gen_perms(nums, perms, idx + 1); // i = 0 will make perms [[1,2,3], [1,3,2]]
            // backtrack
            std::swap(nums[i], nums[idx]);
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> perms;
        gen_perms(nums, perms);
        return perms;
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> nums(argc - 1);
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        try
        {
            std::size_t pos;
            // std::cout << "argv[" << i << "]: " << arg << std::endl;
            int num = std::stoi(arg, &pos);
            // std::cout << num << std::endl;
            if (pos < arg.size())
            {
                std::cerr << "Trailing characters after number: " << arg << std::endl;
            }

            nums[i - 1] = num;
        }
        catch (std::invalid_argument const &ex)
        {
            std::cerr << "Invalid number: " << arg << std::endl;
        }
        catch (std::out_of_range const &ex)
        {
            std::cerr << "Number out of range: " << arg << std::endl;
        }
    }

    Solution solution;

    for (std::vector<int> permutation : solution.permute(nums))
    {
        for (int num : permutation)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}