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
};
std::ostream &operator<<(std::ostream &, const parameters &);
#endif //PACS_CHALLENGE_1_PARAMETERS_HPP
