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
    t--; 
    while(t >= b) 
    visit(*t--); 
    printf("\n"); 
    return Ok; 
} 
char dic[40] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
Status visit(SElemType c) 
{ 
    printf("%c",dic[c]); 
    return Ok; 
} 

int main() 
{ 
    SqStack a;
    SqStack *ans = &a;
    long long n,m;
    while(cin >> n >> m){
        if(n < 0)   cout << '-';
        n = abs(n);
        InitStack(ans);
        while(n){
            Push(ans,n%m);
            n /= m;
        }
        StackTraverse(ans,visit);
    }
    return 0; 
} 

