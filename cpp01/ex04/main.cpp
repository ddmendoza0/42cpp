#include <string>
#include <fstream>
#include <cstdlib>

void    replace_instances( std::ifstream& f0, std::ofstream& f1, std::string s1, std::string s2)
{
    std::string line;
    while (std::getline(f0, line))
    {
        size_t pos = 0;
        while ( true )
        {
            pos = line.find(s1, pos);
            if (pos == std::string::npos)
                break ;
            line.erase(pos, s1.size());
            line.insert(pos, s2);
            pos = pos + s2.size();
        }
        f1 << line '\n';
    }
}

int main(int argc, char *argv[])
{
    int r_val = EXIT_FAILURE;
    if (argc != 4)
        return (r_val);

    if (!argv[1][0] || !argv[2][0])
        return (r_val);
    
    std::string     inputfile_n  = argv[1];
    std::ifstream   f0(inputfile_n);
    if (!f0.is_open())
        return (EXIT_FAILURE);

    std::string     outputfile_n = inputfile_n + ".replace";
    std::ofstream   f1(outputfile_n);
    if (!f1.is_open())
        return (EXIT_FAILURE);
    
    replace_instances(f0, f1, argv[2], argv[3]);


    return r_val;
}