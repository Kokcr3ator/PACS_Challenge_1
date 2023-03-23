//
// Created by tommaso on 14/03/23.
//

#include <iostream>
std::ostream & operator<<(std::ostream &out, const parameters &p)
{
    out << "PARAMETER VALUES:"
        << "\n";
    out << "y0 = " << p.initialcond << "\n";
    out << "T = " << p.tf << "\n";
    out << "N = " << p.N << "\n";
    return out;
}
