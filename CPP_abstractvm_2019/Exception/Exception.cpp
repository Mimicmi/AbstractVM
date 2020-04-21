/*
** Exception.cpp for CPP_abstractvm_2019 in /home/simonfrezard/Documents/Epitech_tasks/AbstractVM/CPP_abstractvm_2019/Exception
**
** Made by  Simon Frezard, Li Wang-Faure, Julien Barrière
** Login   <>
**
** Started on  Tue Jan 21 11:14:19 2020 
** Last update Tue Jan 21 11:14:19 2020 
*/

#include "Exception.h"

Exception::Exception(const std::string &message) throw()
{
    this->_message = "Error: " + message;
}

Exception::Exception(const std::string &message, const int &line) throw()
{
    this->_message = "Line " + std::to_string(line) + ": error: " + message;
}

Exception::~Exception()
{
}

const char *Exception::what() const throw()
{
    return (this->_message.c_str()); //c_str return value of string object
}