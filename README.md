# Custom Hash Function

This project implements a basic custom hash function in C++, which manipulates bits of each character in the input string to generate a unique hash value.

## Features

- Custom bit manipulation (swapping 4-bit halves).
- XOR and bit rotation operations to generate a hashed output.
- Outputs a unique hexadecimal hash value for any input string.
- Possibility to input by hand or with external file
- Generation of file which contains string pairs
- Comparison between Hashes

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
    g++ main.cpp -o hash_function
    ```

    If you are using Windows and `g++` is available via MinGW or Cygwin:

    ```bash
    g++ main.cpp -o hash_function.exe
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

After running the program, you will be prompted to enter a string or choose a filename, which already has a string. The program will process the string through the custom hash function and output the resulting hexadecimal hash.

## Experiments

### v0.3

Hash speed comparison in seconds

| Number of Lines Read |   MyHash   |   MD5     |
|----------------------|------------|-----------|
|          1000        | 0.001995   | 0.000199  |
|          5000        | 0.009381   | 0.000998  |
|         10000        | 0.018556   | 0.002396  |
|         50000        | 0.470373   | 0.056852  |
|        100000        | 6.784238   | 0.825197  |

Using MD5 was noticably quicker

Hash percentage comparison

<b>MD5</b>

- bit level
  
![image](https://github.com/user-attachments/assets/2dc79e7c-18d2-4600-8b39-6b37d9a1590e)

- hex level

![image](https://github.com/user-attachments/assets/e7bef8ea-6cdf-4ab4-ab94-19bd67835da1)


<b>My hash </b>

- bit level
  
![image](https://github.com/user-attachments/assets/e48fae69-1c19-4f85-bdde-70e3ddf7c2c5) <br>

- hex level

![image](https://github.com/user-attachments/assets/cc51bf41-f2ab-412a-8436-c56e1dfd3468) <br>

Hash functions where pretty similar in avalanche effect experiment

Also my hash incorporates salt, which help with hiding and puzzle friendliness.
It's practically impossible to reverse-engineer the output into input
```bash
string generateSalt(int len = 16) {
    const char alphanum[] = "0123456789"
                                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz";
    string salt;
    srand((time(nullptr)));
    for (int i = 0; i < len; ++i) {
        salt += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return salt;
}
```

### v0.2

<b>First experiment shows that my hash function: </b>
- is deterministic
- can handle any input
- gives exactly 64 chars
  
![image](https://github.com/user-attachments/assets/d97edee8-b165-485a-b982-9cd42a02ce4a)<br>

<b>Second experiment shows the speed of my hash function (no flags used):</b><br>
- left side is speed in seconds
- right side is number of lines given as input
  
![image](https://github.com/user-attachments/assets/1677f7b7-823e-4e2a-bea5-81505a2f9b94) <br>

<b> Graph of the hash functions execution time based on input size </b><br>

![graph](https://github.com/user-attachments/assets/ea29a891-b080-4106-a297-9b869d6e9cc9)
 <br>

<b> Based on results: </b>

The algorithm likely falls into the O(n log n) complexity class

<b> Third experiment shows, that my hash function is resiliant to coalitions  </b> <br>
It was made using a file, which had 100 000 string pairs of different length <br>
They were compared in order to find any matches, none were found <br>

![image](https://github.com/user-attachments/assets/85d2565c-d96b-43a0-8681-48aa0f1a6628) <br>

<b> Fourth experimemnt </b>
- bit level
  
![image](https://github.com/user-attachments/assets/e48fae69-1c19-4f85-bdde-70e3ddf7c2c5) <br>

- hex level

![image](https://github.com/user-attachments/assets/cc51bf41-f2ab-412a-8436-c56e1dfd3468) <br>

### v0.1
<b>First experiment shows that my hash function: </b>
- is deterministic
- can handle any input
- gives exactly 64 chars

![e1](https://github.com/Edukasas/blockchain/blob/master/assets/e1.png) <br>

<b>Second experiment shows the speed of my hash function (no flags used):</b><br>
- left side is speed in seconds
- right side is number of lines given as input
  
![e2](https://github.com/Edukasas/blockchain/blob/master/assets/e2.png) <br>

<b> Graph of the hash functions execution time based on input size </b><br>

![graph](https://github.com/Edukasas/blockchain/blob/master/assets/graph.png) <br>

<b> Based on results: </b>

The algorithm likely falls into the O(n log n) complexity class

<b> Third experiment shows, that my hash function is resiliant to coalitions  </b> <br>
It was made using a file, which had 100 000 string pairs of different length <br>
They were compared in order to find any matches, none were found <br>

![image](https://github.com/user-attachments/assets/91aeb8eb-1a30-4a23-88df-7c649f66dc42)

<b> Fourth experimemnt </b>
- bit level

  ![image](https://github.com/user-attachments/assets/c9e04a46-ea06-4470-922e-bc123aeb3607)

- hex level

  ![image](https://github.com/user-attachments/assets/fefc9a1e-bb9b-4f8a-8ffc-5471d083ad37)


```bash
$ ./hash_function
Enter input: Hello
Hash: ffffffffb0f2e1c3bbbbbbcebb85ff02abc5af01dad53e711234567812345678
