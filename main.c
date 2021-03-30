#include <stdio.h>
#include "utils.h"

#define SZ 10
#define T char
#define T1 int
#define SIZE 1000
//уже было определено в utils
//#define true 1==1
//#define false 1!=1

typedef int boolean;

//для задания 1
typedef struct
{
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void init()
{
    for (int i=0;i<SZ;++i)
    {
        arr[i]=NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat=dat;
    node->pr=pr;
    int flag;

    if(items==0)
    {
        arr[tail++]=node;
        items++;
    }
    else if (items == SZ)
    {
        printf("%s\n","Queue is full");
        return;
    }
    else
    {
        int i=0;
        int idx=0;
        Node *tmp;
        for(i=head;i<tail;++i)
        {
            idx=i%SZ;
            if (arr[idx]->pr > pr)
                break;
            else
                idx++;
        }
        flag = idx%SZ;
        i++;
        while(i<=tail)
        {
            idx = i%SZ;
            tmp = arr[idx];
            arr[idx]=arr[flag];
            arr[flag]=tmp;
            i++;
        }
        arr[flag]=node;
        items++;
        tail++;
    }
}

Node* rem()
{
    if (items == 0)
    {
        return NULL;
    }
    else
    {
        int idx = head++%SZ;
        Node *tmp = arr[idx];
        arr[idx]=NULL;
        items--;
        return tmp;
    }
}

void printQueue()
{
    printf("[");
    for(int i=0; i< SZ; ++i)
    {
        if(arr[i]==NULL)
        {
            printf("[*,*]");
        }
        else
        {
            printf("[%d,%d]", arr[i]->pr, arr[i]->dat);
        }
    }
    printf("]\n");
}

//для задания 2
int cursor1 = -1;
T1 Stack1[SZ];

//функция для перевода десятичного числа в двоичное и вывода этого числа
void decimalToBinary(int n)
{
    printf("Value input %d\n", n);
    if ( n >= 2 )
    {
        decimalToBinary( n/2 );
    }
    printf("%d", n % 2);
    //printf("\n");
}

boolean pushStack(T1 data)
{
    if(cursor1<SZ)
    {
        Stack1[++cursor1]=data;
        return true;
    }
    else
    {
        printf("%s\n","Stack overflow");
        return false;
    }
}

//Вот тут уже можно поменять непосредственно вывод, в соответствии с заданием
T1 popStack()
{
    if (cursor1 !=-1)
    {
        //decimalToBinary(Stack1[cursor1]);
        return Stack1[cursor1--];
    }
    else
    {
        //printf("%s\n","Stack overflow");
        return -1;
    }
}

int main()
{
    printf("Task 1\n");
    init();
    ins(1,11);
    ins(3,22);
    ins(4,33);
    ins(2,44);
    ins(3,55);
    ins(4,66);
    ins(5,77);
    ins(1,88);
    ins(2,99);
    ins(6,100);
    //для проверки
    //ins(7,1000);
    printQueue();
    printf("Cut sequence\n");
    for(int i = 0; i<7; ++i)
    {
        Node* n = rem();
        printf("pr=%d, dat=%d\n", n->pr, n->dat);
    }
    printQueue();

    ins(1,110);
    ins(3,120);
    ins(6,130);

    printf("New sequence\n");
    printQueue();

    for(int i = 0; i<5; ++i)
    {
        Node* n = rem();
        printf("pr=%d, dat=%d\n", n->pr, n->dat);
    }
    printQueue();

    printf("Task 2\n");

    pushStack('1');
    pushStack('2');
    pushStack('3');
    pushStack('4');
    pushStack('33');
    pushStack('7');
    int tmp1;
    while(cursor1!=-1)
    {
        //decimalToBinary(popStack());
        printf("\n");
        printf("Cursor is %d\n", cursor1);
        printf("%c ", popStack());
        printf("\n");
        //decimalToBinary(popStack());
    }
    return 0;
}
