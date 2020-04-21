/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** .cpp file for factory class, this class read and execute assembler language 
** By:
** Simon Frezard, Li Wang-Faure, Julien Barriere
*/

#include <iostream>
#include <cmath>
#include <cfloat>
#include <float.h>
#include "Factory.h"
#include "../IOperand/IOperand.h"
#include "../IOperand/Operand.h"
#include "../Exception/Exception.h"


static IOperand* createOperand(eOperandType type, const std::string& value) {
    Factory f;

    switch (type)
    {
        case Int8:
            return f.createInt8(value);
        case Int16:
            return f.createInt16(value);
        case Int32:
            return f.createInt32(value);
        case Float:
            return f.createFloat(value);
        case Double:
            return f.createDouble(value);
    }
}

IOperand* Factory::createInt8(const std::string& value) {
    double val = stoi(value);

    if (val > 127) {
        throw Exception("is not a Int8");
    }
    if (val < -128) {
        throw Exception("is not a Int8");
    }
    char res = val;
    return (new Operand(value, Int8));
}

IOperand* Factory::createInt16(const std::string& value) {
    double val = stoi(value);

    if (val > 32767) {
        throw Exception("is not a Int16");
    }
    if (val < -32768) {
        throw Exception("is not a Int16");
    }
    return (new Operand(value, Int16));
}

IOperand* Factory::createInt32(const std::string& value) {
    double val = stoi(value);

    if (val > 2147483647) {
        throw Exception("is not a Int32");
    }
    if (val < -2147483648) {
        throw Exception("is not a Int32");
    }
    return (new Operand(value, Int32));
}

IOperand* Factory::createFloat(const std::string& value){ 
    double val = stof(value);

    if (!std::isfinite(val) && val > 0) {
        throw Exception("is not a float");
    }
    if (!std::isfinite(val) && val < 0) {
        throw Exception("is not a float");
    }
    return (new Operand(value, Float));
}

IOperand* Factory::createDouble(const std::string& value){
    double val = stod(value);

    if (!std::isfinite(val) && val > 0) {
        throw Exception("is not a double");
    }
    if (!std::isfinite(val) && val < 0) {
        throw Exception("is not a double");
    }
    return (new Operand(value, Double));
}
