#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream numFile("day2input.txt");
    string line;
    int score = 0;

    /* Rock == A, Paper == B, Scissors == C
    lose == X, draw == Y, win == Z
    Rock == 1, Paper == 2, Scissors == 3*/

    while (getline(numFile, line))
    {
        if ((line[0] == 'A') && (line[2] == 'Y'))
        {
            score += 4;
        }
        else if ((line[0] == 'B') && (line[2] == 'X'))
        {
            score += 1;
        }
        else if ((line[0] == 'A') && (line[2] == 'X'))
        {
            score += 3;
        }
        else if ((line[0] == 'A') && (line[2] == 'Z'))
        {
            score += 8;
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
            score += 2;
        }
        else if ((line[0] == 'C') && (line[2] == 'Y'))
        {
            score += 6;
        }
        else if ((line[0] == 'C') && (line[2] == 'Z'))
        {
            score += 7;
        }
    }
    cout << score;
}
