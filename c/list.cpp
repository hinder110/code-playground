#include <iostream>

#include <vector>

using namespace std;

struct MyString{
    char *beg,*end;

};

void move_to(MyString &src ,MyString &dst){
    dst.beg = src.beg;
    dst.end = src.end;
    src.beg = src.end = nullptr;
}

class MyClass
{
        private:
            int value;
        public:
            static int a;//静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。我们不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化，如下面的实例所示。
            
            //下面的实例有助于更好地理解静态成员数据的概念：
            void setValue(int value)
            {
                this->value=value;
            }//这里的this是一个隐藏指针，他一直指向的是对象的位置，这个在不同的地方这个this指向的是哪一个具体的对象？？？
            void printValue()
            {
                std::cout <<"Value:"<<value<<std::endl;
            }  
            
};//class hou mian shi yao jia ;de !!!

int MyClass::a=100;

//:://范围解析运算符 :: 可以穿越哦！！！
class Line3
{
    public:
        void setLength(double len);
        double getLength(void);
        Line3();//这是构造函数
        ~Line3();//构析函数
        Line3(const Line3 &obj);
    private:
        double length;
        double len;
        int *ptr;
};

//friend class x;友元函数：：类的友元函数定义在类的外部，但是可以访问类的所有private和protected的成员。



Line3::Line3(void)
{
    cout << "Object is being created" << endl;
    ptr = new int;
    *ptr = len;
}

Line3::Line3(const Line3 &obj): length(obj.length), len(obj.len)
{
    cout <<"调用拷贝构造函数并为指针 ptr 分配内存"<<endl;
    ptr = new int ;
    *ptr = *obj.ptr;
    //这里的拷贝函数传入了对象，但这个对象自己有一个地址obj.ptr他让拷贝函数中的ptr指向obj.ptr了
    //这里拷贝的是那个对象的地址！！！
    //很关键的一点是浅拷贝复制的是指针，复制了指针仅仅是可以访问那里的内存数据而已，你得在拷贝函数中提取内存中的变量的数据
    //浅拷贝的缺点也就在这里了，备份是一种浅拷贝的思想吗？
    
}

Line3::~Line3(void)
{
    cout<<"object is being deleted"<<endl;
    delete ptr;
}

void Line3::setLength(double len)
{
    length=len;
}

double Line3::getLength(void)
{
    return length ;

    return *ptr;
}



class Person{
    private:
        string name;
        int age;
    public:
        Person(string n ,int a):name(n),age(a){}
        //zhe li de person zhilei de shi gouzao hanshu 

        void printInfo(){
            cout<<"Name:"<<name<<",Age:"<<age<<endl;
        }
        void printInfo_3();
};

class Box
{
    
    protected://protected（受保护）成员变量或函数与私有成员十分相似，但有一点不同，protected（受保护）成员在派生类（即子类）中是可访问的。
    public:
        friend void printWidth(Box box);
        double width;
};

void pritWidth(Box box ){
    cout<<"box width is :"<<box.width<<endl;
}

class SmallBox:Box
{
private:
    /* data */
public:
    void setSmallWidth( double wid );
    double getSmallWidth( void );
};

double SmallBox::getSmallWidth(void)
{
    return width;
}

void SmallBox::setSmallWidth( double wid )
{
    width = wid;
}


class Line
{
   public:
      double length;
      void setLength( double len );
      double getLength( void );
};
 
// 成员函数定义
double Line::getLength(void)
{
    return length ;
}
 
void Line::setLength( double len )
{
    length = len;
}
//zheli de hua jiushi ::zhege dongxi jiushi weila ge iyi ge qiangwang lei de yizhong fangfa,


void Person::printInfo_3()
{
    cout<<"Name:"<<name<<",Age:"<<age<<endl;
}
 
// 函数声明
void swap(int& x, int& y);

void swap(int& x,int& y)
{
    int temp = x;
    x =y;
    y = temp;

    return;
}
 
int main ()
{
   // 局部变量声明
   int a = 100;
   int b = 200;
   Person person_1("john",30);

   Line line;

   SmallBox box;
 
   // 设置长度
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   // 不使用成员函数设置长度
   line.length = 10.0; // OK: 因为 length 是公有的
   cout << "Length of line : " << line.length <<endl;
   
   // box.width = 10.0; // Error: 因为 width 是私有的
   box.setSmallWidth(10.0);  // 使用成员函数设置宽度
   cout << "Width of box : " << box.getSmallWidth() <<endl;

   //zhe li de hau jiu shi dui yu lei bianliang he duixiang bianliangzuo la qufen
   //zhiyou zai yige lei zhong baohan la lingwai de lei bianlaing caihui qu qufen lei bianqiang he duixiang biangliang

   std::vector<int> myVector(5,10);

   std::vector<int> vec;
   std::vector<int> vec2={1,2,3,4};
   //zhe lishi vector bushsi zhi neng zhi zheng 

   //vector zhishi chunzhu

   int x =myVector[0];//zhe yi dian ky shi he shuzu henxiang ,qishi zai mou fang mian de hua jiushi shuzu

   int y = myVector.at(1);//zheshi di erge yuansu

   int size = myVector.size();

   for (auto it = myVector.begin();it!=myVector.end();++it){
    std::cout<<*it<<"";
   }
   //zheli jiandao l diedai qi 

    std::cout<<"first element:"<<myVector.at(0)<<std::endl;

    //xhrli de jiushi wei sm you std::zheyang de yi ge ddonxi ne 
    //shi yingwei haiyou yidianjiushi zhege si huhe zhineng zhizheng zhijain yehsi you dian guanxi de 

    //zhejiusihi yig eweti ::#std::是在什么时候才出现的呢？

    std::cout<<"size of vector"<<myVector.size()<<std::endl;
    //zheli de hau shi myvector shiyong size()zhege fangfa de; zheli de hau henxiang java zhong duiyu ,zuixiang de haiyoujiushi python zhongde yehshi zheyang de
    myVector.erase(myVector.begin()+2);

    myVector.erase(myVector.end()-1);



   cout << "交换前，a 的值：" << a << endl;
   cout << "交换前，b 的值：" << b << endl;
 
   /* 调用函数来交换值 */
   swap(a, b);
 
   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;

   myVector.clear();

   Line3 line3 ;

   line3.setLength(6.0);

   Line3 line2 = line3; 

   cout <<"Length is :"<<line2.getLength()<<endl;

   cout <<"Length is :"<<line3.getLength()<<endl;

    //~Line3();//这个是子栋启动的吗？构析函数是在对象死亡的是后自动的启动消除内存占用的？？？

    MyClass obj1;
    obj1.setValue(10000);
    obj1.printValue();

    MyClass *ptr1 =&obj1;
    //这里的指针只能访问public中的变量但是对于private中的不能访问！！！


    //std::cout<<"ptr 的value :"<<ptr->value<<std::endl;

    //动态分配内存！！！
    //这里的主要的方法，就是让一个类指针创建一个新的对象，这个对象的内存就是指针的内存，所以最后可以delete掉内存，对应类的内存，这就实现了动态内存分配了！！！
    MyClass *ptr2=new MyClass;//这里应该给的是地址但是现在给的是new MyClass//这里jiushi直接改变了指针的内存位置，让   
    std::cout<<"ptr de dizhi:"<<ptr2<<std::endl;
    std::cout<<"ptr de dizhi:"<<ptr2->a<<std::endl;
    delete ptr2;
    std::cout<<"after ptr de dizhi:"<<ptr2<<std::endl;

    //当我们调用成员函数时，实际上是替某个对象调用它。

    //成员函数通过一个名为 this 的额外隐式参数来访问调用它的那个对象，当我们调用一个成员函数时，用请求该函数的对象地址初始化 this。例如，如果调用 total.isbn()则编译器负责把 total 的地址传递给 isbn 的隐式形参 this，可以等价地认为编译器将该调用重写成了以下形式：
    //this 指针的类型可理解为 Box*。此时得到两个地址分别为 box1 和 box2 对象的地址。
    return 0;

    system("pause");

}



/*这里的引用其实就是一体两面，一个门俩把钥匙，就是一个变量 的值可以有两个钥匙去改变这个空间的值*/

namespace A{

namespace B{
void f(){}
}//namespace B


void f(){
    B::f();//zhe li shi ji fang wen de shi Bzhong de f()

}
}//namespace A

void f(){
    A::f();

    A::B::f();
    //zhe li din yi de shi quanju de hanshu ;
    //zheli hen gaun jian de yi dian jiu shi ,tamen san ge han shu shi bu tong de fangwen de zhuangtai yeshi buyi yang de 

}