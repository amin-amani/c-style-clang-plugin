# c-style-clang-plugin
A Clang plugin to check if function names , variables , etc follow the SINA naming convention.

## Overview

This plugin analyzes C and C++ source code and reports warnings for function names that do not adhere to the SINA naming convention. 

# Comparison of Clang Plugins and .clang-format

| Action                               | Clang Plugins | .clang-format  |
|--------------------------------------|:-------------:|:--------------:|
| **Code Formatting**                  |      No       |       Yes      |
| - Indentation                        |      No       |       Yes      |
| - Brace Styles                       |      No       |       Yes      |
| - Column Limit                       |      No       |       Yes      |
| - Whitespace Control                 |      No       |       Yes      |
| - Alignment                          |      No       |       Yes      |
| - Line Wrapping                      |      No       |       Yes      |
| - Pointer and Reference Formatting   |      No       |       Yes      |
| - Comment Formatting                 |      No       |       Yes      |
| **Naming Conventions**               |      Yes      |       No       |
| - Check Function Names               |      Yes      |       No       |
| - Variable Naming                    |      Yes      |       No       |
| **Custom Static Analysis**           |      Yes      |       No       |
| - Custom Diagnostics                 |      Yes      |       No       |
| - Code Transformations               |      Yes      |       No       |
| **Language-Specific Rules**          |      Yes      |       Yes      |
| - Custom Checks for Specific Languages|     Yes      |      Limited   |
| **Integration with Build Systems**   |      Yes      |       Yes      |
| **IDE Support**                      |     Limited   |       Yes      |
| **Automation in CI/CD**              |      Yes      |       Yes      |
| **Performance Impact on Compilation**|    Moderate   |       Low      |
| **Ease of Use**                      |    Complex    |      Simple    |
| **Flexibility**                      |      High     |      Limited   |



## Features

- **Function Name Validation**: The plugin traverses function declarations using RecursiveASTVisitor and applies a regex pattern to match function names against the snake_case format.
- **Warning Reporting**: If a function name does not conform to snake_case, the plugin emits a warning message indicating the non-compliant function name.

## Usage

1. **Build the Plugin**:
   - Ensure you have Clang and LLVM installed.
   - Use CMake to build the plugin.
   - Example:
     ```sh
     sudo apt install libclang-dev
     mkdir src/build
     cd build
     cmake ..
     make
     ```

2. **Run the Plugin**:
   - Apply the plugin to your C or C++ source files using Clang.
   - Example:
     ```sh
     clang-15 -Xclang -load -Xclang ./c-style.so -Xclang -plugin -Xclang hello -c ./sample/snake-case-func.c
     ```

3. **Check Output**:
   - Review the compiler output for warnings regarding non-compliant function names.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or create a pull request on the GitHub repository.

## License

This project is licensed under the [MIT License](LICENSE).


