#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma comment(lib,"./linklist.lib")
int main()
{
    struct node *list1 = creatlist();
    insertbyhead(list1, 1);
    insertbyhead(list1, 2);
    printlist(list1);
    insertbytail(list1, -3);
    printlist(list1);
    insert(list1, 8, -3);
    printlist(list1);
    deletebyhead(list1);
    printlist(list1);
    deletebytail(list1);
    printlist(list1);
    deletenode(list1, -1);
    printlist(list1);
    deletenode(list1, 8);
    printlist(list1);
    deletenode(list1, 1);
    printlist(list1);
    destroy_LinkList(list1);
    system("pause");
    return 0;
}
