# Numerical Methods Suite

![License](https://img.shields.io/badge/license-MIT-blue.svg) ![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg) ![Language](https://img.shields.io/badge/language-C%2B%2B%2FCLI-blue.svg)

## Overview

**Numerical Methods Suite** is a high-performance **C++/CLI WinForms application** engineered for solving complex mathematical problems. It bridges the gap between raw computational power and user-friendly visualization, making it an essential tool for engineering students, mathematicians, and researchers.

This project hosts a robust engine for:
*   **Root Finding**: Solving non-linear equations ($f(x) = 0$).
*   **Numerical Integration**: Computing definite integrals ($\int f(x)dx$).
*   **Interpolation**: Estimating unknown values from discrete data points.
*   **Differential Equations**: Solving Ordinary Differential Equations (ODEs) numerically.
*   **Curve Fitting**: Finding the best-fit curve for a set of data points using regression.

---

## Key Features

### 1. Advanced Equation Parser Engine
The core of the application is a custom-built equation parser designed for speed and accuracy. It allows users to input mathematical expressions in a natural, human-readable format.
*   **Shunting Yard Algorithm**: Utilizes Edsger Dijkstra's algorithm to convert infix expressions (e.g., `3 + 4`) into Reverse Polish Notation (RPN e.g., `3 4 +`) for efficient O(n) machine evaluation.
*   **Dynamic Variable Handling**: Supports functional evaluation for both single-variable ($f(x)$) and multi-variable ($f(x, y)$) equations, enabling complex surface plotting and ODE solving.
*   **Comprehensive Math Library**: Built-in support for a wide range of functions:
    *   **Trigonometric**: `sin`, `cos`, `tan`, `asin`, `acos`, `atan`
    *   **Hyperbolic**: `sinh`, `cosh`, `tanh`
    *   **Exponential/Logarithmic**: `exp`, `sqrt`, `log` (base 10), `ln` (base e)
    *   **Operators**: Standard ($+, -, *, /, \textasciicircum$) and prioritized evaluation.
*   **Validation**: Robust syntax checking ensures valid input, detecting errors like mismatched parentheses or unknown tokens before computation begins.

### 2. Root Finding Methods
Solve non-linear equations $f(x) = 0$ with high precision using iterative approximation techniques.

| Method | Description | Time Complexity | Convergence |
| :--- | :--- | :--- | :--- |
| **Bisection** | A bracketing method that repeatedly bisects an interval and selects a sub-interval in which a root must lie. Simple but robust. | $O(\log(b-a))$ | Linear |
| **Secant Method** | An iterative method using a succession of roots of secant lines to better approximate a root. Faster than Bisection but requires no derivative. | $O(1.618)$ | Superlinear |
| **Newton-Raphson** | Uses the function $f(x)$ and its derivative $f'(x)$ to linearlize the function at the current point. Converges extremely fast near the root. | $O(\log n)$ | Quadratic |

### 3. Numerical Integration
Compute definite integrals $\int_{a}^{b} f(x) dx$ using numerical approximation.
*   **Trapezoidal Rule**: Approximates the region under the graph as a trapezoid. Simple linear approximation ($O(1/n^2)$ error).
*   **Simpson's 1/3 Rule**: Uses quadratic polynomials to approximate the function over sub-intervals. Requires an even number of intervals ($O(1/n^4)$ error).
*   **Simpson's 3/8 Rule**: Uses cubic interpolation for higher accuracy. Requires the number of intervals to be a multiple of 3 ($O(1/n^4)$ error).

### 4. Ordinary Differential Equations (ODEs)
Solve first-order ODEs of the form $y' = f(x, y)$ given initial conditions.
*   **Euler's Method**: The most basic explicit method for numerical integration of ODEs. It follows the tangent line at the current point ($y_{n+1} = y_n + hf(x_n, y_n)$).
*   **Modified Euler (Heun's Method)**: A predictor-corrector approach. It predicts the next value using Euler's method, then corrects it using the average of the slopes at the original and predicted points.
*   **Visualization**: Generates tabular steps showing $x$, $y_{predictor}$, and $y_{corrector}$ values for detailed analysis.

### 5. Interpolation & Curve Fitting
*   **Lagrange Interpolation**: Constructs a polynomial that passes exactly through all given data points. Ideal for theoretical analysis.
*   **Newton's Divided Difference**: A recursive method for constructing the interpolating polynomial. More efficient than Lagrange when data points are added dynamically.
*   **Least Squares Fitting**: curve fitting method that finds the best-fitting curve (linear, polynomial, etc.) that minimizes the sum of squared residuals between observed and modeled data.

---

## System Architecture

The project follows a modular **Object-Oriented Design**, strictly separating UI logic from mathematical computation to ensure maintainability and testability.

```mermaid
graph TD
    A[Main UI (MyForm)] --> B[Method Forms]
    B --> C[Solver Classes]
    C --> D[Equation Parser]
    B --> E[UI Helpers]
    
    subgraph Core Logic
    D[Parser Engine (EquationParser)]
    C[Secant / Bisection / Integration / ODE Solvers]
    end
    
    subgraph UI Layer
    A
    B[BisectionForm / NewtonForm / etc]
    E[DataGrid Helper]
    end
```

*   **UI Layer**: Windows Forms built with C++/CLI for native .NET integration. Handles user input and result visualization.
*   **Solver Layer**: Pure C++ logic classes (e.g., `SecantSolver`, `NumericalIntegrator`) that perform the heavy lifting independent of the UI.
*   **Utility Layer**: Shared helpers for data grid manipulation, input validation, and string conversion.

---

## Tech Stack & Prerequisites

### Prerequisites
*   **Operating System**: Windows 10 or Windows 11.
*   **Runtime**: .NET Framework 4.8 or later.

### Development Environment
*   **Language**: C++ (C++/CLI) - Combining the performance of C++ with the ease of .NET.
*   **GUI Framework**: Windows Forms (WinForms).
*   **IDE**: Visual Studio 2019 or 2022 (Must have "Desktop development with C++" workload installed).

---

## Screenshots

### Main Interface
![Application Interface](https://github.com/user-attachments/assets/30da17aa-effc-4c09-8a86-0d6dcb9d59b7)

### Curve Fitting Analysis
![Curve Fitting](https://github.com/user-attachments/assets/71b7823d-cf54-4bc9-9d4e-7f83d7df3801)

### ODE Solver Output
![ODE Solver](https://github.com/user-attachments/assets/358c2bab-24f6-45ed-ad92-abf6c730acf8)

---

## Installation & Usage

### 1. Download & Run
1.  Navigate to the [Releases](https://github.com/Abdelhamid108/NumericalMethodsWinForms/releases) page.
2.  Download the latest executable (`Project1.exe` or `NumericalMethods.zip`).
3.  Run the executable. No installation is required if .NET Framework 4.8 is present on your machine.

### 2. Usage Example: Root Finding (Bisection)
1.  Open the **Bisection** module from the main menu.
2.  **Equation**: Input your function, e.g., `x^3 - x - 2`.
3.  **Interval**: Set the start point `a = 1` and end point `b = 2`.
4.  **Tolerance**: Set the desired precision, e.g., `0.0001`.
5.  Click **Calculate**. The table will show the iteration steps as the interval narrows down to the root.

### 3. Usage Example: ODE Solver
1.  Open the **Euler & Modified Euler** module.
2.  **Equation**: Input the differential equation $f(x, y)$, e.g., `x + y`.
3.  **Initial Values**: Set starting conditions $x_0 = 0, y_0 = 1$.
4.  **Target**: Set the target x value $x = 1$ and the Step size $h = 0.1$.
5.  Click **Solve** to see the step-by-step solution compared between Basic Euler and Modified Euler methods.

---

## Contributors

*   **Abdelhamid** ([@Abdelhamid108](https://github.com/Abdelhamid108)) - Lead Developer
*   **Marwan** ([@marwan779](https://github.com/marwan779))
*   **Yehia Hamdy** ([@YHS003](https://github.com/YHS003))
*   **Fady Ashraf** ([@fady1559](https://github.com/fady1559))
*   **Ahmed Kandil** ([@Ahmed-Kandil11](https://github.com/Ahmed-Kandil11))

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
