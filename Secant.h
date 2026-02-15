#pragma once

#include <sstream>
#include <string>


using namespace std;

/**
 * @brief Implements the Secant Method for finding roots of non-linear
 * equations.
 *
 * The Secant Method is an iterative root-finding algorithm that uses a
 * succession of roots of secant lines to better approximate a root of a
 * function f. It can be thought of as a finite-difference approximation of
 * Newton's method.
 */
class SecantSolver {
private:
  string expr;   ///< The mathematical expression to solve.
  double x0, x1; ///< The two initial approximations.
  double tol;    ///< The error tolerance for convergence.
  int maxIter;   ///< The maximum number of iterations allowed.
  std::ostringstream resultStream; ///< Stream to capture the output log.

public:
  /**
   * @brief Constructs a new Secant Solver object.
   * @param expr The function string (e.g., "x^2 - 4").
   * @param x0 The first initial guess.
   * @param x1 The second initial guess.
   * @param tol The error tolerance (e.g., 1e-6).
   * @param maxIter The maximum number of iterations.
   */
  SecantSolver(string expr, int x0, int x1, double tol, int maxIter);

  /**
   * @brief Executes the Secant method algorithm.
   *
   * Iteratively calculates the next approximation x2 using the formula:
   * x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
   *
   * Stops when |x2 - x1| < tol or maxIter is reached.
   *
   * @return The approximated root.
   */
  double solve();

  /**
   * @brief Retrieves the formatted result log.
   * @return A string containing the iteration details.
   */
  std::string GetResult();
};