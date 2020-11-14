#include <cstdio>

// define integrator
typedef double (*func)(double x);
double midpoint(func f, const double a, const double b, const int n = 50){
  const double dx = (b-a)/n;
  double I = 0.0;
  for (int i = 0; i < n; ++i){
    double x = (i+1./2.)*dx;
    I += f(x)*dx;
  }
  return I;
}

// function we'll integrate
double  x_squared(double x){return x*x;}

// main program
int main(){
  double I = midpoint(x_squared, 0.0, 1.0, 100000000);
  std::printf(" I = %.3e  and should be close to %.3e\n", I, 1.0/3.0);
  return 0;
}
