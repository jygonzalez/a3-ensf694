/**
 *  File Name: CircularQueue.h
 *  Assignment: ENSF 694 Summer 2024 - Lab 3 Exercise D
 *  Created by: Mahmood Moussavi on 2024-04-09.
 *  Completed by: Yael Gonzalez
 *  Submission Date: July 17, 2024
 */

#ifndef CircularQueue_h
#define CircularQueue_h

#include <iostream>
using namespace std;
#define SIZE 10 // Set to 4 to test data1.txt. Set to 10 to test data2.txt.
typedef int TYPE;

class CircularQueue
{
private:
    TYPE head;      // position of head
    TYPE tail;      // position of tail
    TYPE arr[SIZE]; // a queue array with maximum SIZE elements
    TYPE count;     // keeps track of number of valid data in the queue
public:
    CircularQueue();
    /* PROMISES: set initial values for head, tail and count. Also, initializes Queue (array) with zeroes */
    bool isFull() const;
    /* PROMISES: return value is true if queue is full */
    bool isEmpty() const;
    /* PROMISES: return value is true if queue is empty */
    TYPE enqueue(int v);
    /* PROMISES: adds value v to the tail, increments count of values and returns the new position of the tail */
    TYPE dequeue();
    /* PROMISES: returns the position of the element representing, eliminates its value and decrements count */
    void displayQueue() const;
    /* PROMISES: dispalys the existing values in the queue */
    TYPE counter() const;
    /* PROMISES: returns the number of values in the queue */
    const TYPE *get_arr() const;
    /* PROMISES: returns the address of the array arr */
};
#endif /* CircularQueue_h */
