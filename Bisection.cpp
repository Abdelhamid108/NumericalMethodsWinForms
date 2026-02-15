#include "Bisection.h"
#include "Parser.h"
#include <cmath>
#include <iomanip>
#include <iostream>


using namespace std;

bisection::bisection(string expr, int a, int b, double tol, int maxIter) {
  this->expr = expr;
  this->a = a;
  this->b = b;
  this->tol = tol;
  this->maxIter = maxIter;

  bisection_solve();
}

/**
 * @brief Solves the equation using the Bisection Method.
 *
 * Steps:
 * 1. Checks if the signs of f(a) and f(b) are opposite. If not, the method
 * cannot guarantee a root.
 * 2. Iteratively calculates the midpoint c = (a+b)/2.
 * 3. Evaluates f(c).
 * 4. Narrows the interval [a, b] based on the sign of f(c).
 *
 * The process repeats until the absolute value of f(c) is less than the
 * tolerance or the maximum number of iterations is reached.
 */
void bisection::bisection_solve() {
  EquationParser Parser;

  // Helper: Initial check for valid bracketing
  Parser.parseEquation(expr);
  double fa = Parser.evaluate(a);

  Parser.parseEquation(expr);
  double fb = Parser.evaluate(b);

  if (fa * fb >= 0) {
    resultStream << "No sign change: f(a) and f(b) must have opposite signs.\n";
    return;
  }

  // Initialize output table headers
  resultStream << left << setw(15) << "Iter" << setw(25) << "a" << setw(25)
               << "b" << setw(25) << "c" << setw(25) << "f(c)" << "\n";

  resultStream << fixed << setprecision(6);

  for (int i = 1; i <= maxIter; ++i) {
    double c = (a + b) / 2;
    Parser.parseEquation(expr);
    double fc = Parser.evaluate(c);

    // Record current iteration state
    resultStream << left << setw(8) << i << setw(20) << a << setw(20) << b
                 << setw(20) << c << setw(20) << fc << "\n";

    // Check for convergence
    if (fabs(fc) < tol) {
      resultStream << "\nRoot found: " << c << "\n";
      return;
    }

    // Update interval
    if (fa * fc < 0) {
      // Root is in the left half
      b = c;
      fb = fc;
    } else {
      // Root is in the right half
      a = c;
      fa = fc;
    }
  }

  resultStream << "\nApproximate root after max iterations: " << (a + b) / 2
               << "\n";
}

std::string bisection::GetResult() { return resultStream.str(); }