# Tetribit

### General Idea
This is a basic tetris game played on bits. The map of the game is represented by a number that is saved on 64 bits. In this way we have a 8x8 map,where 0 is '.' and 1 is '#'. The pieces are numbers, too, but on 32 bits. 

### Input
The input of the game is a number that will be on 64 bits , the map, an integer number that are the number of moves you want to introduce. Next will be the moves that you make and it consists of a number that is the piece, then 8 integer numbers that mean how many colloms the piece is moving in the right( if the number is positive ) or left (if the number is negative).

### How it works?
The program uses the logic operation "and", to verify if there is a collision, if not, the program will make the next move of the same piece , until there is a collision or all 8 moves of the same piece are done . Then the program is looking for full lines, using the same operation. If such a line exists it will remove the line and all the lines will fall one at a time.After every move or line removel,your curent map is printed

### END
The program stops in 2 cases. First one is if you are out of moves, and second if you can not make the next move. If both cases, it will be calculated a score that depends on lines removed and zeroes in your final map.It will be printed the final map and the score you made.

### Authors
Margineanu Adrian
