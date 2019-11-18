//
//  main.cpp
//  test_11_19(nowcoder求最大连续bit数)
//
//  Created by 张辉 on 2019/11/19.
//  Copyright © 2019 可乐. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

//题目：求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
//
//分析：使用移位统计连续出现1的次数，每次统计完与前面的连续次数作比较比前面的大就更新

#include <iostream>
#include <algorithm>
using namespace std;

/*从最低位开始，n&1判断当前位是否为1
 *    如果是1，++count，更新maxsize；
 *    如果是0，count归0；
 *    n向左移位来比较下一位
*/
int main()
{
    int n;
    while (cin >> n)
    {
        int count = 0, maxsize = 0;
        while (n)
        {
            if (n & 1)
            {
                count++;
                maxsize = max(maxsize, count);
            }
            else
                count = 0;
                n = n >> 1;
        }

        cout << maxsize << endl;
    }
    return 0;
}



