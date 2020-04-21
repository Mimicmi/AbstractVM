/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** A simple virtual machine for a simple assembler
** By:
** Simon Frezard, Li Wang-Faure, Julien Barriere
*/

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "./Parser/Parser.h"
#include "./Exception/Exception.h"
#include "./Factory/commands.h"
#include "./Memory/Memory.h"

int main(int argc, char **argv)
{
    Parser parser;
    std::vector<std::string> input;
    std::vector<std::tuple<std::string, std::string, std::string>> result;
    Commands Commands;

    try
    {
        if (argc > 1)
        {
            input = parser.getFile(argv[1]);
            result = parser.checkFile(input);
        }
        else
        {
            std::string line;
            int lineIndex = 1;
            while (line != "exit")
            {
                std::getline(std::cin, line);
                result.push_back(parser.checkInput(line, lineIndex));
            }
            std::cout << ";;" << std::endl;
        }
        for (int i = 0; i < result.size(); i++)
        {
            std::string function = std::get<0>(result[i]);
            std::string type = std::get<1>(result[i]);
            std::string value = std::get<2>(result[i]);
            if (function != "")
                Commands.call(function, type, value, i + 1);
        }
    }
    catch (Exception &e)
    {
        if (argc == 0)
            std::cout << ";;" << std::endl;
        std::cerr << e.what() << std::endl;
        return (84);
    }
    // try {

    // } catch (Exception e) {
    //     std::cout << e.what() << std::endl;
    //     return 84;
    // }
    return 0;
}