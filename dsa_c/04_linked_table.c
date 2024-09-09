/**
* brief:
* Created by lzy on 2024-09-10.
*/
#include  <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode
{
    E e;   //保存当前元素
    struct ListNode * next;   //指向下一个结点的指针
};

typedef struct ListNode * Node;   //这里我们直接为结点指针起别名，可以直接作为表实现

void initList(Node head) {
    head->next = NULL;   //头结点默认下一个为NULL
}


