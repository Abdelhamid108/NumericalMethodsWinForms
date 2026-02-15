#ifndef EULER_METHODS_H
#define EULER_METHODS_H

#include <sstream>
#include <string>


/**
 * @brief Abstract base class for Euler ODE solvers.
 */
class EulerMethod {
public:
  virtual void solve(const std::string &equation, double x0, double y0,
                     double h, int steps) = 0;
  virtual ~EulerMethod() {}
};

/**
 * @brief Implements the Basic Euler Method (Forward Euler).
 * Formula: y_new = y_old + h * f(x_old, y_old)
 */
class BasicEuler : public EulerMethod {
public:
  void solve(const std::string &equation, double x0, double y0, double h,
             int steps) override;
};

/**
 * @brief Implements the Modified Euler Method (Heun's Method).
 * Formula:
 * k1 = f(x, y)
 * k2 = f(x+h, y + h*k1)
 * y_new = y + (h/2) * (k1 + k2)
 */
class ModifiedEuler : public EulerMethod {
public:
  void solve(const std::string &equation, double x0, double y0, double h,
             int steps) override;
};

// Global buffer to access output
extern std::ostringstream output;
std::string getEulerOutput();

#endif // EULER_METHODS_H
