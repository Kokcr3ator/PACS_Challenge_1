//
// Created by tommaso on 14/03/23.
//
#include <vector>
#include <cmath>
#include "CrankNicolson.hpp"
#include "GetPot"
#include <string>
#include "read_parameters.hpp"
// To plot with GNUPlot
// #include "gnuplot-iostream.hpp"

// Help function when called with -h or --help

void printHelp()
{
    std::cout
            << "USAGE: main [-h] [-v] -p parameterFile (default: parameters.pot)"
            << std::endl;
    std::cout << "-h this help" << std::endl;
    std::cout << "-v verbose output" << std::endl;
}

int main(int argc, char** argv){

    using namespace std;

    int status(0);

    GetPot cl(argc, argv);
    if(cl.search(2, "-h", "--help"))
    {
        printHelp();
        return 0;
    }

    // Check if we want verbosity
    bool verbose = cl.search(1, "-v");

    // Get file with parameter values
    string filename = cl.follow("parameters.pot", "-p");

    cout << "Reading parameters from " << filename << std::endl;
    parameters param;
    param = readParameters(filename, verbose);
    // Defining the force function
    std::function<double(double, double)> force = [](double t, double y) {return -t*exp(-y);};

    // Calculating the solution (CrankNicolson returns an array of 2 vectors, one with the times and one with the solution y(t))
    auto [t_n,u_n] = CrankNicolson(force, param);

    // Computing the exact solution
    unsigned long N = param.N;
    double y0 = param.initialcond;
    double c = exp(y0);

    std::vector<double> exact_sol(N+1);
    for(size_t i = 0; i <= N; ++i){
        exact_sol[i] = log(c - pow(t_n[i],2)/2);
    }

    // Writing the output in a file
    cout << "Result file: result.dat" << endl;
    ofstream f("result.dat");

    f << "#time coordinate\tcomputed solution\texact solution" << std::endl;
    for(size_t n = 0; n <= N; n++)
    {
        f.setf(std::ios::left, std::ios::adjustfield);
        f.width(16);
        f << t_n[n] << "\t\t" << u_n[n] << "\t\t" << exact_sol[n] << "\n";
    }

    /*
    // Plotting with GNUPlot

    Gnuplot gp;
    gp << "plot" << gp.file1d(std::tie(t_n, u_n)) << "w lp lw 2 title 'uh',"
     << gp.file1d(std::tie(t_n, exact_sol)) << "w l lw 2 title 'uex'"
     << std::endl;
    */

    f.close();
    return status;


}
