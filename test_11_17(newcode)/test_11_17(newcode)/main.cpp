//
//  main.cpp
//  test_11_17(newcode)
//
//  Created by 张辉 on 2019/11/18.
//  Copyright © 2019 可乐. All rights reserved.
//
//
//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}
//题目：密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
//
//一、密码长度:
//5 分: 小于等于4 个字符
//10 分: 5 到7 字符
//25 分: 大于等于8 个字符
//二、字母:
//0 分: 没有字母
//10 分: 全都是小（大）写字母
//20 分: 大小写混合字母
//三、数字:
//0 分: 没有数字
//10 分: 1 个数字
//20 分: 大于1 个数字
//四、符号:
//0 分: 没有符号
//10 分: 1 个符号
//25 分: 大于1 个符号
//五、奖励:
//2 分: 字母和数字
//3 分: 字母、数字和符号
//5 分: 大小写字母、数字和符号
//最后的评分标准:
//>= 90: 非常安全
//>= 80: 安全（Secure）
//>= 70: 非常强
//>= 60: 强（Strong）
//>= 50: 一般（Average）
//>= 25: 弱（Weak）
//>= 0: 非常弱
//对应输出为：
//VERY_SECURE,
//WEAK,
//AVERAGE,
//STRONG,
//VERY_STRONG,
//SECURE,
//VERY_WEAK

#include<iostream>
#include<string>
using namespace std;
// 密码长度得分
int grade_len(string& s)
{
    int len = s.size();
    if(len <= 4)
    {
        return 5;
    }
    else if(len >= 5 && len <= 7)
    {
        return 10;
    }
    else if(len >= 8)
    {
        return 25;
    }
    return 0;
}
//字母所得分数
int grade_alpha(string& s)
{
    int alpha = 0;
    int small = 0;
    int big = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(isalpha(s[i]))
        {
           ++alpha;
        }
        if(isupper(s[i]))
        {
            ++big;
        }
        if(islower(s[i]))
        {
            ++small;
        }
    }
    if(alpha == 0)
    {
        return 0;
    }
    if(big == s.size() || small == s.size())
    {
        return 10;
    }
    else if(big > 0 && small > 0)
    {
        return 20;
    }
    return 0;
}
//数字得分
int grade_digit(string& s)
{
    int num = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(isdigit(s[i]))
        {
            ++num;
        }
    }
    if(num == 0)
    {
        return 0;
    }
    else if(num == 1)
    {
        return 10;
    }
    else if(num > 1)
    {
        return 20;
    }
    return 0;
}

// 符号得分
int grade_symbol(string& s)
{
    int sym = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(isalnum(s[i]))
        {
            ++sym;
        }
    }
    if(sym == 0)
    {
        return 0;
    }
    else if(sym == 1)
    {
        return 10;
    }
    else if(sym > 1)
    {
        return 25;
    }
    return 0;
}
 // 奖励得分
int grade_rewd(string& s)
{
    if(grade_alpha(s) > 0 && grade_digit(s) > 0)
    {
        if(grade_symbol(s) > 0)
        {
            if(grade_alpha(s) == 20)
            {
                return 5;
            }
            return 3;
        }
        return 2;
    }
    return 0;
}
void password_grade_level()
{
    string s;
    while(getline(cin, s))
    {
        int ret1 = grade_len(s);
        int ret2 = grade_alpha(s);
        int ret3 = grade_digit(s);
        int ret4 = grade_symbol(s);
        int ret5 = grade_rewd(s);
        int ret = ret1 + ret2 + ret3 + ret4 + ret5;
        if(ret >= 90)
        {
            cout << "VERY_SECURE" << endl;
        }
        else if(ret >= 80)
        {
            cout << "SECURE" << endl;
        }
        else if(ret >= 70)
        {
            cout << "VERY_STRONG" << endl;
        }
        else if(ret >= 60)
        {
            cout << "STRONG" << endl;
        }
        else if(ret >= 50)
        {
            cout << "AVERAGE" << endl;
        }
        else if(ret >= 25)
        {
            cout << "WEAK" << endl;
        }
        else if(ret >= 0)
        {
            cout << "VERY_WEAK" << endl;
        }
        cin.get();
    }
}

int main()
{
    password_grade_level();
    return 0;
}



