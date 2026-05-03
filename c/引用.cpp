#include<iostream>

#include<cstring>

using namespace std;

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main(){

    int a =4;
    int b =3;

    int& i =a;
    int& j =b;

    i=6;

    j=7;
    /*这里，引用变量可以改变引用变量的值，但是对于a和b的大小发生改变了吗？*/
    a=9;

    b=8;
    cout << "SS:"<<j<<endl;
    cout << "KK:"<<i<<endl;
    cout << "SS:"<<a<<endl;
    cout << "KK:"<<b<<endl;
    /*这里的引用的话就是强行绑定两个变量了*/
    char str[]=" Unable to read ....";

    clog <<"Error message :"<<str <<endl;

    cerr<<"Error message :"<<str<<endl;

    Books book_1;
    strcpy (book_1.title,"css");
    strcpy (book_1.author,"wjj");

    strcpy (book_1.subject,"c++");

    book_1.book_id =12;

    cout << "第一本书标题 : " << book_1.title <<endl;
    cout << "第一本书作者 : " << book_1.author <<endl;
    cout << "第一本书类目 : " << book_1.subject <<endl;
    cout << "第一本书 ID : " << book_1.book_id <<endl;
    system("pause");
}