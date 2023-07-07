//  测试顺序表的基本运算
// Created by 1900 on 2023/7/7.
//
#include "01_basic_operation.cpp"

int main( void ) {
    SqList *L;
    ElemType e;

    printf("The basic operation of sequence list:\n");
    printf("\t(1)Initialize\n");
    InitList(L);

    printf("\t(2)Create sequence list\n");
    ElemType a[] = "abcde";
    CreateList(L, a, 5);

    printf("\t(3)Display sequence list: ");
    DispList(L);

    printf("\t(4)The length of sequence list: %d\n", ListLength(L));
    printf("\t(5)Sequence is %s\n", ListEmpty(L) ? "empty" : "not empty");

    GetElem(L, 3, e);
    printf("\t(6)The third element in sequence list is: %c\n", e);

    printf("\t(7)The location of a in sequence list is %d\n", LocateElem(L, 'a'));

    printf("\t(8)Insert element f in the four position\n");
    ListInsert(L, 4, 'f');
    printf("\t(9)Display sequence list: ");
    DispList(L);

    printf("\t(10)Delete the third element in sequence list\n");
    ListDelete(L, 3, e);
    printf("\t(11)Display sequence list: ");
    DispList(L);

    printf("\t(12)Free sequence list\n");
    DestroyList(L);

    return 0;
}