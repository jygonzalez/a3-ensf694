/**
 *  File Name: DynamicStack.cpp
 *  Assignment: ENSF 694 Summer 2024 - Lab 3 Exercise E
 *  Created by: Mahmood Moussavi on 2024-04-09.
 *  Completed by: Yael Gonzalez
 *  Submission Date: July 17, 2024
 */

#include "DynamicStack.h"

DynamicStack::DynamicStack(int n) : entry(0),
                                    initial_capacity(n),
                                    current_capacity(n),
                                    array(new int[n]) {}

DynamicStack::DynamicStack(DynamicStack const &stack) : entry(stack.entry),
                                                        initial_capacity(stack.initial_capacity),
                                                        current_capacity(stack.current_capacity),
                                                        array(new int[stack.current_capacity])
{
    if (stack.entry > 0) // If no values in the array, don't copy
    {
        std::copy(stack.array, stack.array + stack.entry, this->array); // Copy of the array
    }
}

DynamicStack::~DynamicStack()
{
    delete[] array;
}

int DynamicStack::top() const
{
    if (empty())
    {
        std::cout << "Cannot peek: Stack is empty." << endl;
        return -1;
    }

    return array[entry - 1];
}

int DynamicStack::size() const
{
    return entry;
}

bool DynamicStack::empty() const
{
    return entry == 0;
}

int DynamicStack::capacity() const
{
    return current_capacity;
}

DynamicStack &DynamicStack::operator=(DynamicStack const &rhs)
{
    if (this != &rhs) // avoid self copy
    {
        delete[] array;
        this->entry = rhs.entry;
        this->initial_capacity = rhs.initial_capacity;
        this->current_capacity = rhs.current_capacity;
        this->array = new int[rhs.current_capacity];
        if (rhs.entry > 0) // If no values in the array, don't copy
        {
            std::copy(rhs.array, rhs.array + rhs.entry, this->array); // Copy of the array
        }
    }

    return *this;
}

void DynamicStack::push(const int &obj)
{
    if (entry == current_capacity)
    {
        current_capacity *= 2;
        DynamicStack temp(*this); // temp value using copy ctor
        *this = temp;             // assignment op
    }

    entry++;
    array[entry - 1] = obj;
}

int DynamicStack::pop()
{
    if (empty())
    {
        std::cout << "Cannot pop: Stack is empty." << endl;
        return -1;
    }

    int popped_value = array[entry - 1];
    entry--;

    if (entry == current_capacity / 4 && current_capacity > initial_capacity)
    {
        current_capacity /= 2;
        DynamicStack temp(*this); // temp value using copy ctor
        *this = temp;             // assignment op
    }

    return popped_value;
}

void DynamicStack::clear()
{
    DynamicStack temp(initial_capacity); // temp value using default ctor
    *this = temp;                        // assignment op
}

void DynamicStack::display()
{
    for (int i = 0; i < entry; i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}
