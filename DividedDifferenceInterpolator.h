#ifndef DIVIDED_DIFFERENCE_INTERPOLATOR_H
#define DIVIDED_DIFFERENCE_INTERPOLATOR_H

#include <vector>

#using < System.Windows.Forms.dll>

using namespace System::Windows::Forms;

/**
 * @brief Implements Newton's Divided Difference Interpolation.
 *
 * This class calculates the interpolating polynomial using divided differences.
 * It automatically selects between forward and backward formulas based on the
 * position of the interpolation point relative to the data range.
 */
class divide {
public:
  int n;            ///< Number of data points.
  double x[20];     ///< Array of x coordinates (max 20 points).
  double f[20][20]; ///< Divided difference table.
  double XX;        ///< The point to interpolate at.
  double P1;        ///< The calculated interpolated value.

  /**
   * @brief Constructor.
   */
  divide();

  /**
   * @brief Sets the data and triggers the interpolation calculation.
   *
   * @param xVec Vector of x coordinates.
   * @param yVec Vector of y coordinates.
   * @param inputXX The x value to interpolate.
   * @param outputBox The RichTextBox control to display results.
   */
  void setData(std::vector<double> xVec, std::vector<double> yVec,
               double inputXX, RichTextBox ^ outputBox);

  /**
   * @brief Computes and displays the divided difference table.
   * @param outputBox The UI component for output.
   */
  void diffTable(RichTextBox ^ outputBox);

  /**
   * @brief Calculates the final interpolated value using the computed
   * differences.
   * @param outputBox The UI component for output.
   */
  void calcP(RichTextBox ^ outputBox);
};

#endif // DIVIDED_DIFFERENCE_INTERPOLATOR_H