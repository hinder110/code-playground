#include<iostream>

using namespace std;

void selectionSort(int *arr,int len){
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

}

void insertion_sort(int arr[],int len){
    for(int i = 1; i<len ; i++){
        int temp = arr[i];
        int j = i;
        while (j>0&&arr[j-1]>temp)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=temp;
        /*zheli de guanjian dianshi nidei lijie zheg for de 
        duiyu arr[i]de yige yidong zuoyong ,zheli weism yong de shi j
        erbuhsi i ne woxian de huajiushi weil i shi weil zhao dao nage
        yuansu (yaoyidongde yuansu er jde zuoyongshi jiang i arr[i],dezhi yong temp 
        xiang qian yidong ,yci zheli de guanjian dian shi temp erbushi i he j
        )
        */
        
    }
}

void shell_sort(int* arr,int len){
    for(int gap = len/2;gap>0 ; gap/=2){
        for (int i = gap; i < len; i++)
        {
            int temp = arr[i];
            int j = i ;
            //kaishi yid ong
            while (j>=gap&&arr[j-gap]>temp)
            {
                arr[j] = arr[j-gap];
                j-=gap;
                
            }
            arr[j]= temp;
            
        }
        
    }
}

void printarr(int *arr,int len){
    for (int i = 0; i < len ; i++)
    {
        cout<<arr[i]<<endl;     /* code */
    }
    
}

int main(){

    int arr[10]={1,2,9,7,5,6,4,3,8,10};
    
    int len = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr,len);

    insertion_sort(arr,len);
    /*shi xian cheng gong l*/

    shell_sort(arr,len);

    printarr(arr,len);

    system("pause");
}