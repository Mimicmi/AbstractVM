
#include <sstream>
#include <vector>
#include <regex>
#include "Parser.h"
#include "../Factory/commands.h"
#include "../Exception/Exception.h"

Parser::Parser()
{
    instructions.insert({"push", true});
    instructions.insert({"pop", false});
    instructions.insert({"dump", false});
    instructions.insert({"dup", false});
    instructions.insert({"clear", false});
    instructions.insert({"swap", false});
    instructions.insert({"assert", true});
    instructions.insert({"add", false});
    instructions.insert({"sub", false});
    instructions.insert({"mul", false});
    instructions.insert({"div", false});
    instructions.insert({"mod", false});
    // instructions.insert({"load", true});
    // instructions.insert({"store", true});
    // instructions.insert({"print", false});
    instructions.insert({"exit", false});

    values.insert({"int8", "[-]?[0-9]+"});
    values.insert({"int16", "[-]?[0-9]+"});
    values.insert({"int32", "[-]?[0-9]+"});
    values.insert({"float", "[-]?[0-9]+[.]?[0-9]*"});
    values.insert({"double", "[-]?[0-9]+[.]?[0-9]*"});
    values.insert({"bigdecimal", "[-]?[0-9]+[.]?[0-9]*"});
}

Parser::~Parser()
{
}

std::vector<std::string> Parser::getWordsInLine(const std::string &line)
{
    // Remove comments from the line
    std::string tmpLine = line.substr(0, line.find(";", 0));
    std::string word;
    std::vector<std::string> wordList;
    // Open a stream for the line
    std::istringstream iss(tmpLine);

    // Read each words from the line
    while (iss >> word)
    {
        // Save each words in a vector
        wordList.push_back(word);
    }
    return (wordList);
}

std::string Parser::getInstructionType(const std::string &instrValue, const int &line)
{
    int delimiter = instrValue.find("(");
    std::string type = instrValue.substr(0, delimiter);
    std::map<std::string, std::string>::iterator typeIt = this->values.find(type);

    // Throw an exception if the type does not exist
    if (typeIt == this->values.end())
        throw Exception("type does not exist", line);
    return (type);
}

std::string Parser::getInstructionValue(const std::string &instrValue, const std::string &type, const int &line)
{
    int delimiter = instrValue.find("(");
    std::map<std::string, std::string>::iterator typeIt = this->values.find(type);
    std::string value = instrValue.substr(delimiter + 1, instrValue.size() - delimiter - 2);

    // Regex does not match
    if (std::regex_match(value, std::regex(typeIt->second)) == false)
        throw Exception("regex does not match", line);
    // Regex OK
    return (value);
}

std::vector<std::string> Parser::getFile(const std::string &filename)
{
    std::fstream fs;
    std::vector<std::string> file;
    std::string line;

    fs.open(filename);
    // File can't be opened / does not exist
    if (fs.is_open() == false)
        throw Exception("file does not exist");
    // Open OK
    while (std::getline(fs, line))
    {
        file.push_back(line);
    }
    fs.close();
    return (file);
}

std::vector<std::tuple<std::string, std::string, std::string>> Parser::checkFile(const std::vector<std::string> &input)
{
    int lineIndex = 1;
    std::tuple<std::string, std::string, std::string> tupleResult;
    std::vector<std::tuple<std::string, std::string, std::string>> result;

    for (auto const &line : input)
    {
        result.push_back(this->checkInput(line, lineIndex));
        lineIndex++;
    }
    if (input.back() != "exit")
        throw Exception("missing exit");
    return (result);
}

std::tuple<std::string, std::string, std::string> Parser::checkInput(const std::string &line, const int &lineIndex)
{
    std::vector<std::string> lineWords = getWordsInLine(line);
    if (lineWords.size() > 0)
    {
        std::map<std::string, bool>::iterator it = this->instructions.find(lineWords.front());

        if (it == this->instructions.end())
        {
            throw Exception("instruction \"" + lineWords.front() + "\" does not exist", lineIndex);
        }
        else
        {
            bool instrValueExists = it->second;
            std::string type = "";
            std::string value = "";

            if (instrValueExists == true)
            {
                std::string instrValue = lineWords.back();
                type = this->getInstructionType(instrValue, lineIndex);
                value = this->getInstructionValue(instrValue, type, lineIndex);
            }
            return (std::make_tuple(it->first, type, value));
        }
    }
    return std::make_tuple("", "", "");
}
