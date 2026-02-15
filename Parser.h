#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <map>
#include <unordered_set>

/**
 * @brief A robust mathematical equation parser and evaluator.
 *
 * The EquationParser class is responsible for tokenizing string-based mathematical expressions,
 * converting them from Infix to Postfix notation using the Shunting Yard algorithm,
 * and evaluating the result for given variable values.
 *
 * Supported features:
 * - Basic arithmetic operators (+, -, *, /, ^)
 * - Trigonometric functions (sin, cos, tan, asin, acos, atan)
 * - Hyperbolic functions (sinh, cosh, tanh)
 * - Logarithmic and exponential functions (log, ln, exp, sqrt)
 * - Constants (pi, e)
 * - Single (x) and dual (x, y) variable support
 */
class EquationParser {
public:
    /**
     * @brief Constructs a new Equation Parser object.
     * Initializes configuration flags to default values.
     */
    EquationParser();

    /**
     * @brief Configures the parser to allow simultaneous use of x and y variables.
     * @param allow True to enable both x and y in the same equation, False otherwise.
     */
    void setAllowXY(bool allow);

    /**
     * @brief Parses a mathematical equation string.
     *
     * Validates the input syntax, tokenizes the string, and converts it to
     * postfix notation for efficient evaluation.
     *
     * @param equation The mathematical equation string (e.g., "sin(x) + 2*y").
     * @throws std::runtime_error If the equation contains invalid syntax or characters.
     */
    void parseEquation(const std::string& equation);

    /**
     * @brief Evaluates the pre-parsed equation for a single variable 'x'.
     * @param x_value The numerical value to substitute for 'x'.
     * @return The computed result of the equation.
     * @throws std::runtime_error If the equation requires 'y' but only 'x' is provided.
     */
    double evaluate(double x_value);

    /**
     * @brief Evaluates the pre-parsed equation for variables 'x' and 'y'.
     * @param x_value The numerical value to substitute for 'x'.
     * @param y_value The numerical value to substitute for 'y'.
     * @return The computed result of the equation.
     */
    double evaluate(double x_value, double y_value);

    /**
     * @brief Prints the current postfix representation to the standard output.
     * Useful for debugging the Shunting Yard algorithm's output.
     */
    void printPostfix();

    // Getters for variable detection
    bool hasX() const { return has_x; }
    bool hasY() const { return has_y; }

private:
    // Configuration flags
    bool allow_xy;      ///< Flag for allowing both x and y variables
    bool has_x, has_y;  ///< Flags indicating if x or y are present in the current equation

    // Token storage
    std::vector<std::string> tokens;   ///< Stores the tokenized infix expression
    std::vector<std::string> postfix;  ///< Stores the converted postfix (RPN) expression

    // Supported math functions
    const std::unordered_set<std::string> math_functions = {
        "sin", "cos", "tan", "asin", "acos", "atan",
        "sinh", "cosh", "tanh", "sqrt", "exp", "ln", "log"
    };

    // Mathematical constants
    const std::map<std::string, double> constants = {
        {"pi", 3.14159265358979323846},
        {"e", 2.71828182845904523536}
    };

    // Helper methods
    bool isOperator(char c);
    int precedence(char op);
    bool isFunction(const std::string& token);
    bool isConstant(const std::string& token);
    bool isValidCharacter(char c);
    void validateTokens();
    void convertToPostfix();
};

#endif // PARSER_H