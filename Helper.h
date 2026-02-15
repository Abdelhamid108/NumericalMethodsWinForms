#pragma once
#include "Parser.h"

/**
 * @brief Static helper class for UI and Data operations.
 */
class Helper {
public:
  /**
   * @brief Parses and validates a cell value from a data grid.
   *
   * Tries to interpret the string as a mathematical expression using the
   * parser. Useful for allowing users to input values like "pi" or "sqrt(2)"
   * directly into tables.
   *
   * @param TableData The string content of the cell.
   * @param flag Pointer to a boolean that will be set to false if validation
   * fails.
   * @return The evaluated double value, or 0.0 if invalid.
   */
  static double TableHandler(System::String ^ TableData, bool *flag);
};
