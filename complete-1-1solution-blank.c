#include<stdio.h>
#include<stdlib.h>


/*

原程序代码中存在的问题：
2.在程序结束之后，并没有完成对链表占用内存的释放操作
3.在申请空表时，没有对其指针域设空
4.PolyDifferentaion的返回值设置成void也行，在函数体中已经把Ploy的各项都改变了

编写代码时遇到的问题：
1.Attach函数的参数是一个二级指针（否则无法把pRear置向新生成P结点） 而 PolyDifferentaion函数的参数是一个一级指针（改变ploy中每一项的值）
2.如何处理只有常数项的多项式求导和包含常数项的多项式求导（如何遍历链表，删除链表某一个元素）
3.当一个指向结构体的指针被设置NULL的时候，该指针是不能被解引用访问其数据域的

*/
typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;    /* 系数 */
    int expon;    /* 指数 */
    Polynomial link;    /* 指向下一结点 */
};

void Attach( int c, int e, Polynomial *pRear )
{
    /* 将由(c, e)构成的新项插入到pRear间接指向的结点后面 */
    Polynomial P;

    P = (Polynomial)malloc(sizeof(struct PolyNode));  /* 申请一新结点 */
    P->coef = c;    /* 对新结点赋值  */
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P; /* 将P指向的新项插入到当前结果表达式尾项的后面 */
    *pRear = P;         /* 修改pRear值 */
}

Polynomial ReadPoly()
{
    /* 读入并建立多项式 */
    Polynomial  P = NULL, Rear = NULL, t = NULL;
    int c, e;

    /* 为了程序处理方便起见，先构造一个链表头空结点 */
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;

    while ( scanf("%d %d", &c, &e) != EOF ) /*读入当前项系数和指数，直到文件结尾 */
        Attach(c, e, &Rear); /* 将当前项插入多项式尾部 */
    /* 删除临时生成的头结点 */
    t = P;
    P = P->link;
    free(t);
    return P;
}

Polynomial PolyDifferentiation( Polynomial P )
{
    /* 求多项式P的导函数，返回结果多项式 */
    /* 原多项式在求导后即被导函数取代    */

    Polynomial rear = NULL;    /* 用来存储链表当前位置 */

    rear = P;

    if(rear->expon == 0)    /* 如果第一项就是常数项，返回0 */
    {
        rear->coef = 0;
        rear->expon = 0;
    }
    else
    {
        /*
        如果该结点的下一个结点不是空结点，则有可能是常数项；
        如果要删除常数项，则必须要存储常数项前面的一个结点地址；
        所以要判断rear->link是否为空
        */
        while(rear->link != NULL)
        {
             /* 如果下一项是常数项，删除下一项，
             求导当前项，rear设置为扫描到链表尾部，跳出循环 */
            if(rear->link->expon == 0)
            {
                free(rear->link);
                rear->link = NULL;

                rear->coef = (rear->coef)*(rear->expon);    /* 按照求导法则对系数和指数赋值 */
                rear->expon = (rear->expon) - 1;

                rear = NULL;
                break;
            }
            else
            {
                rear->coef = (rear->coef)*(rear->expon);    /* 按照求导法则对系数和指数赋值 */
                rear->expon = (rear->expon) - 1;

                rear = rear->link;
            }
        }
        if(rear != NULL)    /* 有可能没有常数项，则需要对最低幂项单独求导 */
        {
            rear->coef = (rear->coef)*(rear->expon);
            rear->expon = (rear->expon) - 1;

            rear = rear->link;
        }
    }

    return P;
}

void PrintPoly( Polynomial P )
{
    /* 输出多项式 */
    int flag = 0; /* 辅助调整输出格式用 */

    while ( P )
    {
        if (!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

int main()
{
    Polynomial P;

    P = ReadPoly(); /* 读输入多项式 */
    P = PolyDifferentiation( P ); /* 求导函数 */
    PrintPoly( P ); /* 输出多项式 */

    return 0;
}
