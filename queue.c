
 /***************************************************************************************
 *	FileName					:	queue.c
 *	CopyRight					:	1.0
 *	ModuleName					:	Collection management module
 *
 *	Create Data					:	2016/01/24
 *	Author/Corportation			:	lailiru
 *
 *	Abstract Description		:	队列各种操作的实现
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Date			Revised By			Item			Description
 *	1	v1.0		2016/01/24		lailiru						      Create this file
 *
 ***************************************************************************************/
/**************************************************************
*	Debug switch Section定义调试用的宏
**************************************************************/
//#define Debug_Switch
/**************************************************************
*	Include File Section包含头文件
**************************************************************/
#include "stdio.h"
#include "stdlib.h"
/**************************************************************
*	Macro Define Section定义平时用的宏
**************************************************************/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define ERRORFlow -1
#define OVERFLOW -1 
typedef char ElemType;
/**************************************************************
*	Struct Define Section定义结构体
**************************************************************/
typedef struct{
		ElemType *elem;  //存储空间的基址
		int front;       //队头位标
		int rear;        //队尾位标
		int maxsize;     //最大长度
}SqQueue;
/**************************************************************
*	Prototype Declare Section写函数声明
**************************************************************/
/**************************************************************
*	Global Variable Declare Section全局变量
**************************************************************/
/**************************************************************
*	File Static Variable Define Section文件内的静态变量
**************************************************************/
/**************************************************************
*	Function Define Section函数定义
**************************************************************/
/**
 *	@description	初始化队列
 *	@param			Q:欲初始化的队列
 *					size:队列的长度						
 *	@return			初始化成功返回1
 */
int InitQueue_Sq(SqQueue &Q,int size){
	Q.elem=(ElemType *)malloc(size*sizeof(ElemType));
	if(NULL==Q.elem)
		return OVERFLOW;
	Q.maxsize = size;
	Q.front = Q.rear = 0;
	return  OK;
}

 /**
 *	@description	判断队列是否为空
 *	@param			Q:所要判断的队列
 *	@return			若队列为空返回1，否则返回0
 */
 int QueueEmpty_Sq(SqQueue Q){
 	if(Q.front==Q.rear)
 		return TRUE;
 	return FALSE;	 
 }

 /**
 *	@description	求队列的长度
 *	@param			Q:所要求长度的队列
 *	@return			返回队列长度
 */
 int QueueLength_Sq(SqQueue Q)
{ if(Q.front==Q.rear)
    return 0;
  if(Q.front==(Q.rear%Q.maxsize))
     return Q.maxsize;
  if(Q.front<Q.rear)
     return(Q.rear-Q.front);
   if(Q.rear<Q.front) 
     return Q.rear+Q.maxsize-Q.front;
}

/**
 *	@description	入队
 *	@param			Q:队列
 *					e:要入队的元素
 *	@return			入队成功返回1
 */
 int EnQueue_Sq(SqQueue &Q,ElemType e){
 	if((Q.rear+1)%Q.maxsize==Q.front)
 		return ERROR;
 	Q.elem[Q.rear] = e;
 	Q.rear = (Q.rear+1)%Q.maxsize;
 	return OK; 
 }

 /**
 *	@description	出队
 *	@param			Q:队列
 *					e:所取出的元素
 *	@return			出队成功返回1
 */
 int DeQueue_Sq(SqQueue  &Q,ElemType &e){
 	if(Q.front==Q.rear)
 		return ERROR;
 	e = Q.elem[Q.front];
 	Q.front = (Q.front+1)%Q.maxsize;
 	return OK;
 }

