#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

bool    replace_instances( std::ifstream& f0, std::ofstream& f1, std::string s1, std::string s2)
{
    std::string line;
    bool        first_line = true;
    while (std::getline(f0, line))
    {
        if (!first_line)
            f1 << '\n';

        size_t  pos = 0;
        while ( true )
        {
            pos = line.find(s1, pos);
            if (pos == std::string::npos)
                break ;
            line.erase(pos, s1.size());
            line.insert(pos, s2);
            pos = pos + s2.size();
        }

        f1 << line;
        first_line = false;
    }
    return ( f1.good() );
}

int main(int argc, char *argv[])
{
    int r_val = EXIT_FAILURE;
    if (argc != 4)
    {
        std::cerr << "ERROR: invalid number of arguments" << std::endl;
        return (r_val);
    }

    if (!argv[1][0] || !argv[2][0])
    {
        std::cerr << "ERROR: empty argument" << std::endl;
        return (r_val);
    }
    
    std::string     inputfile_n  = argv[1];
    std::ifstream   f0(inputfile_n.c_str());
    if (!f0.is_open())
    {
        std::cerr << "ERROR: could not open file '" << inputfile_n << "'" << std::endl;
        return (r_val);
    }

    std::string     outputfile_n = inputfile_n + ".replace";
    std::ofstream   f1(outputfile_n.c_str());
    if (!f1.is_open())
    {
        std::cerr << "ERROR: could not open file '" << outputfile_n << "'" << std::endl;
        return (r_val);
    }
    
    if (replace_instances(f0, f1, argv[2], argv[3]))
        r_val = EXIT_SUCCESS;
    
    f0.close();
    f1.close();

    return (r_val);
}