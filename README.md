# Custom Hash Function

This project implements a basic custom hash function in C++, which manipulates bits of each character in the input string to generate a unique hash value.

## Features

- Custom bit manipulation (swapping 4-bit halves).
- XOR and bit rotation operations to generate a hashed output.
- Outputs a unique hexadecimal hash value for any input string.
- Possibility to input by hand or with external file

## Installation

Before running this project, ensure you have the following installed:

- **C++ Compiler**: You can use any C++ compiler (GCC, Clang, MSVC, etc.).

### Steps to Install and Run

1. **Clone the repository**  
   Download or clone this project to your local machine.

    ```bash
    git clone https://github.com/your-username/custom-hash-function.git
    cd custom-hash-function
    ```

2. **Compile the project**  
   Compile the C++ source code using your preferred compiler. Here's an example using `g++`:

    ```bash
    g++ hash_function.cpp -o hash_function
    ```

    If you are using Windows and `g++` is available via MinGW or Cygwin:

    ```bash
    g++ hash_function.cpp -o hash_function.exe
    ```

3. **Run the program**  
   After compilation, run the executable to test the hash function. You can provide any input string.

    ```bash
    ./hash_function
    ```

    On Windows:

    ```bash
    hash_function.exe
    ```

4. **Input**  
   Enter any string, and the program will output a hexadecimal hash value.

    ```bash
    Input: Hello
    Hash: ffffffffb0f2e1c3bbbbbbcebb85ff02abc5af01dad53e711234567812345678
    ```


## Usage

After running the program, you will be prompted to enter a string. The program will process the string through the custom hash function and output the resulting hexadecimal hash.

```bash
$ ./hash_function
Enter input: Hello
Hash: ffffffffb0f2e1c3bbbbbbcebb85ff02abc5af01dad53e711234567812345678
