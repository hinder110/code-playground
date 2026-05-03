#include"iostream"
using namespace std;

int main(){

    int arr[5]={300,350,200,400,250};

    int max = 0;

    //zhe li de hua jiu shi bi jiao arr zhong de mei yi ge zhi he max de daxiao ranhou huan zhi 
    
    for(int i = 0; i < 5; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    cout << "最大值为"<<max<<endl;

    system("pause");

    return 0;
}
//  ok这里的话是已经成功了，这个就是最简单的排序，ok我记得在C语言中也是学了这个！！！