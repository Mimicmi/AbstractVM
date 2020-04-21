/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** .h file for IOperand class, this class contain all operation for vm 
** By:
** Simon Frezard, Li Wang-Faure, Julien Barriere
*/

#ifndef IOPERAND
#define IOPERAND

#include <iostream>
#include <string>

//defined eOperandType for all that is needed
typedef enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDecimal
} eOperandType;

class IOperand
{
public:
    // virtual std ::string toString() const = 0;                  // string that represents the instance
    // virtual eOperandType getType() const = 0;                   // returns the type of instance
    // virtual IOperand *operator+(const IOperand &rhs) const = 0; // sum
    // virtual IOperand *operator-(const IOperand &rhs) const = 0; // difference
    // virtual IOperand *operator*(const IOperand &rhs) const = 0; // product
    // virtual IOperand *operator/(const IOperand &rhs) const = 0; // quotient
    // virtual IOperand *operator%(const IOperand &rhs) const = 0; // modulo
};

#endif