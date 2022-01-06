/*
 * FILE: main.cpp
 * AUTHOR: Juan Mota
 * DATE: 02/2021
 * PURPOSE: Main class that will run the Polynomial Calculator.
 *
 */
 
#include <iostream>
#include <fstream>
#include <string>
#include "Polynomial.hpp"
#include "MyStack.hpp"
#include "MyStack.ctt"

using namespace std;


MyStack<Polynomial> Accumulator; //Create a Stack that accumulates Polynomial expressions

//Simple method that prints out the Menu any time it is called
void Menu()
{
  cout << "__________________________________________________________________________________________" << endl;
  cout << "\nWelcome to this Polynomial Calculator! \nPlease, insert one of the next commands:\n" << endl;
  cout << "\tc -> Remove the top element from the accumulator" << endl;
  cout << "\td -> Remove all elements from the accumulator" << endl;
  cout << "\ts -> Enter a Polynomial (The Polynomial should not contain any spaces when typed in)" << endl;
  cout << "\te -> Evaluate the polynomial at that value and the result will be printed" << endl;
  cout << "\t+ -> Add the top two values from the accumulator" << endl;
  cout << "\t- -> Subtract the top two values from the accumulator" << endl;
  cout << "\t* -> Multiply the top two values from the accumulator" << endl;
  cout << "\tp -> Print the current value of the accumulator to the screen\n" << endl;
  cout << "\tq -> Exit the Calculator\n" << endl;

  cout << " >>> ";
}

//Let us know if the current Stack will be empty after removing the element on top.
// In other words, look for a second element after removing the top.
bool SingleElement()
{
  Polynomial test = Accumulator.top();
  Accumulator.pop();
  
  if(Accumulator.isEmpty())//If the Stack is empty after the pop, we have (or had) a single element.
  {
  	Accumulator.push(test);//Push the element back to where it was.
  	return true;//Return true because there's only one element in the Stack
  }
  
  Accumulator.push(test);//Push the element back to where it was.
  return false;//Return false if it found a Second element in after the pop
}

int main(int argc, char *arv[]) 
{
  
  Menu();//Print the Menu for the user.
  char command; //Variable storing the specific action desired by the user.
  cin >> command;//Receive an specific command order.
  Polynomial p;// Polynomial variable that will store the terms introduced by the user.
  Polynomial temp;// Second element on top of the Stack that will evaluate with the element on top.
  double evaluate;// Store the number at which x must be evaluated.
  
  do{
  	switch(command)// Look for the command inserted by the user and do the corresponding action.
  	{
  		case 'c' :
  		Accumulator.pop();//Remove whatever is on top of the Stack
  		
  		if(!Accumulator.isEmpty())//Check if there was only one element in the Stack
  			cout << Accumulator.top() << endl;// Print out the Top of the Stack.
  		else
  			cout << "The Accumulator is now empty" << endl;//Let the user now that there are not any other Polynomials stored
  			
  		Menu();
  		break;
  		
  		case 'd' :
  		Accumulator.Clear();// Clear out the entire accumulator
  		cout << "Accumulator Cleared!" << endl;
  		Menu();
  		break;
  		
  		case 's' :
  		cout <<"Please, insert your Polynomial Expression (Type ';' at the end of the expression to finish):\n >>>";
  		cin >> p;
  		Accumulator.push(p);//Insert the new Polynomial Expression at the top
  		cout << Accumulator.top() << endl;// Print out the Top of the Stack.
  		Menu();
  		break;
  		
  		case 'e' :
  		if(!Accumulator.isEmpty())//Check if it is not empty.
  		{
  			cout <<"Please, enter the value of x at which to evaluate the Polynomial:\n >>>";
  			cin >> evaluate;
  			p = Accumulator.top();//Store what is at the top of the Stack
  			cout << p.eval(evaluate) << endl;// Print the result of the expression evaluated by the value assigned
  		}else
  			cout << "Sorry, the Accumulator is currently empty." << endl;
  		
  		cout << Accumulator.top() << "   When X = " << evaluate << endl;// Print out the Expression and the value of X
  		Menu();
  		break;
  		
  		case '+' :
  		if(!Accumulator.isEmpty())//Check if it is not empty.
  		{
  			if(!SingleElement())// Check if there's something under this element
  			{
  				p = Accumulator.top();//Store what is at the top of the Stack
  				Accumulator.pop();// Remove the previous element
  				temp = Accumulator.top();//Store what is at the top of the Stack
  				Accumulator.pop();// Remove the previous element
  				p = p + temp;//Apply the operation between two terms (Add)
  				Accumulator.push(p);// Update by inserting the new Polynomial
  				cout << Accumulator.top() << endl;// Print out the Top (Result of these two) of the Stack.
  			}else
  				cout << "You need to insert a second element to apply this. Please, use 's' and insert a second element" << endl;
  		}else
  			cout << "Sorry, the Accumulator is currently empty." << endl;
  		Menu();
  		break;
  		
  		case '-' :
  		if(!Accumulator.isEmpty())//Check if it is not empty.
  		{
  			if(!SingleElement())// Check if there's another element under the top.
  			{
  				p = Accumulator.top();//Store what is at the top of the Stack
  				Accumulator.pop();// Remove the previous element
  				temp = Accumulator.top();//Store what is at the top of the Stack
  				Accumulator.pop();// Remove the previous element
  				p = temp - p;//Apply the operation between two terms (Subtract)
  				Accumulator.push(p);// Update by inserting the new Polynomial
  				cout << Accumulator.top() << endl;// Print out the Top (Result of these two) of the Stack.
  			}else
  				cout << "You need to insert a second element to apply this. Please, use 's' and insert a second element" << endl;
  		}else
  			cout << "Sorry, the Accumulator is currently empty." << endl;
  		Menu();
  		break;
  		
  		case '*' :
  		if(!Accumulator.isEmpty())//Check if it is not empty.
  		{
  			if(!SingleElement())// Check if there's another element under the top.
  			{
  				p = Accumulator.top();//Store what is at the top of the Stack
  				Accumulator.pop();// Remove the previous element
  				temp = Accumulator.top();//Store what is at the top of the Stack
  				Accumulator.pop();// Remove the previous element
  				p = p * temp;//Apply the operation between two terms (Multiply)
  				Accumulator.push(p);// Update by inserting the new Polynomial (Result)
  				cout << Accumulator.top() << endl;// Print out the Top (Result of these two) of the Stack.
  			}else
  				cout << "You need to insert a second element to apply this. Please, use 's' and insert a second element" << endl;
  		}else
  			cout << "Sorry, the Accumulator is currently empty." << endl;
  		Menu();
  		break;
  		
  		case 'p' :
  		if(!Accumulator.isEmpty())//Check if it is not empty.
  			cout << Accumulator.top() << endl; // Print out the Top of the Stack.
  		else
  			cout << "Sorry, the Accumulator is currently empty." << endl;
  		Menu();
  		break;
  		
  		default :
  		cout << "X X X Command not recognized. Please, try again. X X X " << endl;
  		Menu();
  		break;
  		
	}
	
  cin >> command;//Ask the User for a new command.
  
  }while(command != 'q');//Finally, terminate the program if 'q' is pressed.
  
  cout << "Thank you for using polyCalc! Have a nice day!\n\n";//Thank you message at the end.
}


