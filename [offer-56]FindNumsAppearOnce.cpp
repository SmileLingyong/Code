/**
 * Creation         :       2019.07.13 20:08
 * Last Reversion   :       2019.07.13 20:08
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
FindNumsAppearOnce （数组中只出现一次的数字）
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 找到第一个1所在的位数
 */ 
int FindFirstOne(int bit_res) {
    int index = 0;
    while (((bit_res & 1) == 0) && index < 32) {
        bit_res >>= 1;
        index++;
    }
    return index;
}

/**
 * 用于将数组分成两组，每组都含有一个只出现一次的
 */ 
bool IsBitOne(int target, int index) {
    return ((target >> index) & 1) == 1;
}

/*
首先：位运算中异或的性质：两个相同数字异或=0，一个数和0异或还是它本身。
当只有一个数出现一次时，我们把数组中所有的数，依次异或运算，最后剩下的就是落单的数，因为成对儿出现的都抵消了。
依照这个思路，我们来看两个数（我们假设是AB）出现一次的数组。我们首先还是先异或，剩下的数字肯定是A、B异或的结果，
这个结果的二进制中的1，表现的是A和B的不同的位。我们就取第一个1所在的位数，假设是第3位，接着把原数组分成两组，
分组标准是第3位是否为1。如此，相同的数肯定在一个组，因为相同数字所有位都相同，而不同的数，肯定不在一组。然后把
这两个组按照最开始的思路，依次异或，剩余的两个结果就是这两个只出现一次的数字。
*/
void FindNumsAppearOnce(vector<int> data, int *num1,int *num2) {
    int size = data.size();
    if (size == 2) {
        *num1 = data[0];
        *num2 = data[1];
        return;
    }
    int bit_res = 0;
    for (int i = 0; i < size; i++) {
        bit_res ^= data[i];
    }
    int index = FindFirstOne(bit_res);
    for (int i = 0; i < size; i++) {
        if (IsBitOne(data[i], index)) {
            *num1 ^= data[i];
        } else {
            *num2 ^= data[i];
        }
    }
}

int main() {
    vector<int> data = {2, 4, 3, 6, 3, 2, 5, 5};
    int num1 = 0, num2 = 0;
    FindNumsAppearOnce(data, &num1, &num2);
    cout << num1 << " " << num2 << endl;
    return 0;
}