/**
* brief: 数组实现的顺序表，线性表
* Created by lzy on 2024-09-08.
*/
#include  <stdio.h>
#include <stdlib.h>

typedef int E;  // 方便更换其他类型

const int DEFAULT_capacity = 10;

struct List
{
    E * array;  //指向顺序表的底层数组
    int capacity;
    int size;
};

typedef struct List * ArrayList;

_Bool initList(ArrayList list, int init_capacity)
{
    list->array = (E*)malloc(sizeof(E) * init_capacity);
    if (list->array == NULL) return 0;
    list->capacity = init_capacity;
    list->size = 0;
    return  1;
}

_Bool initList_0(ArrayList list)
{
    return  initList(list, DEFAULT_capacity);
}

_Bool insertList(ArrayList list, E e, int index)
{
    if(index < 1 || index > list->size + 1) return 0; // 如果在非法位置插入，返回0表示插入操作执行
    if(list->size == list->capacity)
    {
        int new_capacity = list->capacity + (list->capacity >> 1);   // 当list的容量已满，则进行扩容
        E * new_array = realloc(list->array, new_capacity * sizeof(E));  // 使用realloc进行数组扩容
        if (new_array == NULL)
        {
            return 0;
        }
        list->array = new_array;
        list->capacity = new_capacity;
    }
    for (int i = list->size; i >= index; i--)
    {
        list->array[i] = list->array[i - 1];
    }
    list->array[index - 1] = e;
    list->size++;
    return  1;
}

_Bool removeList(ArrayList list, int index)
{
    if (index < 1 || index > list->size) return 0;
    for ( int i = index - 1; i < list->size - 1; i++ )
    {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    return  1;
}

int getSize(ArrayList list)
{
    return  list->size;
}

E * getElement(ArrayList list, int index)
{
    if (index < 1 || index > list->size) return NULL;
    return  &list->array[index - 1];
}

int findFirst(ArrayList list, E e)
{
    for (int i = 0; i < list->size; ++i)
    {
        if (list->array[i] == e) return  i + 1;
    }
    return -1;
}

int findLast(ArrayList list, E e)
{
    for (int i = list->size - 1; i >= 0; --i)
    {
        if (list->array[i] == e) return i + 1;
    }
    return -1;
}

void printList(ArrayList list)
{
    for ( int i = 0; i < list->size; i++ )
    {
        // printf("%d ", list->array[i]);
        printf("%d%s", list->array[i], i == list->size - 1 ? ", " : " ");
    }
    printf("size is %d, capacaty is %d\n", list->size, list->capacity);
}

int main(int argc, char** argv)
{
    int a = -1;
    struct List list;
    if (initList_0(&list))
    {
        printf("init list success, capacity: %d\n", list.capacity);
        insertList(&list, 222, 1);
        printList(&list);
        insertList(&list, 110, 1);
        printList(&list);
        insertList(&list, 333, 3);
        printList(&list);

        for (int i = 0; i < 15; ++i)
        {
            insertList(&list, i*10, i+1);
        }
        printf("list.get(3): %d\n", *getElement(&list, 3));
        printf("list.findFirst(110): %d\n", findFirst(&list, 110));
        printf("list.findLast(30): %d\n", findLast(&list, 110));

        printf("&a=%p", &a);
        printf(", &list.array[10]=%p\n", &list.array[10]);

        removeList(&list, 9);
        printList(&list);
        removeList(&list, 9);
        printList(&list);
    } else
    {
        printf("init list failed\n");
    }



}
