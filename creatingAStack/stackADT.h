#ifndef STACKADT_H
#define STACKADT_H


/**
6 Operations in our stack

initStack

isFull

isEmpty

push

top

pop


*/


template <class Type>
class stackADT
{
    public:
        virtual void initStack() = 0;
            // Method to init stack to an empty state

        virtual bool isFull() const = 0;
            // returns stack is full

        virtual bool isEmpty() const = 0;
            // returns stack is empty

        virtual void push(const Type& item) = 0;
            // add item to top of stack

        virtual Type top() const = 0;
            // return top most element of stack

        virtual void pop() = 0;
            // remove top most element from stack

};

#endif // STACKADT_H
