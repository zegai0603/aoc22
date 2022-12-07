#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream numFile("day2input.txt");
    string line;
    int score = 0;

    /* Rock == A, Paper == B, Scissors == C
    Rock == X, Paper == Y, Scissors == Z
    Rock == 1, Paper == 2, Scissors == 3*/

    while (getline(numFile, line))
    {
        if ((line[0] == 'A') && (line[2] == 'Y'))
        {
            score += 8;
        }
        else if ((line[0] == 'B') && (line[2] == 'X'))
        {
            score += 1;
        }
        else if ((line[0] == 'A') && (line[2] == 'X'))
        {
            score += 4;
        }
        else if ((line[0] == 'A') && (line[2] == 'Z'))
        {
            score += 3;
        }
        else if ((line[0] == 'B') && (line[2] == 'Y'))
        {
            score += 5;
        }
        else if ((line[0] == 'B') && (line[2] == 'Z'))
        {
            score += 9;
        }
        else if ((line[0] == 'C') && (line[2] == 'X'))
        {
            score += 7;
        }
        else if ((line[0] == 'C') && (line[2] == 'Y'))
        {
            score += 2;
        }
        else if ((line[0] == 'C') && (line[2] == 'Z'))
        {
            score += 6;
        }
    }
    cout << score;
}
