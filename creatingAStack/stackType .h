#ifndef STACKTYPE _H
#define STACKTYPE _H

#include <iostream>
#include <cassert>
#include "stackADT.h"


using namespace std;


template <class Type>
class stackType
{
    public:
        stackType(int stackSize = 100);

        const stackType<Type>& operator=(const stackType<Type> & other);
        // overload the assignment operator

        stackType(const stackType<Type>& otherStack);

        void initStack();
            // declared in parent, must be defined in child

        bool isFull() const ;

        bool isEmpty() const ;

        void push(const Type& item);

        Type top() const;

        void pop();



        ~stackType();

    private:
        int maxStackSize;
        int stackTop;
        Type *list;

        void copyStack(const stackType<Type>& otherStack);
};


template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
        {
            cout << "Size of array is invalid" << endl;
            cout << "Setting stack size to 100" << endl;

            maxStackSize = 100;
        }
    else
        {
            maxStackSize = stackSize;
        }

    stackTop = 0;
    list = new Type[maxStackSize];

}

template <class Type>
void stackType<Type>::initStack()
{
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isFull() const
{
    return (stackTop == maxStackSize);
}

template <class Type>
bool stackType<Type>::isEmpty() const
{
    return stackTop == 0;
}

template <class Type>
void stackType<Type>::push(const Type& item)
{
    if (!isFull())
        {
            list[stackTop] = item;
            stackTop++;
        }
    else
        {
            cout << "Stack is full, cannot add more elements :^( " << endl;
        }
}

template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != 0);
    return list[stackTop - 1];
}

template <class Type>
void stackType<Type>::pop()
{
    if (!isEmpty())
        {
            stackTop--;
        }
    else
        {
            cout << "Stack is empty, cannot pop an empty stack" << endl;
        }
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    list = new Type[maxStackSize];

    for (int i = 0; i < stackTop; i++)
        {
            list[i] = otherStack.list[i];
        }
}



template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = nullptr;

    copyStack(otherStack);
}

template <class Type>
const stackType<Type> & stackType<Type>::operator=(const stackType<Type>& otherStack)
{
    if (this != &otherStack)
        {
            copyStack(otherStack);
        }
    return *this;
}


template <class Type>
stackType<Type>::~stackType()
{
    delete [] list;
}




#endif // STACKTYPE _H
