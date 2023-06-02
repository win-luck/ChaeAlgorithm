#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSubset(const vector<int>& subset) {
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;
}

void subsetSum(const vector<int>& nums, vector<int>& subset, int start, int sum, int targetSum) {
    if (sum == targetSum) {
        printSubset(subset);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        if (sum + nums[i] <= targetSum) {
            subset.push_back(nums[i]);
            subsetSum(nums, subset, i + 1, sum + nums[i], targetSum);
            subset.pop_back();
        }
    }
}

void generateSubsets(const vector<int>& nums, int targetSum) {
    vector<int> subset;
    subsetSum(nums, subset, 0, 0, targetSum);
}

int main() {
    vector<int> weights = {15, 22, 14, 26, 32, 9, 16, 8};
    int target = 53;
    generateSubsets(weights, target);
    return 0;
}
