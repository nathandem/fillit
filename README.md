# Fillit - can you fill it?


## Presentation

Fillit is a variant of the infamous Russian game Tetris. Its rule is simple: given some tetris blocks form the smallest possible square.

Given this input

	###.
	#...
	....
	....
	
	...#
	.###
	....
	....

the correct answer is

	AAA
	A.B
	BBB


## How it's built
The project is made of three parts: parsing, normalization and resolution.

### 1) Parsing
Parsing involves reading the text file and making sure the file is formatted as intended (4 lines of 4 characters followed by a line feed, only `#` and `.`, etc). If the format is correct, in-memory copies of the tetriminos are added to a linked list. Else, `error\n` is returned.

=> see `parse_input.c` for the parsing and `lst_utils.c` as well as `fillit.h` for the linked list structure and its manipulation functions.

Examples of valid tetriminos:

	....    ....    ####    ....    .##.    ....    .#..    ....    ....
	..##    ....    ....    ....    ..##    .##.    ###.    ##..    .##.
	..#.    ..##    ....    ##..    ....    ##..    ....    #...    ..#.
	..#.    ..##    ....    ##..    ....    ....    ....    #...    ..#.

Examples of invalid tetriminos:

	####    ...#    ##...   #.      ....    ..##    ####    ,,,,    .HH.
	...#    ..#.    ##...   ##      ....    ....    ####    ####    HH..
	....    .#..    ....    #.      ....    ....    ####    ,,,,    ....
	....    #...    ....            ....    ##..    ####    ,,,,    ....


*At this point, we know that the input is valid and copies of the tetriminos are stored in the nodes of a the linked-list.*

### 2) Normalization
We now move the tetriminos on the top-left corner of their grids and change their hashes to a letter corresponding to the order in which they appear in the file.

=> see `normalize_lst.c`

This input

	....
	..##
	..#.
	..#.
	
	....
	.##.
	.##.
	....
	
	....
	....
	#...
	###.


gets transformed into

	AA..
	A...
	A...
	....
	
	BB..
	BB..
	....
	....
	
	C...
	CCC.
	....
	....

*With a clean list of tetriminos in memory, the resolution can now begin!*

### 3) Resolution
The resolution is done through a ["backtracking" algorithm](https://en.wikipedia.org/wiki/Backtracking). It's a recursion algo which explores different branches of options by adding and removing functions on the stack as a way to do try-error exploration. This process runs until reaching the function base case with a result and exiting.

=> I recommend you to have a look at `algo.c`, especially the `resolve` function (called from the `main`) and the `resolve_rec` function to understand better how the flow goes

Example of a full resolution

	$> cat sample.fillit | cat -e
	....$
	##..$
	.#..$
	.#..$
	$
	....$
	####$
	....$
	....$
	$
	#...$
	###.$
	....$
	....$
	$
	....$
	##..$
	.##.$
	....$
	$> ./fillit sample.fillit | cat -e
	DDAA$
	CDDA$
	CCCA$
	BBBB$
	$>

Note: the algo is fast for small numbers of tetriminos. Yet, as we add pieces to the input files, complexity explodes, so does the resolution time.


### Constraints
- Language: C.
- No memory leaks.
- Style guide of the school: the Norme. Functions should not be longer than 25 lines, files should not contained more than 5 functions, `for` loops are prohibited, etc.


## Building and testing locally
If this projects sparks your curiosity, feel free to build it on your machine. You need `gcc` installed and accessible on your session. If it's the case, you can just type ``make`` from the `src` folder to get the ``fillit`` program. If's not already the case, you can make the program executable with `chmod +x fillit`.

You can use the input files of the `tests` directory to test the behavior of the program. A simple bash script `test_runner.sh` conviently goes thought each of the test files to display their content and output the result of the program for them. To run it, just type `./test_runner.sh` from the `tests` folder (this file also needs to be executable).


## Credits
This project is part of the curriculum of 42 ([FR](https://www.42.fr/) [US](https://www.42.us.org/)). It was written by Adrien Vardon and myself on Dec 2018.


If you want to exerce you C and algo skills on this project, here is the [full subject](https://cdn.intra.42.fr/pdf/pdf/734/fillit.fr.pdf) of the project.
