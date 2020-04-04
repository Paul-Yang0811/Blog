/*
 * 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *pNext;
} list_t;

list_t *create_list(list_t *pHead, int n)
{
    list_t *head = pHead;

    while (n) {
        list_t *p = (list_t *)malloc(sizeof(list_t));
        if (p == NULL) {
            printf("malloc failed!\n");
            exit(-1);
        }
        p->data = n--;
        printf("set data=%d\n", p->data);

        head->pNext = p;
        p->pNext = NULL;
        head = p;
    }

    return pHead;
}

void print_list(list_t *pHead) {
    while (pHead != NULL) {
        printf("print data=%d\n", pHead->data);
        pHead = pHead->pNext;
    }
}

int main()
{
    list_t *pHead = (list_t *)malloc(sizeof(list_t));
    if (pHead == NULL) {
        printf("malloc failed!\n");
        exit(-1);
    }
    pHead->data = -1;
    pHead = create_list(pHead, 4);

    print_list(pHead);

    return 0;
}