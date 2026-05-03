#include<stdio.h>
/*#include<coino.h>*/
#include<stdlib.h>

typedef struct _Student
{   
    int stdNum;
    char name[20];
    int score;
    /* data */
}Student;

typedef struct _Node
{   
    Student student;
    struct _Node* next;
    /* data */
}Node;
void welcome(){
    	printf("///\n\
//                          _ooOoo_                          //\n\
//                         o8888888o                         //\n\
//                         88\" . \"88                         //\n\
//                         (| ^_^ |)                         //\n\
//                         O\\  =  /O                         //\n\
//                      ____/`---'\\____                      //\n\
//                    .'  \\\\|     |//  `.                    //\n\
//                   /  \\\\|||  :  |||//  \\                   //\n\
//                  /  _||||| -:- |||||-  \\                  //\n\
//                  |   | \\\\\\  -  /// |   |                  //\n\
//                  | \\_|  ''\\---/''  |   |                  //\n\
//                  \\  .-\\__  `-`  ___/-. /                  //\n\
//                ___`. .'  /--.--\\  `. . ___                //\n\
//               ."" '<  `.___\\_<|>_/___.'  >'"".                //\n\
//            | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |            //\n\
//            \\  \\ `-.   \\_ __\\ /__ _/   .-` /  /            //\n\
//     ========`-.____`-.___\\_____/___.-`____.-'========     //\n\
//                          `=---='                          //\n\
//     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     //\n\
//           佛祖保佑       永不宕机     永无BUG             //\n\
///\n");
}

void inputStudent(Node* head){
    Node* fresh = malloc(sizeof(Node));
    fresh->next=NULL;
    scanf(%d%s%d,&fresh->student.stdNum,&fresh->student.name,&fresh->student.score);
    Node* move =head;
    while (move->next!=NULL)
    {   
        move = move->next;
        /* code */
    }
    move->next= fresh;
    

}


int main(){
    //chuanjian head Node 
    Node* head = malloc(sizeof(Node));
    head->next = NULL;
    welcome();
    free(head);
    return 0;
}
