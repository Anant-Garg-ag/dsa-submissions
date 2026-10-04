class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() -1;
        int sum = numbers[i] + numbers[j];
        while (sum != target){
            if (sum < target){
                i++;
                sum = numbers[i] + numbers[j];
            }
            else if (sum > target){
                j--;
                sum = numbers[i] + numbers[j];
            }
        }
        return {i + 1, j + 1};
    }
};
