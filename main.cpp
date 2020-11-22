#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{

    std::string parsedtext;

    std::ifstream file(argv[1]);
    std::stringstream text;
    text << file.rdbuf();
    
    parsedtext = std::regex_replace(text.str(), std::regex("mov"), "\033[1;31m mov\033[0m");
    parsedtext = std::regex_replace(parsedtext, std::regex("pop"), "\033[1;31m pop\033[0m");
    parsedtext = std::regex_replace(parsedtext, std::regex("push"), "\033[1;31m push\033[0m");
    parsedtext = std::regex_replace(parsedtext, std::regex("section"), "\033[1;31m section\033[0m");
    

    std::cout << parsedtext << std::endl;

}
