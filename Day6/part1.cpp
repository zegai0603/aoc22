#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h> //required to use the find function and other functions
#include <vector>
using namespace std;

int main()
{
    string line, test;
    int repeat, checker = 1;
    ifstream file("day6input.txt");

    getline(file, line);
    for (int i = 0; i < line.length(); i++)
    {
        test = line.substr(i, 4);
        repeat = 0;
        for (int y = 0; y < 4; y++)
        {
            for (int z = 0; z < 4; z++)
            {
                if (test[y] == test[z])
                {
                    repeat += 1;
                }
            }
        }
        if (repeat <= 4)
        {
            cout << test << endl;
            cout << i + 4 << endl;
            break;
        }
    }
}
