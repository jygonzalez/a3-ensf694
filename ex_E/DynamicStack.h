/**
 *  File Name: DynamicStack.h
 *  Assignment: ENSF 694 Summer 2024 - Lab 3 Exercise E
 *  Created by: Mahmood Moussavi on 2024-04-09.
 *  Completed by: Yael Gonzalez
 *  Submission Date: July 17, 2024
 */

#ifndef DynamicStack_H
#define DynamicStack_H

#include <iostream>
using namespace std;

class DynamicStack
{
private:
    int entry;
    int initial_capacity;
    int current_capacity;
    int *array;

public:
    DynamicStack(int n = 5);
    /* PROMISES: Sets value of entry to zero, initial_capacity and current_capacity to n,
     * and allocates memory space for array */

    /* copy ctor*/
    DynamicStack(DynamicStack const &);
    /* PROMISES: A copy of the stack initialized with its current members */

    ~DynamicStack();
    /* PROMISES: Deallocates memory space allocated for array*/

    int top() const;
    /* PROMISES: Returns the value at the top of the stack */

    int size() const;
    /* PROMISES: Returns the number of values stored in the stack */

    bool empty() const;
    /* PROMISES: Returns true if stack is empty */

    int capacity() const;
    /* PROMISES: Returns current capacity of the array in the stack */

    DynamicStack &operator=(const DynamicStack &);
    /* PROMISES: Handles assignment operation for a DynamicStack object */

    void push(const int &v);
    /* PROMISES: The value of v is added at the top of the stack. If the array is full,
     * the current capacity of the array is doubled, then the value of v is added.
     */

    int pop();
    /* PROMISES: Removes the element at the top of the stack. If, only one fourth of
     * the array is full,  and the array's capacity is greater than it's initial capacit, the
     * capacity of the array is halved.
     */

    void clear();
    /* PROMISES: Removes all the entry values from the stack and if necessary resizes
     * the array to its initial capacity.
     */

    void display();
    /* PROMISES: Displays all the existing values in the stack */
};

#endif
