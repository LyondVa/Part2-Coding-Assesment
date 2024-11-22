//
// Created by fopop on 22/11/2024.
//
#include <iostream>
#include <vector>

int findMissingNumber(const std::vector<int>& nums) {
    const int n = nums.size();

    // Calculate the sum of numbers from 1 to n+1
    const int expectedSum = (n + 1) * (n + 2) / 2;

    // Calculate the actual sum of numbers in the array
    int actualSum = 0;
    for (const int num : nums) {
        actualSum += num;
    }

    // The missing number is the difference between the expected and actual sums
    return expectedSum - actualSum;
}

int main() {
    const std::vector<int> nums = {3, 7, 1, 2, 6, 4};
    const int missingNumber = findMissingNumber(nums);
    std::cout << "Missing number: " << missingNumber << std::endl;

    return 0;
}