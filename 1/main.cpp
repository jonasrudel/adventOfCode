#include <iostream>
#include <fstream>
#include <string>

int turnIntoPossibleDigit(std::string inputstring, int position)
{
    if(isdigit(inputstring[position]))
    {
        return(int(inputstring[position]) - 48);
    }
    if(inputstring.size() - position >= 3)
    {
        char threeCharString[3]{};
        inputstring.copy(threeCharString, 3, position);

        if (std::string(threeCharString).compare("one") == 0)
            return 1;
        else if (std::string(threeCharString).compare("two") == 0)
            return 2;
        else if (std::string(threeCharString).compare("six") == 0)
            return 6;
    }
    if(inputstring.size() - position >= 4)
    {
        char fourCharString[4]{};
        inputstring.copy(fourCharString, 4, position);
        if (std::string(fourCharString).compare("four") == 0)
            return 4;
        else if (std::string(fourCharString).compare("five") == 0)
            return 5;
        else if (std::string(fourCharString).compare("nine") == 0)
            return 9;
    }
    if(inputstring.size() - position >= 5)
    {
        char fiveCharString[5]{};
        inputstring.copy(fiveCharString, 5, position);

        if (std::string(fiveCharString).compare("three") == 0)
            return 3;
        else if (std::string(fiveCharString).compare("seven") == 0)
            return 7;
        else if (std::string(fiveCharString).compare("eight") == 0)
            return 8;
    }
    return -1;
}


int findFirstNumber(std::string inputstring)
{
    for(int i = 0; i < inputstring.size(); i++)
    {
        int possibleDigit = turnIntoPossibleDigit(inputstring, i);
        if(possibleDigit != -1)
        {
            return possibleDigit;
        }
    }
    return -1;
}

int findLastNumber(std::string inputstring)
{
    int currentLastDigit = -1;
    for(int i = 0; i < inputstring.size(); i++)
    {
        int possibleDigit = turnIntoPossibleDigit(inputstring, i);
        if(possibleDigit != -1)
        {
            currentLastDigit = possibleDigit;
        }
    }
    return currentLastDigit;
}




int main()
{
    std::ifstream myfile ("input.txt");
    std::string line;
    int totalSum = 0;
    if(myfile.is_open()) 
    {
        while(getline(myfile,line))
        {
            totalSum += 10 * findFirstNumber(line) + findLastNumber(line);
        }
    }
    std::cout << totalSum << std::endl;
    myfile.close();
}
