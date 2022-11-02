#include <iostream>

class Stack
{
    private:
        int stacklist[20];
        int top;

    public:
        Stack(void);
        void Push(const int item);
        int Pop(void);
        void ClearStack(void);
        int Peek(void) const;
        int StackEmpty(void) const;
        int StackFull(void) const;

};

Stack::Stack(void)
{
    top = -1;
}

void Stack::Push(const int& item)
{
    if(top == MaxStackSize-1)
        exit(1);
    top++;
    stacklist[top] = item;
}

int Stack::Pop(void)
{
    int temp;
    if(top==-1)
        exit(1);
    temp = stacklist[top];
    top--;
    return temp;
}

int Stack::Peek(void) const
{
    int temp;
    if(top==-1)
        exit(1);
    temp = stacklist[top];
    return temp;
}

void Stack::ClearStack(void)
{
    top -= 1;
}

int Stack::StackEmpty(void) const
{
    return top==-1;
}

int Stack::StackFull(void) const
{
    return top==(MaxStackSize-1);
}
