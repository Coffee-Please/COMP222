# Measuring Performance

**Objective:**
To calculate the average CPI, the execution time, and MIPS of a sequence of instructions, given
the number of instruction classes, the CPI and total count of each instruction type, and the clock
cycle rate (frequency) of a particular machine.

**Inputs:**
- Number of instructions classes (types)
- CPI each type of instruction
- Total count of each type of instruction (in billions)
- Clock rate of machine (GHz)

**Output:**
- Average CPI of the sequence of instructions
- Total CPU processing time (seconds) of the sequence of instructions
- MIPS of the sequence of instructions

**Specification:**

The program calculates the output based on choosing from a menu of choices, where each choice
calls the appropriate procedure, where the choices are:
1) Enter parameters
2) Calculate the average CPI of a sequence of instructions
3) Calculate the execution time of a sequence of instructions
4) Calculate the MIPS of a sequence of instructions
5) Quit program

**What to do:**
- Make sure all calculations are displayed truncated to 2 decimal fractional places, using the
format “%.2f” in the printf statements.
- Make sure that the total execution time is measured in seconds.
- Make sure your code compiles with zyBooks’ zyLabs compiler--if it does not compile with
zyBooks’ compiler it will be graded as not compiling, even if it compiles on your compiler on
your desktop/laptop at home
- To typecast an int x to a float y, use y=(float)x or simply y=1.0*x
- Feel free to use the template “skeleton” code provided on Canvas for the assignment

**What NOT to do (any violation will result in an automatic score of 0 on the assignment):**
- Do NOT modify the choice values (1, 2, 3, 4, 5) or input characters and then try to convert
them to integers--the test script used for grading your assignment will not work correctly.
- Do NOT turn in an outdated version of the assignment downloaded from the Internet
(coursehero, github, etc.) or a version that was coded by someone else (former student, tutor,
etc.)
- Do NOT use any self-created or external libraries that cannot be located/utilized by zylabs
- Do NOT turn in your assignment coded in another programming language (C++, C#, Java,
Python, Perl, etc.)—it will NOT compile under zyLabs C compiler.

**Sample Test Run** 

Inputs: 1 3 2.5 1 6 3 4 5 2 2 3 4 5

Note: Inputs in the test run may not show up on the output display.

```
Measuring Performance:
----------------------
1) Enter parameters
2) Calculate CPI of a sequence
3) Calculate Execution time of a sequence
4) Calculate MIPS of a sequence
5) Exit program
Enter selection: 1
Enter the number of instruction classes: 3
Enter the frequency of the machine (GHz): 2.5
Enter CPI of class 1: 1
Enter instruction count of class 1 (billions): 6
Enter CPI of class 2: 3
Enter instruction count of class 2 (billions): 4
Enter CPI of class 3: 5
Enter instruction count of class 3 (billions): 2
Measuring Performance:
----------------------
1) Enter parameters
2) Calculate CPI of a sequence
3) Calculate Execution time of a sequence
4) Calculate MIPS of a sequence
5) Exit program
Enter selection: 2
The average CPI of the sequence is: 2.33
Measuring Performance:
----------------------
1) Enter parameters
2) Calculate CPI of a sequence
3) Calculate Execution time of a sequence
4) Calculate MIPS of a sequence
5) Exit program
Enter selection: 3
The execution time of the sequence is: 11.20 sec
Measuring Performance:
----------------------
1) Enter parameters
2) Calculate CPI of a sequence
3) Calculate Execution time of a sequence
4) Calculate MIPS of a sequence
5) Exit program
Enter selection: 4
The total MIPS of the sequence is: 1071.43
Measuring Performance:
----------------------
1) Enter parameters
2) Calculate CPI of a sequence
3) Calculate Execution time of a sequence
4) Calculate MIPS of a sequence
5) Exit program
Enter selection: 5
```
