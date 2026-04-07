# Programming Assignment 3: Highest Value Longest Common Sequence
## Authors
**Herique Batista e Silva** (UFID: 24431968)  
**Bora Turkmen** (UFID: 25221169)
## Instructions
1. **Prerequisites**
    - Ensure you have CMake >= 3.26 installed
    - Ensure you have a C++17 compiler
    - Ensure you have a Python interpreter
    - Ensure you have Python's pandas library installed
    - Ensure you have Python's matplotlib library installed
2. **Clone Project**
    ```bash
    git clone https://github.com/ricks05/COP4533_PA3.git
3. **Create a Build Directory**
   ```bash
   mkdir build
   cd build
4. **Generate Build System**
   ```bash
   cmake ..
5. **Build the Project**
   ```bash
   cmake --build .
6. **Run Program**  
   From the build directory:
   ```bash
   ./main
   ```
    - Following assignment format, provide your input as src/io/example.in
    - This will run the algorithm and create example.out, containing the desired output
8. **Input Test and Analysis**  
   From the build directory:
   ```bash
   ./test
   ```
   Then run the python file:
   ```bash
   python ../test/graph.py
   ```
    - This will graph the runtimes of our 10 non-trivial inputs
## Written Component
![View PDF](written/COP4533_PA3.pdf)