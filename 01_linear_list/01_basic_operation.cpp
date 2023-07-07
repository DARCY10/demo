//  顺序表的基本运算
// Created by 1900 on 2023/7/6.
//  元素序号: 1~n(对应索引：0~n-1)
#include "stdio.h"
#include "malloc.h"
#define MAXSIZE 50

typedef char ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

void CreateList(SqList *&L, ElemType a[], int n) {
    L = (SqList*) malloc(sizeof(SqList));
    for (int i = 0; i < n; i++) {
        L->data[i] = a[i];
    }
    L->length = n;
}

void InitList(SqList *&L) {
    L = (SqList*) malloc(sizeof(SqList));
    L->length = 0;
}

void DestroyList(SqList *&L) {
    free(L);
}

bool ListEmpty(SqList *L) {
    return L->length == 0;
}

int ListLength(SqList *L) {
    return L->length;
}

void DispList(SqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%c ", L->data[i]);
    }
    printf("\n");
}

bool GetElem(SqList *L, int i, ElemType &e) {
    if (i < 1 || i > L->length) {
        return false;
    }
    e = L->data[i - 1];
    return true;
}

int LocateElem(SqList *L, ElemType e) {
    int i = 0;

    while (i < L->length && L->data[i] != e) {
        i++;
    }

    if (i >= L->length) {
        return 0;
    }

    return i + 1;
}

bool ListInsert(SqList *&L, int i, ElemType e) {
    if (i < 1 || i > L->length) {
        return false;
    }

    int j;
    i--;
//    将data[i]及其后面元素后移一个位置
    for (j = L->length; j > i; j--) {
        L->data[j] = L->data[j - 1];
    }

    L->data[i] = e;     // 插入元素
    L->length++;        // 表长加1
    return true;
}

bool ListDelete(SqList *&L, int i, ElemType &e) {
    if (i < 1 || i > L->length) {
        return false;
    }

    int j;
    i--;
    e = L->data[i];     //  保存被删元素
//    将data[i]及其后面元素前移一个位置
    for (j = i; j < L->length; j++) {
        L->data[j] = L->data[j + 1];
    }

    L->length--;
    return true;
}