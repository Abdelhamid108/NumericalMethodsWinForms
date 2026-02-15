#pragma once

#include <sstream>
#include <string>

using namespace std;
/**
 * @brief Implements the Bisection Method for finding roots of non-linear
 * equations.
 *
 * The Bisection Method is a bracketing algorithm that repeatedly divides an
 * interval in half and then selects the sub-interval in which the root must
 * lie.
 */
class bisection {
private:
  string expr; ///< The mathematical expression to solve.
  double a, b; ///< The start and end points of the interval.
  double tol;  ///< The error tolerance for convergence.
  int maxIter; ///< The maximum number of iterations allowed.
  std::ostringstream
      resultStream; ///< Stream to store the formatted output table.

public:
  /**
   * @brief Constructs a Bisection solver instance.
   * @param expr The function string (e.g., "x^3 - x - 2").
   * @param a The start of the interval.
   * @param b The end of the interval.
   * @param tol The error tolerance (e.g., 1e-5).
   * @param maxIter The maximum iterations to perform.
   */
  bisection(string expr, int a, int b, double tol, int maxIter);

  /**
   * @brief Executes the Bisection algorithm logic.
   *
   * Iterates through the interval, updating the bounds based on the sign of the
   * function, until the root is found within the specified tolerance or maximum
   * iterations are reached. Populates the resultStream with the iteration
   * steps.
   */
  void bisection_solve();

  /**
   * @brief Retrieves the formatted result table.
   * @return A string containing the step-by-step solution.
   */
  std::string GetResult();
};
