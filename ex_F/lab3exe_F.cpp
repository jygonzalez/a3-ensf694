/**
 *  File Name: lab3exe_F.cpp
 *  Assignment: ENSF 694 Summer 2024 - Lab 3 Exercise F
 *  Created by: Mahmood Moussavi on 2024-04-09.
 *  Completed by: Yael Gonzalez
 *  Submission Date: July 17, 2024
 */

#include <vector>
#include <string>
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

typedef vector<string> String_Vector;

String_Vector transpose(const String_Vector &sv);
// REQUIRES:
//    sv.size() >= 1
//    All the strings in sv are the same length, and that length is >= 1.
// PROMISES:
//    Return value is the "transpose" of sv, as defined in the Exercise B
//    instructions.

int main()
{

    const int ROWS = 5;
    const int COLS = 4;

    char c = 'A';
    String_Vector sv;
    sv.resize(ROWS);

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
        {
            sv.at(i).push_back(c);
            c++;
            if (c == 'Z' + 1)
                c = 'a';
            else if (c == 'z' + 1)
                c = 'A';
        }

    cout << "Original Matrix:" << endl;

    for (int i = 0; i < ROWS; i++)
    {
        cout << sv.at(i);
        cout << endl;
    }

    cout << "\nTranspose Matrix:" << endl;

    String_Vector vs = transpose(sv);
    for (int i = 0; i < (int)vs.size(); i++)
        cout << vs.at(i) << endl;

    return 0;
}

String_Vector transpose(const String_Vector &sv)
{
    String_Vector vs;                   // transposed matrix
    const int rows = (int)sv[0].size(); // vs(#rows) = sv(#cols)
    const int cols = (int)sv.size();    // vs(#cols) = sv(#rows)
    vs.resize(rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            vs.at(i).push_back(sv[j].at(i)); // similar to vs[i][j] = sv[j][i]
        }
    }

    return vs;
}
