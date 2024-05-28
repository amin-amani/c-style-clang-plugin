# c-style-clang-plugin
A Clang plugin to check if function names , variables , etc follow the SINA naming convention.

## Overview

This plugin analyzes C and C++ source code and reports warnings for function names that do not adhere to the SINA naming convention. 

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


