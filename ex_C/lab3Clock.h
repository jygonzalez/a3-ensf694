/**
 *  File Name: lab3Clock.h
 *  Assignment: ENSF 694 Summer 2024 - Lab 3 Exercise C
 *  Created by: Mahmood Moussavi
 *  Completed by: Yael Gonzalez
 *  Submission Date: July 17, 2024
 */

#ifndef lab3_exe_C_Clock
#define lab3_exe_C_Clock

#include <assert.h>
#include <iostream>

/**
 * The following class definition represnets a clock and contains three
 * private data members hour, minute, and second, which respectively describe a clock
 * in the format hours:minutes:seconds.
 */
class Clock
{
public:
    Clock();
    /**
     * PROMISES:
     *  Initializes the clock with hour, minute, and second each set to zero.
     */

    Clock(int seconds);
    /**
     * PROMISES:
     *  Initializes the clock hour, minute, and second members respectively with the
     *  converted supplied value of seconds.
     *
     *  For example, if the argument value is 4205, the values of data members hour,
     *  minute and second will be: 1, 10, and 5 respectively.
     *
     *  If the given argument value is negative the data members will all be initialized to zeros.
     */

    Clock(int h, int min, int sec);
    /**
     * PROMISES:
     *  Initializes the clock hour, minute, and second members with the respective supplied
     *  arguments.
     *
     *  The data members will all be initialized to zeroes if any of the following illegal
     *  operations is attempted:
     *  - The given values for second or minute are greater than 59 or less than zero.
     *  - The given value for hour is greater than 23 or less than zero.
     */

    int get_hour() const;
    /**
     * PROMISES:
     *  Retuns the hours of a clock.
     */

    int get_minute() const;
    /**
     * PROMISES:
     *  Retuns the minutes of a clock.
     */

    int get_second() const;
    /**
     * PROMISES:
     *  Retuns the seconds of a clock.
     */

    void set_hour(int h);
    /**
     * PROMISES:
     *  Sets a new value to the hours of a clock with the value of h.
     */

    void set_minute(int min);
    /**
     * PROMISES:
     *  Sets a new value to the minutes of a clock with the value of m.
     */

    void set_second(int sec);
    /**
     * PROMISES:
     *  Sets a new value to the seconds of a clock with the value of s.
     */

    // Implementer functions
    void increment();
    /**
     * PROMISES:
     *  Increments the value of the clock's time by one.
     *  For example, if the value of the time is 00:00:00 it will change to 00:00:01.
     */

    void decrement();
    /**
     * PROMISES:
     *  Decrements the value of the clock's time by one.
     *  For example, if the value of the time is 00:00:00 it will change to 23:59:59.
     */

    void add_seconds(int seconds);
    /**
     * REQUIRES:
     *  seconds > 0, i.e., argument is a positive integer of seconds.
     * PROMISES:
     *  Adds the value of supplied argument seconds to the value of the current time.
     *  For example, if the clock’s time is 23:00:00, and the given argument is 3601 seconds,
     *  the time will change to: 00:00:01.
     */

private:
    int hour;   // Cannot be less than 0 or more than 23
    int minute; // Cannot be less than 0 or more than 59
    int second; // Cannot be less than 0 or more than 59

    int hms_to_sec();
    /**
     * PROMISE:
     *  Returns the total value of the data members in a Clock object, in seconds.
     *
     *  For example, if the time value of a Clock object is 01:10:10, returns 4210
     *  seconds.
     */

    void sec_to_hms(int seconds);
    /**
     * PROMISE:
     *  Sets the total values for the Clock object data members with the supplied value of
     *  seconds.
     *
     *  For example, if the supplied argument is 4210 seconds, the data members values will be:
     *  1, 10 and 10, respectively for hour, minute, and second.
     */
};

#endif
