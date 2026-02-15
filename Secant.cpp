#include "secant.h"
#include "parser.h"
#include <cmath>
#include <iostream>


using namespace std;

SecantSolver::SecantSolver(string expr, int x0, int x1, double tol,
                           int maxIter) {
  this->expr = expr;
  this->x0 = x0;
  this->x1 = x1;
  this->tol = tol;
  this->maxIter = maxIter;

  solve();
}

/**
 * @brief Executes the Secant method logic.
 *
 * Steps:
 * 1. Evaluates the function at x0 and x1.
 * 2. Checks for initial sign changes (though not strictly required for Secant,
 * often good practice).
 * 3. Enters iteration loop:
 *    a. Checks for division by zero (if f(x1) == f(x0)).
 *    b. Calculates new approximation x2.
 *    c. Checks convergence condition |x2 - x1| < tol.
 *    d. Updates x0 and x1 for the next iteration.
 *
 * @return The estimated root of the equation.
 */
double SecantSolver::solve() {

  EquationParser Parser;

  // Evaluate initial points
  Parser.parseEquation(expr);
  double f0 = Parser.evaluate(x0);

  Parser.parseEquation(expr);
  double f1 = Parser.evaluate(x1);

  // Note: Secant method doesn't strictly require a sign change, but this check
  // was originally here.
  if (f0 * f1 >= 0) {
    resultStream << "No sign change: f(a) and f(b) must have opposite signs.\n";
    return 0.0;
  }

  double x2;

  for (int i = 0; i < maxIter; ++i) {
    // Prevent division by zero
    if (fabs(f1 - f0) < 1e-12) {
      resultStream << "Division by zero error in secant method." << endl;
      return x1;
    }

    // Secant formula
    x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

    Parser.parseEquation(expr);
    double f2 = Parser.evaluate(x2);

    resultStream << "Iteration " << i + 1 << ": x = " << x2 << ", f(x) = " << f2
                 << endl;

    // Check for convergence
    if (fabs(x2 - x1) < tol) {
      resultStream << "Converged to root: " << x2 << endl;
      return x2;
    }

    // Shift points for next iteration
    x0 = x1;
    f0 = f1;
    x1 = x2;
    f1 = f2;
  }

  resultStream << "Did not converge within the maximum number of iterations. "
                  "Last approximation: "
               << x2 << endl;
  return x2;
}

std::string SecantSolver::GetResult() { return resultStream.str(); }