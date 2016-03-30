# For an n-bit Carry Completion Adder, write a C program to determine
the relationship between the average delay and operand size (n).

Guidelines:
 Operand size (n) varies from 1 to 48 with a skip of 1.
 Performance (delay) of each setup is to be derived from the average of 1000 sets of
random input numbers.
 Use rand( ) (or other similar functions) to generate random numbers for simulation.
 Note:
{ Your program should \simulate" the hardware process of the adder, down to
the gate level. That is, the program should generate intermediate results one
cycle at a time.
{ Your program should simulate the process one 2d-delay \cycle" at a time (with
a loop iteration), and should not \propagate" values inadvertently due to se-
quential program behavior within the same \cycle" (iteration). That is, each
value (carry, sum, etc.) at the end of current \cycle" should be determined us-
ing values from the previous \cycle", instead of using the \propagated" values
newly generated from other components during the current \cycle".
 Plot your nal results in d (gate delay) versus the operand size (n).
 Submit a report containing the following:
- your program with clear documentation,
 -your simulation results with a snapshot of all c0i
and c1i
at the end of each cycle
using the following 24-bit input patterns
101001001100101101100101
010101111000010010001011
- your plot with your conclusions and reasoning.
