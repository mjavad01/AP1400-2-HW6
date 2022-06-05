#ifndef Q1_H
#define Q1_H

#include<iostream>

namespace q1 
{
    // get derevative of a function
    
    double derivative(double (*f)(double), double x, double h = 0.00001)
    {
        
        return (f(x + h) - f(x)) / h;
    }
    
    // get the gradient of a function point by pointer

    // gradient_descent
   
    double gradient_descent(double initial_value, double step_size, double (*f)(double))
    {
        double x {initial_value};
        while (std::abs(derivative(f, x)) > 0.0001)
        {
            x -= step_size * derivative(f, x);
        }
        return x;
    }
} 

#endif //Q1_H