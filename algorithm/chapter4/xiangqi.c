//uva 1589
/*
Now you are given a situation only containing a black general, a red general and several red chariots,
cannons and horses, and the red side has delivered a check. Now it turns to black side's move. Your
job is to determine that whether this situation is \checkmate"

The input contains no more than 40 test cases. For each test case, the rst line contains three integers
representing the number of red pieces N(2<=N<=7) and the position of the black general.  The
following N lines contain details of N red pieces.  For each line, there are a char and two integers
representing the type and position of the piece (type char `G' for general, `R' for chariot, `H' for horseand `C'
 for cannon). We guarantee that the situation is legal and the red side has delivered the check.
There is a blank line between two test cases. The input ends by `0 0 0'.

For each test case, if the situation is checkmate, output a single word `YES', otherwise output the word`NO'.
Hint:
In the rst situation, the black general is checked by chariot and "flying general". In the second situa-
tion, the black general can move to (1, 4) or (1, 6) to stop check. 

SampleInput
2 1 4
G 10 5
R 6 4
3 1 5
H 4 5
G 10 5
C 7 5
0 0 0
SampleOutput
YES
NO
*/