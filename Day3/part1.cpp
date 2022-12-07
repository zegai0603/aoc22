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
    vector<char> alphabets = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<int> repeat;
    int len; // length of line
    int sum = 0;
    char hold;     // temp searched character used in search for loops
    char repeated; // repeated character

    // finding repeated character in the 2 sublines and appending its value to the repeat vector
    while (getline(file, line))
    {
        len = line.length();
        txt1 = line.substr(0, len / 2);
        txt2 = line.substr(len / 2, len / 2);

        // search nested loop (could be improved)
        for (int i = 0; i < txt1.length(); i++)
        {
            hold = txt1[i];
            for (int y = 0; y < txt2.length(); y++)
            {
                if (txt2[y] == hold)
                {
                    repeated = hold;
                    break;
                }
            }
        }

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
