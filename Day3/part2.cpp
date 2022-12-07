#include <fstream>
#include <iostream>
#include <bits/stdc++.h> //required to use the find function
#include <vector>
using namespace std;

int main()
{
    ifstream file("day3input.txt");
    string line;
    string txt1;
    string txt2;
    string txt3;
    vector<char> alphabets = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<int> repeat;
    vector<string> lines;
    int sum = 0;
    char hold;     // temp searched character used in search for loops
    char repeated; // repeated character

    // getting lines into a vector 'lines'
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    // go through characters in the first line, cross check with the other 2 lines to see if character is in both lines
    for (int z = 0; z < lines.size(); z += 3)
    {
        txt1 = lines[z];
        txt2 = lines[z + 1];
        txt3 = lines[z + 2];

        for (int i = 0; i < txt1.length(); i++)
        {
            hold = txt1[i];
            if ((txt2.find(hold) != -1) && (txt3.find(hold) != -1))
            {
                repeated = hold;
                break;
            }
        }

        // find value of repeated characters using their index in the alphabets vector
        auto value = find(alphabets.begin(), alphabets.end(), repeated);
        int index = value - alphabets.begin() + 1;
        repeat.push_back(index);
    }

    // get the sum of the values in the repeat vector
    for (int i = 0; i < repeat.size(); i++)
    {
        sum += repeat[i];
    }

    cout << sum << endl;
}
