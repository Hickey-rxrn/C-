//
//  main.cpp
//  test_7_31(C++练习)
//
//  Created by 张辉 on 2019/7/31.
//  Copyright © 2019 张辉. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}



#include<iostream>
using namespace std;
//int main()
//{
////    int a;
////    double b;
////    char c;
////    cin>>a;
////    cin>>b>>c;
////    cout<<a<<endl;
////    cout<<b<<" "<<c<<endl;
////
////    return 0;
//
//}
//void TestFunc(int a = 0)
//{
//    cout<<a<<endl;
//}
//int main()
//{
//    TestFunc();    //没有传参时,使用参数的默认值
//    TestFunc(10);  //传参时,使用指定的实参
//    return 0;
//}
//
//


//void TestFunc(int a = 10,int b = 20, int c = 30)
//{
//    cout<<"a = "<<a<<endl;
//    cout<<"b = "<<b<<endl;
//    cout<<"c = "<<c<<endl;
//}
//int main()
//{
//    TestFunc();       //全缺省参数
//    return 0;
//}

//void TestFunc(int a, int b = 20, int c = 30)
//{
//    cout<<"a = "<<a<<endl;
//    cout<<"b = "<<b<<endl;
//    cout<<"c = "<<c<<endl;
//}
//int main()
//{
//    TestFunc();       //半缺省参数
//    return 0;
//}


//   函数重载(同一作用域中可以同名,但是函数的型参必须不同)
//int Add(int x, int y)
//{
//    return x+y;
//}
//double Add(double x, double y)
//{
//    return x+y;
//}
//long Add(long x, long y)
//{
//    return x+y;
//}
//
//int main()
//{
//    cout<<Add(3, 4)<<endl;
//    cout<<Add(3.3, 4.4)<<endl;
//    cout<<Add(3L, 4L)<<endl;
//    return 0;
//}



//extern"C" int Add(int left, int right);
//int main()
//{
//    Add(1, 2);
//    return 0;
//}
//void TestFunc(int a = 10)
//{
//    cout<<a<<endl;
//}
//void TestFunc(double b)
//{
//    cout<<"void TestFunc(double)"<<endl;
//}
//int main()
//{
//    TestFunc();
//    return 0;
//}
//int Add(int x, int y)
//{
//    return x + y;
//}
//int main()
//{
//    printf("%d\n",Add(2,3));
//    return 0;
//}
//void TestReF()
//{
//    int a = 10;
//    int &b = a;
//    int* c = &a;
//    int** d = &c;
//    cout<<&a<<endl;
//    cout<<&b<<endl;
//    cout<<&c<<endl;
//    cout<<&d<<endl;
//}
//int main()
//{
//    TestReF();
//    return 0;
//}
void TestConstRef()
{
    const int a = 10;
    const int& b = a;
    cout<<&a<<endl;
    cout<<&b<<endl;
    const int& c = 10;
    cout<<c<<endl;
    double d = 20.55;
    const int& e = d;
    const int& f = d;
    cout<<&d<<endl;
    cout<<&e<<endl;
    cout<<&f<<endl;
}
int main()
{
    TestConstRef();
    return 0;
}
