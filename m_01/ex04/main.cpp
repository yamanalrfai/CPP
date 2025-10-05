
#include <fstream>
#include <iostream>
#include <string>

std::string readinput(std::ifstream &in)
{
    std::string input, line;
    while (std::getline(in, line))
    {
        input += line;
        if (!in.eof())
            input += '\n';    
    }
    return (input);
}

std::string findoutput(std::string input, std::string s1, std::string s2)
{
    std::string ans;

    if (s1.size() == 0)
    {
        ans = input;
    }
    else
        for (long unsigned int i = 0; i < input.size(); i++)
        {
            if (input.size() - i < s1.size())
                ans += input[i];
            else
            {
                if (input.substr(i, s1.size()) == s1)
                {
                    ans += s2;
                    i += s1.size() - 1;
                }
                else
                    ans += input[i];
            }
        }
    return ans; 
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "you must enter a filename and two strings, s1 and s2. ONLY" << std::endl;
        return 1;
    }
    std::string file = argv[1];
    std::ifstream in(file.c_str());
    if (!in)
    {
        std::cout << "NOT valid file" << std::endl;
        return 1;
    }
    std::string input = readinput(in);
    in.close();
    std::ofstream out((file + ".replace").c_str());
    std::string output = findoutput(input, argv[2], argv[3]);
    out << output;
    out.close();
    return 0; 
}
