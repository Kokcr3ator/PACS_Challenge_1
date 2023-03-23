# Challenge 1 APSC Course #
This simple code solves a Cauchy problem using Crank Nicolson numerical scheme.
Given the parameters (the number of time steps N, the final time of interest and the initial condition $y(0)$ ) stored in the file `parameter.pot` this program solves the equation $\frac{d}{dt}(y(t)) = f(t,y(t))$ with initial condition $y(0) = y_0$ where $f(t,y(t)) = -te^{-y}$ .

