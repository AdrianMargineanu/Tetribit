# Tetribit

### General Idea
This is a basic tetris game played on bits. The map o the game is represented by a number that is saved on 64 bits. In this way we have a 8x8 map,where 0 it is '.' and 1 is '#'. The pieces are numbers, too, but on 32 bits. 

### Input
The input of the game is a number that will be on 64 bits , the map, an intiger number that are the number of moves you what to introduce. Next will be the moves that you make and its consist of a number that is the piece, then 8 intiger numbers that means how many colloms it is moving in the right( if the number is positive ) or negativ (if the number is negative).

### How it works?
The program is using the logic operation "and", to verify if there is a collision, if not the program will make the next move of the same piece , util there is a collision or all 8 moves. Then it is locing for full lines, using the same operation.  If there is a such line it will remove the line and all lines from above will fall, one line. After every move or line remove your curent map is printed

### END
The programs stops in 2 cases. First one is if you are out of moves, and second if you can not make the next move. if both cases, it will calculated a score that depends on lines removed and zeroes in your finale map.It will print the final map and the score you made.

### Authors
Margineanu Adrian
