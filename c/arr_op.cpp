#include"iostream"
using namespace std;

int main(){

    int arr[5]={3,2,7,4,8};
    for(int i =0;i<5;i++){
        cout<<"现在的数组元素"<<arr[i]<<endl;
    }
    int ver=0;
    int i = 0;
    int num = sizeof(arr)/sizeof(arr[0]) -1;
    while(num>i){
        ver = arr[num];

        arr[num]=arr[i];

        arr[i]=ver; 

        i++;

        num--;
    }

    for(int i =0;i<5;i++){
        cout<<"现在的数组元素"<<arr[i]<<endl;
    }
    
    system("pause");

    return 0;
}
//ok 这个 也成功了 数组的交换其实是很简单的对于学习过很多关与计算机的我，