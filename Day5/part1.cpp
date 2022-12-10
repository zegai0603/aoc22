#include <iostream>
#include <sstream> // required to use stringstream
#include <string>
#include <fstream>
#include <bits/stdc++.h> //required to use the find function and other functions
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ifstream file("day5input.txt");
    string line, templine;
    int NoOfbox, from, to;
    vector<string> lines;
    vector<vector<char>> stack = {{'N', 'W', 'F', 'R', 'Z', 'S', 'M', 'D'}, {'S', 'G', 'Q', 'P', 'W'}, {'C', 'J', 'N', 'F', 'Q', 'V', 'R', 'W'}, {'L', 'D', 'G', 'C', 'P', 'Z', 'F'}, {'S', 'P', 'T'}, {'L', 'R', 'w', 'F', 'D', 'H'}, {'C', 'D', 'N', 'Z'}, {'Q', 'J', 'S', 'V', 'F', 'R', 'N', 'W'}, {'V', 'W', 'Z', 'G', 'S', 'M', 'R'}};
    char tempch;

    while (getline(file, line))
    {
        lines.push_back(line);
    }

    for (int i = 10; i < lines.size(); i++)
    {
        templine = lines[i];
        // filtering input to get the important numbers
        if (templine.length() == 18)
        {
            NoOfbox = stoi(templine.substr(5, 1));
            from = stoi(templine.substr(12, 1)) - 1;
            to = stoi(templine.substr(17, 1)) - 1;
        }
        if (templine.length() == 19)
        {
            NoOfbox = stoi(templine.substr(5, 2));
            from = stoi(templine.substr(13, 1)) - 1;
            to = stoi(templine.substr(18, 1)) - 1;
        }

        for (int y = 0; y < NoOfbox; y++)
        {
            tempch = stack[from][0];
            stack[from].erase(stack[from].begin());
            stack[to].insert(stack[to].begin(), tempch);
        }
    }

    for (int i = 0; i < stack.size(); i++)
    {
        cout << stack[i][0];
    }
}
