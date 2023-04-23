#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//定义广义表的数据结构
typedef struct GList{
	int tag; //用以区分是原子结点还是子表结点.当tag为1时，该结点是子表，第二个域为slink，用以存放子表的地址；当tag为0时，该结点是原子结点
	union{
		int data; //用以存放原子结点值，其类型由用户自定义
		GList *slink; //指向子表的指针
	};
	GList *next; //指向下一个表结点
} *GListPtr;
GListPtr GreateGList(GListPtr gl){
	char c;
	scanf("%c", &c);
	if(c != ' '){
		gl = (GListPtr)malloc(sizeof(GListPtr));
		if(c == '('){
			gl->tag = 1;
			gl->slink = GreateGList(gl->slink); //递归构造子表结点
		}else{
			gl->tag = 0; //构造原子结点
			gl->data = c;
		}
	}else{
		gl = NULL;
	}
	scanf("%c", &c);
	if(gl != NULL){
		if(c == ','){
			gl->next = GreateGList(gl->next); //构造后续广义表
		}else{
			gl->next = NULL; //遇到其他符号，如")"或";"时，无后续表
		}
	}
	return gl;
}
void PrintGList(GListPtr gl){
	if(gl != NULL){
		if(gl->tag == 1){
			printf("(");
			if(gl->slink == NULL){
				printf("");
			}else{
				PrintGList(gl->slink); //递归调用输出子表
			}
		}else{
			printf("%c", gl->data); //输出结点数据域值
		}
 
		if(gl->tag == 1){
			printf(")");
		}
 
		if(gl->next != NULL){
			printf(",");
			PrintGList(gl->next); //递归调用输出下一个节点
		}
	}
}
int FindGList(GListPtr gl,int t){
	int mark = 0;
	if(gl != NULL){
		if(gl->tag == 0 && gl->data == t){
			mark = 1;
		}else {
			if(gl->tag == 1){
				mark = FindGList(gl->slink,t);
			}else{
				mark = FindGList(gl->next,t);
			}
		}
	}
	return mark; //若查找成功返回1
}
int main(){

    system("pause");
    return EXIT_SUCCESS;
}
//https://blog.csdn.net/Alexshi5/article/details/99897725