//
// Created by tommaso on 14/03/23.
//

#ifndef PACS_CHALLENGE_1_PARAMETERS_HPP
#define PACS_CHALLENGE_1_PARAMETERS_HPP
#include <iostream>

struct parameters
{
    //! Initial condition (Dirichlet condition)
    double initialcond = 0;
    //! Final time
    double tf = 1;
    //! Number of steps for discretization
    unsigned long N = 100;
    
    friend std::ostream &operator<<(std::ostream &, const parameters &);
};

std::ostream &
operator<<(std::ostream &out, const parameters &p)
{
    out << "PARAMETER VALUES:"
        << "\n";
    out << "y0 = " << p.initialcond << "\n";
    out << "T = " << p.tf << "\n";
    out << "N = " << p.N << "\n";
    return out;
}
#endif //PACS_CHALLENGE_1_PARAMETERS_HPP
