//
//  main.cpp
//  test_6_2
//
//  Created by 张辉 on 2019/6/2.
//  Copyright © 2019年 张辉. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}
#include <iostream>
#include <queue>
using namespace std;
int m=8;
int n=8;
int grid[10][10];
int indexcount=0;

struct Position
{
    int row;
    int col;
};
void showPath()
{
    for(int i=0; i<10; i++)
    {
        
        for(int j=0; j<10; j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
    cout<<"------------------"<<endl;
}
bool FindPath(Position start,Position finish,int &PathLen,Position  *&path)
{
    //计算从起点位置start到目标位置finish的最短布线路径，找到最短布线路//径则返回true，否则返回false
    
    if((start.row==finish.row) && (start.col==finish.col))
    {
        PathLen=0;
        cout<<"start=finish"<<endl;
        return true;
    } //start=finish
    //设置方格阵列“围墙”
    //初始化图，-1为未访问
    for(int i=1; i<9; i++)
    {
        for(int j=1; j<9; j++)
            grid[i][j]=-1;
        
    }
    //添加阻挡点
    grid[2][3]=-2;
    for(int i=0; i<= m+1; i++)
        grid[0][i]=grid[n+1][i]=-2; //顶部和底部
    for(int i=0; i<= n+1; i++)
        grid[i][0]=grid[i][m+1]=-2; //左翼和右翼
    //初始化相对位移
    cout<<"完整图"<<endl;
    showPath();
    Position offset[4];
    offset[0].row=0;
    offset[0].col=1;//右
    offset[1].row=1;
    offset[1].col=0;//下
    offset[2].row=0;
    offset[2].col=-1;//左
    offset[3].row=-1;
    offset[3].col=0;//上
    int NumOfNbrs=4;//相邻方格数
    Position here,nbr;
    here.row=start.row;
    here.col=start.col;
    grid[start.row][start.col]=0;
    //标记可达方格位置
    cout<<"布线前图"<<endl;
    showPath();
    
    queue<Position> Q;
    do  //标记相邻可达方格
    {
        for(int I=0; I<NumOfNbrs; I++)
        {
            nbr.row=here.row + offset[I].row;
            nbr.col=here.col+offset[I].col;
            if(grid[nbr.row][nbr.col]==-1)
            {
                //该方格未被标记
                //cout<<grid[nbr.row][nbr.col]<<endl;//显示路标值
                grid[nbr.row][nbr.col]=grid[here.row][here.col]+1;
                //cout<<nbr.col<<"   "<<nbr.row<<endl;//显示坐标
            }
            if((nbr.row==finish.row) &&(nbr.col==finish.col)) break; //完成布线
            Q.push(nbr);
            
            
        }
        //是否到达目标位置finish？
        if((nbr.row==finish.row)&&(nbr.col==finish.col)) break;//完成布线
        //活结点队列是否非空？
        if(Q.empty()) return false;//无解
        here = Q.front();
        //cout<<here.col<<" "<<here.row<<endl;
        Q.pop();//取下一个扩展结点
        
        
        indexcount++;
        // cout<<"下一节点"<<indexcount<<endl;
    }
    while(true);
    //构造最短布线路径
    PathLen=grid[finish.row][finish.col];
    path=new Position[PathLen];
    //从目标位置finish开始向起始位置回溯
    here=finish;
    for(int j=PathLen-1; j>=0; j--)
    {
        path[j]=here;
        //找前驱位置
        for(int i=0; i<NumOfNbrs; i++)
        {
            nbr.row=here.row+offset[i].row;
            nbr.col=here.col+offset[i].col;
            if(grid[nbr.row][nbr.col]==j)
            {
                // cout<<j<<endl;
                break;
            }
        }
        here=nbr;//向前移动
    }
    return PathLen;
}
int main()
{
    Position start;
    start.col=1;
    start.row=1;
    cout<<"布线起点"<<endl;
    cout<<start.col<<" "<<start.row<<endl;
    Position finish;
    finish.row=3;
    finish.col=4;
    cout<<"布线结束点"<<endl;
    cout<<finish.col<<" "<<finish.row<<endl;
    int PathLen=0;
    Position *path;
    
    FindPath(start,finish,PathLen,path);
    cout<<"布线后路径图"<<endl;
    showPath();
    cout<<"路径"<<endl;
    for(int i=0; i<PathLen; i++)
    {
        cout<<path[i].col<<" "<<path[i].row<<endl;
    }
    cout << "布线问题完毕!" << endl;
    
    system("pause");
    return 0;
}
