//
//  main.cpp
//  test_11_18(newcode)
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



//题目描述：
//对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
//
//给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。
#include <iostream>
#include <vector>
using namespace std;
class Board
{
public:
    bool CheckWon(vector<vector <int>> board)
    {
        //判断行和列和是否满
        int row = board.size();
        for(int i = 0; i < row; ++i)
        {
            int sum_row = 0;
            int sum_cow = 0;
            for(int j = 0; j < row; ++j)
            {
                sum_row += board[i][j];
                sum_cow += board[j][i];
            }
            if(sum_row == row)
            {
                return true;
            }
            if(sum_cow == row)
            {
                return true;
            }
        }
        //判断正副对角线和是否满
        int first = 0;
        int second = 0;
        for(int i = 0; i < row; ++i)
        {
            first += board[i][i];
            second += board[i][row - i - 1];
        }
        if(first == row)
        {
            return true;
        }
        if(second == row)
        {
            return true;
        }
        
        return false;
    }
    
};
int main()
{
    Board b;
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    if(b.CheckWon(a))
    {
        cout << "Won" << endl;
    }
    else
    {
        cout << "Lose" << endl;
    }
    return 0;
}

