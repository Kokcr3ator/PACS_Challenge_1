//
// Created by tommaso on 3/13/23.
//

#ifndef PACS_CHALLENGE_1_CRANKNICOLSON_HPP
#define PACS_CHALLENGE_1_CRANKNICOLSON_HPP
#include <vector>
#include "basicZeroFun.hpp"
#include "Derivatives.hpp"
#include <array>
#include <functional>

// Da cambiare: Prendere in input una struct con i parametri

std::array<std::vector<double>,2> CrankNicolson(const std::function<double(double,double)> & f, double y0 = 0, double t0 = 0, double tf = 0, size_t N = 0){
    double h = (tf-t0)/N;
    std::vector<double> u_n(N+1);
    // Setting up th initial condition
    u_n[0] = y0;
    // Setting up the times vector
    std::vector<double> t_n(N+1);
    for(size_t i = 0; i < t_n.size(); ++i){
        t_n[i] = t0 + i*h;
    }
    double u_curr,t_new,t_curr;
    // Solving using Crank-Nicolson
    for(size_t i = 0; i < u_n.size()-1; ++i){
        u_curr = u_n[i];
        t_curr = t_n[i];
        t_new = t_n[i+1];
        // Creating the lambda-functions F(x) and its derivative DF(x) to compute its zero. It is necessary to use a numeric method since the function is non linear
        auto functional = [h,f,u_curr,t_curr,t_new](double x) {return x - (h/2)*(f(t_new,x)+f(t_curr,u_curr)) - u_curr;};
        auto dfunctional = apsc::derive<1>(functional,1.e-4);
        auto [result, converged]= apsc::Newton(functional,dfunctional,0);
        if(converged){
            u_n[i+1] = result;
        }
        else{
            std::cerr<<"Newton did not converge!"<<std::endl;
        }
    }
    std::array<std::vector<double>,2> ret;
    ret[0] = t_n;
    ret[1] = u_n;
    return ret;
}
#endif //PACS_CHALLENGE_1_CRANKNICOLSON_HPP
