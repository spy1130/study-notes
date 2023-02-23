#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct person{
    char name[128];
    int age;
};

int comparePerson(void *data1,void *data2){
    struct person* p1=data1;
    struct person* p2=data2;
    if(strcmp(p1->name,p2->name)==0 && p1->age == p2->age){
        return 1;
    }else{
        return 0;
    }
}
int findArray(void*array,int eleSize,int len,void *data,int(*mycompare)(void*,void*))
{
    char *p=array;
    for(int i =0;i<len;i++){
        //获取到每个元素的首地址
        char * eleAddr =p+ eleSize *i;
        if(mycompare(data,eleAddr)){
            return 1;
        }
    }
    return 0;
}


int main(){
    struct person personArray[]=
    {
        {"aaa",18},
        {"bbb",19},
        {"ccc",20},
        {"ddd",21},
    };
    int len = sizeof(personArray)/ sizeof(struct person);
    struct person p={"ccc",20};
    int ret =findArray(personArray,sizeof(struct  person),len,&p,comparePerson);
    if(ret){
        printf("找到了");
    }else{
        printf("未找到");
    }
    system("pause");
    return 0;
}