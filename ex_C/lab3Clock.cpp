/**
 *  File Name: lab3Clock.cpp
 *  Assignment: ENSF 694 Summer 2024 - Lab 3 Exercise C
 *  Created by: Mahmood Moussavi
 *  Completed by: Yael Gonzalez
 *  Submission Date: July 17, 2024
 */

#include "lab3Clock.h"

Clock::Clock() : hour(0), minute(0), second(0) {}

Clock::Clock(int seconds) : hour(0), minute(0), second(0)
{
    if (seconds >= 0)
    {
        sec_to_hms(seconds);
    }
}

Clock::Clock(int h, int min, int sec) : hour(h), minute(min), second(sec)
{
    if (h < 0 || h > 23 || min < 0 || min > 59 || sec < 0 || sec > 59)
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
}

int Clock::get_hour() const
{
    return hour;
}

int Clock::get_minute() const
{
    return minute;
}

int Clock::get_second() const
{
    return second;
}

void Clock::set_hour(int h)
{
    if (0 <= h && h <= 23)
    {
        hour = h;
    }
}

void Clock::set_minute(int min)
{
    if (0 <= min && min <= 59)
    {
        minute = min;
    }
}

void Clock::set_second(int sec)
{
    if (0 <= sec && sec <= 59)
    {
        second = sec;
    }
}

void Clock::increment()
{
    int curr_secs = hms_to_sec(); // Current clock in seconds
    sec_to_hms(curr_secs + 1);    // Increment clock by 1 second
}

void Clock::decrement()
{
    int curr_secs = hms_to_sec(); // Current clock in seconds
    if (curr_secs == 0)           // 00:00:00
    {
        sec_to_hms(86399); // Decrement to 23:59:59
    }
    else
    {
        sec_to_hms(curr_secs - 1); // Decrement clock by 1 second
    }
}

int Clock::hms_to_sec()
{
    return hour * 3600 + minute * 60 + second;
}

void Clock::sec_to_hms(int seconds)
{
    hour = (seconds / 3600) % 24;
    seconds %= 3600;
    minute = seconds / 60;
    second = seconds % 60;
}

void Clock::add_seconds(int seconds)
{
    assert(seconds > 0);
    int curr_secs = hms_to_sec();    // Current clock in seconds
    sec_to_hms(curr_secs + seconds); // Increment clock by specified seconds
}
