//
//  main.cpp
//  test_11_18(newcode求两个数的最近公共祖先)
//
//  Created by 张辉 on 2019/11/18.
//  Copyright © 2019 可乐. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

//题目：有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号/，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先

//分析：让编号大的先走（往父节点走），然后再比较两个谁大，大的继续走，直到两个走到相同的时候，该节点就是最初两个节点的最近公共祖先


#include <iostream>
using namespace std;
class LCA
{
public:
    int getLCA(int a, int b)
    {
        while(a != b)
        {
            if(a > b)
            {
                a = a / 2;
            }
            if(a < b)
            {
                b = b / 2;
            }            //谁大谁先走，走完比一下，不管左孩子还是又孩子，计算其父节点都是除以2
        }
        return a;
    }
};
int main()
{
    LCA l;
    int a, b;
    cin >> a;
    cin >> b;
    int ret = l.getLCA(a,b);
    cout << ret << endl;
    return 0;
}
