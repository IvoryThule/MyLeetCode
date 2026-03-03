/*LeetCode49：题目内容：给你一个字符串数组，请你将 字母异位词 组合在一起。
可以按任意顺序返回结果列表。*/
/*数据要求：
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
*/

/*解题思路：
1. 遍历字符串数组，将每个字符串排序后作为键，将原始字符串作为值，存入哈希表。
2. 遍历哈希表，将每个键对应的值（即字母异位词的列表）添加到结果列表中。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap; //哈希表，键为排序后的字符串，值为对应的字母异位词列表
        for( string str : strs){
            string sortedStr = str; //将字符串排序
            sort(sortedStr.begin(), sortedStr.end());
            hashMap[sortedStr].push_back(str); //将原始字符串添加到对应的字母异位词列表中
        }
        vector<vector<string>> result;
        for (auto it : hashMap) {
            result.push_back(it.second); //将每个字母异位词列表添加到结果列表中
        }
        return result;
    }

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);
     for (auto it : result) 
        for (auto str : it) {
            cout << str << " ";
        }
        cout << endl;
    return 0;
}