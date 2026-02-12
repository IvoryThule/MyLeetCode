/*题目内容如下：
给定一个整数数组nums和一个整数目标值target，
请你在该数组中找出和为目标值target的那两个整数，
并返回它们的数组下标。
你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
你可以按任意顺序返回答案。*/

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//暴力法，时间复杂度O(n^2)，空间复杂度O(1)，思路简单，直接两层循环遍历数组，找到满足条件的两个数的下标并返回。
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};

//哈希表法，时间复杂度O(n)，空间复杂度O(n)，利用哈希表存储数组元素及其下标，遍历数组时检查目标值与当前元素的差值是否在哈希表中。
class Solution2{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> hashMap; //哈希表，键为数组元素，值为对应的下标
        for(int i = 0; i < nums.size(); i++){
            int j = target - nums[i]; //计算目标值与当前元素的差值
            if(hashMap.find(j) != hashMap.end()){ //如果差值在哈希表中，说明找到了满足条件的两个数
                return {hashMap[j], i}; //返回两个数的下标
            }
            hashMap[nums[i]] = i; //将当前元素及其下标存入哈希表
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution2 solution;
    vector<int> result = solution.twoSum(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl; // 输出: Indices: [0, 1]
    return 0;
}