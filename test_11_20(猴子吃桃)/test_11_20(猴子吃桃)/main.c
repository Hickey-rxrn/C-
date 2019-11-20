//
//  main.c
//  test_11_20(猴子吃桃)
//
//  Created by 张辉 on 2019/11/20.
//  Copyright © 2019 可乐. All rights reserved.
//
//
//#include <stdio.h>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
//猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了一个，
//第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃前一天剩下的一半零一个。
//到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘多少个桃子？



#include<stdio.h>
int Getnum(int day)
{
    if(day == 10)
    {
        return 1;
    }
    return (Getnum(day + 1) + 1) * 2;
}
int main()
{
    printf("%d\n",Getnum(1));
    return 0;
}

