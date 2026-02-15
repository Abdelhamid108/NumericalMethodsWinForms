#include "LagrangeInterpolator.h"

LagrangeInterpolator::LagrangeInterpolator(const std::vector<double> &xData,
                                           const std::vector<double> &yData)
    : x(xData), y(yData) {}

/**
 * @brief Calculates the interpolated value using Lagrange's formula.
 *
 * Formula: P(x) = sum(y_i * L_i(x))
 * Where L_i(x) = product((x - x_j) / (x_i - x_j)) for all j != i.
 *
 * @param xValue The validation point.
 * @return The result P(xValue).
 */
double LagrangeInterpolator::interpolateY(double xValue) const {
  int n = x.size();
  double result = 0.0;

  for (int i = 0; i < n; ++i) {
    double term = y[i];
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        // Build Lagrange basis polynomial L_i(x)
        term *= (xValue - x[j]) / (x[i] - x[j]);
      }
    }
    // Add contribution of the current term to the final result
    result += term;
  }

  return result;
}

/**
 * @brief Performs inverse interpolation by swapping X and Y.
 *
 * This treats the y-values as the independent variable and x-values as the
 * dependent variable. Useful for finding the root (where y=0) or a specific x
 * corresponding to a target y.
 */
double LagrangeInterpolator::interpolateInverse(double yValue) const {
  // Swap x and y to perform inverse interpolation (estimate X from Y)
  std::vector<double> reversedX = y;
  std::vector<double> reversedY = x;

  // Create a new interpolator with swapped data
  LagrangeInterpolator inverseInterpolator(reversedX, reversedY);

  // Use the regular interpolateY to find X
  return inverseInterpolator.interpolateY(yValue);
}
