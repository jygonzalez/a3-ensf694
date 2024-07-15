/**
 *  File Name: CircularQueue.cpp
 *  Assignment: ENSF 694 Summer 2024 - Lab 3 Exercise D
 *  Created by: Mahmood Moussavi on 2024-04-09.
 *  Completed by: Yael Gonzalez
 *  Submission Date: July 17, 2024
 */

#include "CircularQueue.h"

CircularQueue::CircularQueue() : head(1), tail(1), count(0) {}

bool CircularQueue::isFull() const
{
    return head == tail + 1;
}

bool CircularQueue::isEmpty() const
{
    return head == tail;
}

int CircularQueue::enqueue(int element)
{
    if (isFull())
    {
        cout << "Error: Queue is full" << endl;
    }
    else
    {
        tail = (tail + 1) % SIZE;
        arr[tail] = element;
        count++;
    }

    return tail;
}

int CircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Error: Queue is empty" << endl;
    }
    else
    {
        head = (head + 1) % SIZE;
        count--;
    }

    return head;
}

int CircularQueue::counter() const
{
    return count;
}

const int *CircularQueue::get_arr() const
{
    return arr;
}

void CircularQueue::displayQueue() const
{
    int idx = (head + 1) % SIZE;

    if (isEmpty())
    {
        cout << "Queue is empty";
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << arr[idx] << " ";
            idx++;
        }
    }

    cout << endl;
}
