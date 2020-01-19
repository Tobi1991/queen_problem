# queen_problem

This problem calculates all solutions to the "Eight queens puzzle". It is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other (see https://en.wikipedia.org/wiki/Eight_queens_puzzle). 

The story
A friend of mine came to me with this problem during my university time. We were able to find a solution to the problem but the problem was still in my head since I wanted to find ALL the solutions. Obviously every row has to contain exactly one queen (since a queen can move like a rook). So my idea was to place exactly one queen to every row and then write a testing function to check if this position is a solution to the problem. Therefore I just had to iterate over 8!=40320 potential solutions. My initial thought was that this should be possible for a modern computer - and I was right ;-)

There are 92 distinct solutions to the problem. My program will just print all of them to the console. Every solutions contains exactly eight zeroes which are the only fields which are not being attacked by a queen. So just place the queens there.
