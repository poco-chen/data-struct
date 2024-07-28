//
// Created by 陈宇轩 on 2024/7/26.
//

#ifndef ADD_TWO_INT_LINKLIST_H
#define ADD_TWO_INT_LINKLIST_H
typedef struct node//普通节点类型
{
    int data;
    struct node *next;
}node;

typedef struct head//头节点类型
{
    node *front;
    int len;
    char sign;
    node *rear;
}head;
/*函数功能：将一个整型数据一位位存储在带头节点的链表中
 * 函数参数 ：@ int x需要存储的整数
 * 函数返回值：返回存储该整数的链表的头节点
 */
//其中存储分为两个步骤step1从整数中取出它的每一位
//step2把他的每一位存储到链表中去（使用头插法）
head* storage_int(int x);

/*
 * 函数功能：实现两个被存储在链表中的整数的相加
 * 函数参数：@head *a
 *          @head *b两个整数被存储的链表中
 * 函数返回值：返回两个整数相加后的结果
 */

int Add_int(head *a,head *b);


void Add_node(head *h,int x );
void print_LINK_LIST(node * l);
int obtain_list(head *l);
#endif //ADD_TWO_INT_LINKLIST_H
