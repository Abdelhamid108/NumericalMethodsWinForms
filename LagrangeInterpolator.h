#pragma once
#include <vector>

/**
 * @brief Implements Lagrange Polynomial Interpolation.
 *
 * The Lagrange interpolation formula computes a polynomial P(x) of degree n-1
 * that passes through n given data points.
 */
class LagrangeInterpolator {
private:
  std::vector<double> x; ///< Known x coordinates.
  std::vector<double> y; ///< Known y coordinates.

public:
  /**
   * @brief Constructs the interpolator with dataset.
   * @param xData Vector of x coordinates.
   * @param yData Vector of y coordinates.
   */
  LagrangeInterpolator(const std::vector<double> &xData,
                       const std::vector<double> &yData);

  /**
   * @brief Interpolates Y for a given X value.
   * @param xValue The point to evaluate.
   * @return Estimated Y value.
   */
  double interpolateY(double xValue) const;

  /**
   * @brief Inverse Interpolation: Estimates X for a given Y value.
   *
   * Swaps the roles of X and Y data arrays to find the pre-image.
   * Note: This assumes the function is monotonic in the region of interest.
   *
   * @param yValue The target Y value.
   * @return Estimated X value.
   */
  double interpolateInverse(double yValue) const;
};
