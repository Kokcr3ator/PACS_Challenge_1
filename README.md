# Challenge 1 APSC Course #

This simple code solves a Cauchy problem using Crank Nicolson numerical scheme.

Given the parameters (the number of time steps N, the final time of interest and the initial condition $y(0)$ ) stored in the file `parameter.pot` this program solves the equation $\frac{d}{dt}(y(t)) = f(t,y(t))$ with initial condition $y(0) = y_0$ where $f(t,y(t)) = -te^{-y}$ .

To solve the non linear equation generated from the Crank Nicolson implicit scheme a Newton solver has been implemented, as well as the function n-th derivative  calculator (in the include directory `basicZeroFun.hpp` `Derivatives.hpp`).

In this directory `make` produces the executable which is called `main` and the command `./main` runs the executable producing the results of the computation in the document `result.dat`.

If the user wants to plot the solution, the commmand `make plot` opens a gnuplot window where the computed solution and the exact solution are shown.

## Note ##

To plot the solution it is necessary to have gnuplot installed in your system. To install gnuplot it is sufficient to run `sudo apt-get install gnuplot` and `sudo apt-get install gnuplotx-11` for the graphical interface.


