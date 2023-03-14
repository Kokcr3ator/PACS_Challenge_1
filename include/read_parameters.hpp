//
// Created by tommaso on 14/03/23.
//

#ifndef PACS_CHALLENGE_1_READ_PARAMETERS_HPP
#define PACS_CHALLENGE_1_READ_PARAMETERS_HPP
#include <string>
#include "parameters.hpp"
#include "GetPot"
#include <fstream>

//! Reads problem parameters from GetPot file
/*!
  filename: The getopot file with the new values
  verbose: Prints some information on the parameters
 */

parameters readParameters(std::string const &filename, bool verbose = false){
    // Parameter default constructor fills it with the defaults values
    parameters defaults;
    // checks if file exixts and is readable
    std::ifstream check(filename);
    if(!check)
    {
        std::cerr << "ERROR: Parameter file " << filename << " does not exist"
                  << std::endl;
        std::cerr << "Reverting to default values." << std::endl;
        if(verbose)
            std::cout << defaults;
        check.close();
        return defaults;
    }
    else
        check.close();

    GetPot     ifile(filename.c_str());
    parameters values;
    // Read parameters from getpot data
    values.initialcond = ifile("initialcond", defaults.initialcond);
    values.tf = ifile("tf", defaults.tf);
    values.N = ifile("N", defaults.N);
    if(verbose)
    {
        std::cout << "PARAMETER VALUES IN GETPOT FILE"
                  << "\n";
        ifile.print();
        std::cout << std::endl;
        std::cout << "ACTUAL VALUES"
                  << "\n"
                  << values;
    }
    return values;
}

#endif //PACS_CHALLENGE_1_READ_PARAMETERS_HPP
