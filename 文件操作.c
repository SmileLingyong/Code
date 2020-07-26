/**
 * Creation         :       2019.07.14 10:00
 * Last Reversion   :       2019.07.13 10:20
 * Author           :       Lingyong Smile {smilelingyong@163.com}
 * File Type        :       cpp
 * -----------------------------------------------------------------
    文件操作：写入+读取字符串
    r: 只读方式打开文本文件，不能写
    w: 只写方式打开文本文件，写了直接覆盖原来的
    a: 只写（添加）方式打开，写了添加在原来的后面
    +: 与上面的 r、 w、 a 结合，表示以读写方式打开文文本件
    b: 与上面的字符组合，表示打开二进制文件
 * -----------------------------------------------------------------
 * Crop right @ 2019 Lingyong Smile {smilelingyong@163.com}
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* ----------------- 打开文件并写入一行语句 ------------------- */
    FILE *fp;
    char line[100];
    int len;
    while ((fp = fopen("./file.txt", "a+")) == NULL) {   // 只写方式打开文件，并用
        printf("打开文件失败！\n");
        exit(0);
    }
    gets(line);                 // 控制台获取一行
    len = strlen(line);
    fputs(line, fp);
    fclose(fp);

    /* ----------------- 打开文件，读取一行，并输出读取的一行 ------------------- */
    while ((fp = fopen("./file.txt", "rb")) == NULL) {
        printf("打开文件失败！\n");
        exit(0);
    }
    fgets(line, 100, fp);    // 从文件中读取100个字符 
    puts(line);
    return 0;
}

// C/C++混合模式编写
// int main() {
//     /* ----------------- 打开文件并写入一行语句 ------------------- */
//     FILE *fp;
//     string line;
//     int len;
//     while ((fp = fopen("./file.txt", "w")) == NULL) {   // 只写方式打开文件，并用
//         cout << "打开文件失败！" << endl;
//         exit(0);
//     }
//     getline(cin, line);             // 控制台获取一行
//     len = strlen(line.c_str());
//     fputs(line.c_str(), fp);
//     fclose(fp);

//     /* ----------------- 打开文件，读取一行，并输出读取的一行 ------------------- */
//     while ((fp = fopen("./file.txt", "rb")) == NULL) {
//         cout << "打开文件失败！" << endl;
//         exit(0);
//     }
//     fgets((char*)line.c_str(), 100, fp);    // 从文件中读取100个字符
//     cout << line << endl;
//     return 0;
// }