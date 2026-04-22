#include <iostream>

int main(int argc, char *argv[])
{
    (void)argc;
    std::string output;
    std::string input;
    bool        only_spaces = true;

    for (int i = 1; argv[i]; i++)
        input += argv[i];
    
    for (int i = 0; input[i]; i++)
    {
        if (input[i] != ' ')
        {
            only_spaces = false;
            break;
        }
    }

    if (input.empty() || only_spaces)
        output = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 0; input[i]; i++)
            output += std::toupper(input[i]);
    }

	std::cout << output;

	return (0);
}