/*题目内容：给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。*/


#include <vector>
#include <unordered_set>
#include<iostream>
#include<algorithm>
using namespace std;

/*思路一：使用哈希集合*/

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for (int num : numSet) {
        // 如果 num-1 不存在，说明 num 是一个序列的起点
        if (!numSet.count(num - 1)) {
            int currentNum = num;
            int currentLen = 1;

            while (numSet.count(currentNum + 1)) {
                currentNum++;
                currentLen++;
            }
            longest = max(longest, currentLen);
        }
    }
    return longest;
}

/*思路二：使用排序*/
int longestConsecutive2(vector<int>& nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());
    int longest = 1;
    int currentLen = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            continue;
        } else if (nums[i] == nums[i - 1] + 1) {
            currentLen++;
        } else {
            longest = max(longest, currentLen);
            currentLen = 1;
        }
    }
    return max(longest, currentLen);
}

int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl; // 输出: 4
    cout << longestConsecutive2(nums) << endl; // 输出: 4
    return 0;
}