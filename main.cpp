#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>

std::string Getformated(std::string tomut,std::string formt)
{

    return std::regex_replace(tomut, std::regex(formt), "\033[1;31m"+formt+"\033[0m");
    
};

int main(int argc, char *argv[])
{

    std::string parsedtext;

    std::ifstream file(argv[1]);
    std::stringstream text;
    text << file.rdbuf();
    

    parsedtext = Getformated(text.str(),"mov");
    parsedtext = Getformated(parsedtext,"pop");
    parsedtext = Getformated(parsedtext,"push");
    
    parsedtext = Getformated(parsedtext,"section .data");
    parsedtext = Getformated(parsedtext,"section .bss");
    parsedtext = Getformated(parsedtext,"section .text");
    
    std::cout << parsedtext << std::endl;
    //initscr();

    //printw("%s",parsedtext.c_str());

    //refresh();
    //getch();

    //endwin();

}
