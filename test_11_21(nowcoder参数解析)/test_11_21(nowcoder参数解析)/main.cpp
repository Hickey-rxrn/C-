//
//  main.cpp
//  test_11_21(nowcoder参数解析)
//
//  Created by 张辉 on 2019/11/21.
//  Copyright © 2019 可乐. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

//题目描述：
//在命令行输入如下命令：
//xcopy /s c:\ d:\，
//各个参数如下：
//参数1：命令字xcopy
//参数2：字符串/s
//参数3：字符串c:
//参数4: 字符串d:
//请编写一个参数解析程序，实现将命令行各个参数解析出来。
//解析规则：
//
//参数分隔符为空格
//对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入
//xcopy /s “C:\program files” “d:\”时，参数仍然是4个，第3个参数应该是字符串C:\program files，而不是
//C:\program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
//参数不定长
//输入由用例保证，不会出现不符合要求的输入
//输入描述：输入一行字符串，可以有空格
//输出描述：输出参数个数，分解后的参数，每个参数都独占一


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        int count = 0; //计算参数数量
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ')
            {
                ++count;
            }
            if(s[i] == '"') //如果是双引号就向后遍历，直到下一个双引号结束
            {
                do
                {
                    i++;
                } while (s[i] != '"');
            }
        }
        cout << count + 1 << endl;
        //以空格计算参数个数，参数个数 = 空格数 + 1
        //int flag = 1;
        for(int i = 0; i < s.size(); ++i)
        {
//            if(s[i] == '"')
//            {
//                flag ^= 1;
//            }
            if(s[i] != ' ' && s[i] != '"')
            {
                // 普通空格和双引号之外的打印
                cout << s[i];
            }
            if(s[i] == ' ' && s[i] == '"')
            {
                //双引号中的空格要打印
                cout << s[i];
            }
            if(s[i] == ' ' && s[i] != '"')
            {
                //遇到双引号外的空格换行
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
