#include <stdio.h> 
#include <malloc.h> 
#include <iostream>
using namespace std;
typedef int SElemType; 
typedef int Status; 
#define INIT_SIZE 100 
#define STACKINCREMENT 10 
#define Ok 1 
#define Error 0 
#define True 1 
#define False 0 
typedef struct 
{ 
    SElemType *base; 
    SElemType *top; 
    int stacksize; 
}SqStack; 
  
//初始化栈 
Status InitStack(SqStack *s) 
{ 
    s->base = (SElemType *)malloc(INIT_SIZE * sizeof(SElemType)); 
    if(!s->base) 
    { 
    puts("存储空间分配失败！"); 
    return Error; 
    } 
    s->top = s->base; 
    s->stacksize = INIT_SIZE; 
    return Ok; 
} 
  
//清空栈 
Status ClearStack(SqStack *s) 
{ 
    s->top = s->base; 
    return Ok; 
} 
  
//栈是否为空 
Status StackEmpty(SqStack *s) 
{ 
    if(s->top == s->base) 
    return True; 
    else
    return False; 
} 
  
//销毁栈 
Status Destroy(SqStack *s) 
{ 
    free(s->base); 
    s->base = NULL; 
    s->top = NULL; 
    s->stacksize=0; 
    return Ok; 
} 
  
//获得栈顶元素 
Status GetTop(SqStack *s, SElemType &e) 
{ 
    if(s->top == s->base) return Error; 
    e = *(s->top - 1); 
    return Ok; 
} 
  
//压栈 
Status Push(SqStack *s, SElemType e) 
{ 
    if(s->top - s->base >= s->stacksize)//栈满 
    { 
        s->base = (SElemType *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemType)); 
        if(!s->base) 
        { 
          puts("存储空间分配失败！"); 
          return Error; 
        } 
        s->top = s->base + s->stacksize;//修改栈顶位置 
        s->stacksize += STACKINCREMENT;//修改栈长度 
    } 
    *s->top++ = e; 
    return Ok; 
} 
  
//弹栈 
Status Pop(SqStack *s, SElemType *e) 
{ 
    if(s->top == s->base) return Error; 
    --s->top; 
    *e = *(s->top); 
    return Ok; 
} 
  
//遍历栈 
Status StackTraverse(SqStack *s,Status(*visit)(SElemType)) 
{ 
    SElemType *b = s->base;//此处不能直接用base或top移动，即不能改变原栈的结构 
    SElemType *t = s->top; 
    while(t > b) 
    visit(*b++); 
    printf("\n"); 
    return Ok; 
} 
  
Status visit(SElemType c) 
{ 
    printf("%d ",c); 
    return Ok; 
} 

int main() 
{ 
    SqStack a; 
    SqStack *s = &a;
    InitStack(s); 
    cout << "Push:  1" << endl;
    cout << "Pop:   2" << endl;
    cout << "Top:   3" << endl;
    cout << "Visit: 4" << endl; 
    cout << "Exit:  0" << endl;
    int kase, x;
    while(cin >> kase && kase){
        switch(kase){
        case 1:
            cin >> x;
            if(Push(s, x))  cout << "Insert finished." << endl;
            else cout << "INsert failed!" << endl;
            break;
        case 2:
            if(Pop(s, &x)){
                cout << "The top of stack is:" << x << endl;
            }
            else    cout << "Pop failed!" << endl;
            break;
        case 3:
            if(GetTop(s, x)){
                cout << "The top of stack is:" << x << endl;
            }
            else    cout << "Pop failed!" << endl;
            break;
        case 4:
            if(s->top != s->base) StackTraverse(s, visit);
            else cout << "Traverse failed!" << endl;
            break;
        }
    }
    return 0; 
} 

