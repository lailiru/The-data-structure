/***************************************************************************************
 *    FileName                    :    stack.c
 *    CopyRight                   :    1.0
 *    ModuleName                  :    Collection management module
 *
 *    Create Data                 :    2016/01/24
 *    Author/Corportation         :    lailiru
 *
 *    Abstract Description        :    栈各种操作的实现
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Date            Revised By            Item            Description
 *    1     v1.0        2016/01/24           lailiru                              Create this file
 *
 ***************************************************************************************/
/**************************************************************
*    Debug switch Section
**************************************************************/
/**************************************************************
*    Include File Section
**************************************************************/
#include "stdio.h"
#include "stdlib.h"
/**************************************************************
*    Macro Define Section
**************************************************************/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define ERRORFLOW -1
#define OVERFLOW -1 
typedef char ElemType;
/**************************************************************
*    Struct Define Section
**************************************************************/
typedef struct{
        ElemType *elem; // 存储空间的基址 
        int top;        //栈顶位标    
        int size;        // 当前分配的存储容量
        int increment;  // 扩容时增加的存储容量
}SqStack;
/**************************************************************
*    Prototype Declare Section
**************************************************************/
/**************************************************************
*    Global Variable Declare Section
**************************************************************/
/**************************************************************
*    File Static Variable Define Section
**************************************************************/
/**************************************************************
*    Function Define Section
**************************************************************/
/**
 *    @description    初始化顺序栈S
 *    @param            S:欲初始化的顺序栈
 *                    size:当前分配的存储容量
 *                    inc:扩容时增加的存储容量
 *    @return            初始化成功返回1
 */
int InitStack_Sq(SqStack &S,int size,int inc){
    S.elem = (ElemType *)malloc(size*sizeof(ElemType));
    if(NULL==S.elem) 
        return OVERFLOW;
    S.top = 0;
    S.size = size;
    S.increment = inc;
    return OK;    
}

/**
 *    @description    判断栈是否为空
 *    @param            S:所要判空的栈
 *    @return            若栈为空返回1，否则返回0
 */
 int StackEmpty_Sq(SqStack S){
     if(S.top==0)
        return TRUE;
     return FALSE;
}

/**
 *    @description    入栈
 *    @param            S:栈
 *                    e:要入栈的元素
 *    @return            入栈成功返回1
 */
int Push_Sq(SqStack &S,ElemType e){
ElemType *p;
if(S.top>=S.size){
  p=(ElemType *)realloc(S.elem,(S.size+S.increment)*sizeof(ElemType));
if(NULL==p) return OVERFLOW;
S.elem=p;
S.size+=S.increment;
}
S.elem[S.top++]=e;
return OK;
}

 /**
 *    @description    取栈顶元素
 *    @param            S:栈
 *                    e:所取出的栈顶元素
 *    @return            取出成功返回1，否则返回0
 */
int GetTop_Sq(SqStack S,ElemType &e){
    ElemType *p;
    if(S.top<=0)
        return ERROR;
    e = S.elem[S.top-1];
    return OK;
}

 /**
 *    @description    出栈
 *    @param            S:栈
 *                    e:所取出的元素
 *    @return            取出成功返回1
 */
int Pop_Sq(SqStack &S,ElemType &e){
     ElemType *p;
     if(S.top<=0)
         return ERRORFLOW;
     S.top--;
     e = S.elem[S.top];
     return OK;
 }
 
 void main()
{
 SqStack S;
 int a,i,k;
 InitStack_Sq(S,10,5);
 printf("%d\n",StackEmpty_Sq(S));
 for(i=0;i<5;i++)
      Push_Sq(S,i);
 printf("%d\n",StackEmpty_Sq(S));
 GetTop_Sq(S,k);
 printf("%d\n",k);
 for(i=0;i<5;i++){
    Pop_Sq(S,a);
    printf("%d",a);
    } 
 }