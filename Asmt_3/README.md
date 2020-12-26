# Instruction-Level Parallelism

**Objective:**

To calculate the performance of a program with dependent register arithmetic
instructions, by simulating the execution on:

(i) a 5-stage dynamic pipeline processor (w/o NOPs).
(ii) a 5-stage static pipeline processor (w/ NOPs).
The five stages are: Instruction Fetch (IF), Instruction Decode (ID), Execute Operation (EX), Memory Reference (ME), and Write Back to Register (WB).

Note: for register arithmetic instructions, the Memory Reference cycle is unused but still
included in the pipeline.

**Inputs:**
• Number of instructions in the program
• Set of instructions containing register arithmetic instructions, such as:

ADD_X2,X1,X0

where X2 is the destination register and X1, X0 are the source registers.

Note: to parse correctly, there should not be any space, so a “_” is added

**Outputs:**
• The total cycle count for the program run on the selected pipeline processor
• A Gantt chart of the pipeline stages of the instructions for the selected pipeline
processor

**Specification:**

The program calculates the performance of a set of register arithmetic instructions and
prints out the aligned pipelined instructions based on choosing from a menu of choices,
where each choice calls the appropriate procedure:
1) Enter instructions
2) Calculate and show total cycle count on a 5-stage dynamic pipeline processor
3) Calculate and show total cycle count on a 5-stage static pipeline processor (w/ NOPs)
4) Quit program

**What NOT to do (any violation will result in an automatic score of 0 on the assignment):**
• Do NOT modify the choice values (1, 2, 3, 4) or input characters and then try to convert them
to integers--the test script used for grading your assignment will not work correctly.
• Do NOT turn in an outdated version of the assignment downloaded from the Internet
(coursehero, github, etc.) or a version that was coded by someone else (former student, tutor,
etc.)
• Do NOT use any self-created or external libraries that cannot be located/utilized by zylabs
• Do NOT turn in your assignment coded in another programming language (C++, C#, Java,
Python, Perl, etc.)—it will NOT compile under zyLabs C compiler.

**Sample Test Run**:
```
Input:
1
4
ADD_X2,X1,X0
SUB_X3,X5,X4
ADD_X4,X5,X2
SUB_X7,X3,X9
2
3
4

Instruction-level parallelism
-----------------------------
1) Enter instructions
2) Calculate and show total cycle count on a 5-stage dynamic pipeline processor
3) Calculate and show total cycle count on a 5-stage static pipeline processor (w/ NOPs)
4) Quit program

Enter selection: 1

Enter total number of instructions: 4

Instruction-level parallelism
-----------------------------
1) Enter instructions
2) Calculate and show total cycle count on a 5-stage dynamic pipeline processor
3) Calculate and show total cycle count on a 5-stage static pipeline processor (w/ NOPs)
4) Quit program
Enter selection: 2

Total cycles: 9
ADD_X2,X1,X0: IF ID EX ME WB
SUB_X3,X5,X4:    IF ID EX ME WB
ADD_X4,X5,X2:          IF ID EX ME WB
SUB_X7,X3,X9:             IF ID EX ME WB

Instruction-level parallelism
-----------------------------
1) Enter instructions
2) Calculate and show total cycle count on a 5-stage dynamic pipeline processor
3) Calculate and show total cycle count on a 5-stage static pipeline processor (w/ NOPs)
4) Quit program
Enter selection: 3

Total cycles: 9
ADD_X2,X1,X0: IF ID EX ME WB
SUB_X3,X5,X4:    IF ID EX ME WB
NOP :               IF ID EX ME WB
ADD_X4,X5,X2:          IF ID EX ME WB
SUB_X7,X3,X9: IF ID EX ME WB

Instruction-level parallelism
-----------------------------
1) Enter instructions
2) Calculate total cycle count on a 5-stage dynamic pipeline processor
3) Calculate and show total cycle count on a 5-stage static pipeline processor (w/ NOPs)
4) Quit program
Enter selection: 4
```
