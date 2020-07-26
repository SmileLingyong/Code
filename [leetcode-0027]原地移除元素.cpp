/**
 * Creation         :       2019.07.02 14:44
 * Last Reversion   :       2019.07.02 14:50
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
removeElement(移除元素) 
题目描述
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
示例 1:
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
你不需要考虑数组中超出新长度后面的元素。

示例 2:
给定 nums = [0,1,2,2,3,0,4,2], val = 2,
函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
注意这五个元素可为任意顺序。
你不需要考虑数组中超出新长度后面的元素。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

/**
 * 方法一：使用双指针
 * i，j分别指向0，然后，j不断往后遍历，当nums[j] != val时，交换nums[i]和nums[j]
 * i和j都++,这样当j遍历到末尾时，i就指向删处后的最后元素的后一个元素，即最终元素长度
 */ 
int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main() {
    string str_input;
    vector<int> nums;
    int val;
    cout << "输入一串以都好分隔符的数字字符串：" << endl;
    cin >> str_input;
    char *s_input = (char *)str_input.c_str();
    const char *split = ",";
    char *p = strtok(s_input, split);
    int a;
    while (p != NULL) {
        sscanf(p, "%d", &a);
        nums.push_back(a);
        p = strtok(NULL, split);
    }
    cout << "输入要删除的数字：" << endl;
    cin >> val;
    cout << removeElement(nums, val);
    return 0;
}