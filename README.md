# Numerical Methods WinForms Application

## Overview

This repository hosts a robust **C++/WinForms** application designed to perform various numerical methods for mathematical computations. It provides a user-friendly graphical interface alongside a powerful core engine for parsing and solving complex mathematical equations.

The application serves as a comprehensive tool for students, engineers, and researchers to visualize and compute solutions for:
*   **Root Finding**: Solving non-linear equations.
*   **Numerical Integration**: Computing definite integrals.
*   **Interpolation**: Estimating unknown values from discrete data points.
*   **Differential Equations**: Solving Ordinary Differential Equations (ODEs) numerically.
*   **Curve Fitting**: Finding the best-fit curve for a set of data points.

![Application Interface]

![Screenshot (84)](https://github.com/user-attachments/assets/30da17aa-effc-4c09-8a86-0d6dcb9d59b7)
![Screenshot (85)](https://github.com/user-attachments/assets/10e605bd-d492-469d-a4c5-4cf7d9b80279)
![Screenshot (86)](https://github.com/user-attachments/assets/71b7823d-cf54-4bc9-9d4e-7f83d7df3801)
![Screenshot (87)](https://github.com/user-attachments/assets/d6f7f1e6-c092-4a4c-80a7-afc3387177a2)
![Screenshot (88)](https://github.com/user-attachments/assets/e6b01d01-da52-467c-8089-127fed453ca7)
![Screenshot (89)](https://github.com/user-attachments/assets/8134218b-200c-441c-aa65-aed82714fcfd)
![Screenshot (91)](https://github.com/user-attachments/assets/358c2bab-24f6-45ed-ad92-abf6c730acf8)
![Screenshot (92)](https://github.com/user-attachments/assets/fe046f20-e97a-47e4-9220-305d1c2e6ad0)

## Key Features

### 1. Advanced Equation Parser Engine
The core of the application is a custom-built equation parser that interprets user input strings into executable mathematical logic.
-   **Variable Support**: Handles single (`x`) and multi-variable (`x`, `y`) equations.
-   **Mathematical Functions**: Supports a wide range of functions including trigonometric (`sin`, `cos`, `tan`, `asin`, `acos`, `atan`), hyperbolic (`sinh`, `cosh`, `tanh`), exponential (`exp`, `sqrt`), and logarithmic (`log`, `ln`).
-   **Constants**: Recognizes standard constants like `pi` ($\pi$) and `e`.
-   **Algorithm**: Utilizes the **Shunting Yard Algorithm** to convert infix expressions (standard mathematical notation) to postfix notation (Reverse Polish Notation) for efficient evaluation.
-   **Validation**: Includes robust syntax checking for mismatched parentheses, invalid operators, and unsupported characters.

### 2. Root Finding Methods
Accurately find roots of non-linear equations $f(x) = 0$.

| Method | Description | Convergence |
| :--- | :--- | :--- |
| **Bisection Method** | Bracketing method that repeatedly bisects an interval and selects a sub-interval in which a root must lie. | Guaranteed, Linear |
| **Secant Method** | Iterative method using a succession of roots of secant lines to better approximate a root of a function. | Superlinear |
| **Newton-Raphson** | (Implemented in code) Uses the function and its derivative to rapidly converge to a root. | Quadratic |

### 3. Numerical Integration
Compute the definite integral $\int_{a}^{b} f(x) dx$ using numerical approximation techniques.
-   **Trapezoidal Rule**: Approximates the region under the graph of the function as a trapezoid and calculates its area.
-   **Simpson's 1/3 Rule**: Uses quadratic polynomials for a more accurate approximation.
-   **Simpson's 3/8 Rule**: Uses cubic interpolation for higher accuracy with appropriate intervals.
-   **Features**: Supports automatic table generation and custom data point input.

### 4. Ordinary Differential Equations (ODEs)
Solve first-order ODEs of the form $y' = f(x, y)$.
-   **Euler's Method**: A basic explicit method for solving ordinary differential equations.
-   **Modified Euler's Method (Heun's Method)**: An improvement on Euler's method that achieves higher accuracy by averaging the slope.
-   **Output**: Generates a step-by-step tabular solution displaying $x$, $y_{predictor}$, and $y_{corrector}$ values.

### 5. Interpolation & Curve Fitting
Construct new data points within the range of a discrete set of known data points.
-   **Lagrange Interpolation**: Polynomial interpolation that passes through all given data points.
-   **Newton's Divided Difference**: Useful for polynomial interpolation, especially when data points are added dynamically.
-   **Least Squares Curve Fitting**: Finds the best-fitting curve (linear, polynomial, exponential) that minimizes the sum of squared residuals.

## Installation

### Prerequisites
*   **Operating System**: Windows 10 or Windows 11.
*   **Runtime**: .NET Framework 4.8 or later.
*   **Development Environment** (for building from source):
    *   Visual Studio 2019 or 2022.
    *   Desktop development with C++ workload.
    *   C++/CLI support (required for WinForms).

### Running the Application
1.  Navigate to the [Releases](https://github.com/marwan779/NumericalMethodsWinForms/releases) page.
2.  Download the latest `NumericalMethods.zip` or executable.
3.  Extract the files (if zipped) and run `Project1.exe` (or the renamed executable).

### Building from Source
To contribute or modify the code:
```bash
# 1. Clone the repository
git clone https://github.com/marwan779/NumericalMethodsWinForms.git

# 2. Open the solution file
# Navigate to the directory and open "Project1.sln" in Visual Studio.
```
3.  In Visual Studio, set the Solution Configuration to **Release** or **Debug**.
4.  Build the solution: **Build** > **Build Solution** (or press `Ctrl+Shift+B`).
5.  Run the application: **Debug** > **Start Without Debugging** (or press `Ctrl+F5`).

## Usage Guide

### Example: Solving a Root Finding Problem (Bisection)
1.  Launch the application and click on **Bisection**.
2.  **Equation**: Enter your function, e.g., `x^3 - x - 2`.
3.  **Interval**: Enter the start (`a`) and end (`b`) points, e.g., `1` and `2`.
4.  **Tolerance**: Set the error tolerance, e.g., `0.0001`.
5.  **Max Iterations**: Set a safeguard limit, e.g., `100`.
6.  Click **Calculate**. The table will populate with each iteration step, showing the interval narrowing down to the root.

### Example: Solving an ODE (Euler's Method)
1.  Select **Euler & Modified Euler**.
2.  **Equation**: Enter $f(x, y)$, e.g., `x + y`.
3.  **Initial Conditions**: Set $x_0 = 0, y_0 = 1$.
4.  **Target**: Set the target $x_{target} = 1$.
5.  **Step Size ($h$)**: Enter `0.1`.
6.  Click **Solve**. The grid will display the approximate $y$ value at each step $x$.

## Project Structure
*   **Parser.h/cpp**: The core equation parsing logic.
*   **[Method].h/cpp**: Implementation files for specific numerical methods (e.g., `Bisection.cpp`, `Secant.cpp`).
*   **[Method]Form.h**: The GUI forms corresponding to each method (e.g., `BisectionForm.h`).
*   **MyForm.h**: The main dashboard/menu of the application.

## Contributors
*   **Marwan** ([@marwan779](https://github.com/marwan779))
*   **Abdelhamid** ([@Abdelhamid108](https://github.com/Abdelhamid108))
*   **Yehia Hamdy** ([@YHS003](https://github.com/YHS003))
*   **Fady Ashraf** ([@fady1559](https://github.com/fady1559))
*   **Ahmed Kandil** ([@Ahmed-Kandil11](https://github.com/Ahmed-Kandil11))
