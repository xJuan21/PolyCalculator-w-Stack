# Polynomial Calculator with a Stack

Author: Juan Mota

02/28/2021

Platform used: Linux.


Polynomial Calculator written in C++ that prompts a Menu telling the user the available actions into the program. The program utilizes a Stack as a data structure and pushes the result of the operation to the top. Also the Term, Token, and PolyCalc classes were needed to make this possible.

EXECUTION: Use the Makefile in the terminal and run the executable. The Menu will guide the user through the program.

In order to complete this first Project, it was needed to complete the following strategies:

1.- Initialize:
	1.a A Stack class (called MyStack) that would allow to work with attributes and method from the Polynomial class or any other Data Type or Object.
	
	1.b A main class with multiple methods that also interacts with the Polynomial and MyStack classes, which permits efectiveness during the management of Data.
	
	1.c A Menu with an explanation of the available commands to use for the User that will also interact with Stack class
	
	1.d The implementation of a template Class for the accumulator was not completely essential (In this case, MyStack class), but it helped to organize and understand ideas between the Polynomial class and the main class. It helped to figure out which methods and attributes belong to each class.
	
2.- Special/Additional Steps:
	2.a The creation a MakeFile helped to have a faster testing and organization of each file and its components.
	
	2.b The use of nemiver (Debugger) to find errors or bugs that would compromise the program.
	
	2.c A good understanding of templates and Stacks and how they work with each other.
	
<< Bugs that might appear during the execution of the Program >>

After multiple tests with the program. **No bugs were found at this point.**

	After implementing a Stack class, it was essential to learn how the class was involved with the project and with linked lists. Therefore, even though bot data structures might seem similar to each other. there are certain aspects that programmers must be aware before using one or the other. For Stacks, the First-in-Last-Out strategy/mindset is essential to succeed during the process. which also allows to work more effectively with the data being stored in this case. Finally, it is also important to be aware of these steps while using this data structure, because otherwise it would be really easy to fin Segmentation faults during the process. As a solution, implementing boolean variables that allow us to test if the Stack was empty or will be empty in the future was very useful to predict the behavior of the program during the proccess.
