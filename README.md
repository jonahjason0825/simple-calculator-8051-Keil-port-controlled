# simple-calculator-8051-Keil-port-controlled
Welcome to the 8051-based calculator!
You are provided with 4 ports for analysis.
The program takes in three inputs: choice, op1, and op2.
Users can configure port 1 to store their choices, and configure ports 2 and 3 to store operands op1 and op2 respectively.
Set port 1 to 0x01 for addition, 0x02 for subtraction, 0x03 for multiplication, 0x04 for division, and 0x05 for modulus. Add more operations if you wish!
Results can be viewed from port 0 (The port values are interchangeable).
Simple exception handling is also included in this code.
Programmed and tested on Keil Microvision 5 using the Embedded C programming language.
Watch this space for more!
