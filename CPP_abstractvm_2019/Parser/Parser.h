#ifndef PARSER_H_
#define PARSER_H_

#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include <list>
#include <algorithm>
#include <map>

class Parser
{
private:
    std::vector<std::string> getWordsInLine(const std::string &line);
    std::string getInstructionType(const std::string &instrValue, const int &line);
    std::string getInstructionValue(const std::string &instrValue, const std::string &type, const int &line);
    std::map<std::string, bool> instructions;
    std::map<std::string, std::string> values;

public:
    std::vector<std::string> getFile(const std::string &filename);
    std::tuple<std::string, std::string, std::string> checkInput(const std::string &line, const int &lineIndex);
    std::vector<std::tuple<std::string, std::string, std::string>> checkFile(const std::vector<std::string> &input);
    Parser();
    ~Parser();
};

#endif /* !PARSER_H_ */
