#include <iostream>
#include <sstream> // required to use stringstream
#include <string>
#include <fstream>
#include <bits/stdc++.h> //required to use the find function and other functions
#include <vector>
using namespace std;
// for * and & operators refer to http://tutors.ics.uci.edu/index.php/tutor-resources/81-cpp-resources/122-cpp-ref-pointer-operators

void splitComma(string str, string *elf1, string *elf2)
{
    int delimIndex = str.find(',');
    int len = str.length();
    *elf1 = str.substr(0, delimIndex);
    *elf2 = str.substr(delimIndex + 1, len - delimIndex - 1);
}

void splitDash(string str, int *elfLower, int *elfUpper)
{
    int delimIndex = str.find('-');
    int len = str.length();
    *elfLower = stoi(str.substr(0, delimIndex));
    *elfUpper = stoi(str.substr(delimIndex + 1, len - delimIndex - 1));
}

int main()
{
    ifstream file("day4input.txt");
    string pair, elf1, elf2, line;
    vector<string> lines;
    int count = 0;
    int elf1Lower, elf1Upper, elf2Lower, elf2Upper; // lower annd upper limits

    while (getline(file, line))
    {
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); i++)
    {
        pair = lines[i];
        // split into elf1 and elf2
        splitComma(pair, &elf1, &elf2);
        splitDash(elf1, &elf1Lower, &elf1Upper);
        splitDash(elf2, &elf2Lower, &elf2Upper);

        // assume elf1 contains elf2
        if (elf1Lower <= elf2Lower && elf1Upper >= elf2Upper)
        {
            count += 1;
        }
        // assume elf2 contain elf1
        else if (elf2Lower <= elf1Lower && elf2Upper >= elf1Upper)
        {
            count += 1;
        }
    }
    cout << count << endl;
}
