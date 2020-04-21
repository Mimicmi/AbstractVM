/*
** Exception.h for CPP_abstractvm_2019 in /home/simonfrezard/Documents/Epitech_tasks/AbstractVM/CPP_abstractvm_2019/Exception
**
** Made by Simon Frezard, Li Wang-Faure, Julien Barrière
** Login   <>
**
** Started on  Tue Jan 21 11:13:58 2020 
** Last update Tue Jan 21 11:13:58 2020 
*/

#ifndef EXCEPTION_H_
# define EXCEPTION_H_

#include <iostream>
#include <exception>

class Exception : public std::exception
{
    std::string _message;

    public:

    Exception (std::string const &message) throw();
    Exception (std::string const &message, const int &line) throw();
    virtual ~Exception() throw();
    virtual const char* what() const throw();
};



#endif