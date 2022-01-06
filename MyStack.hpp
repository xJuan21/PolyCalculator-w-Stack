/*
 * FILE: MyStack.hpp
 * AUTHOR: Juan Mota
 * DATE: 02/2021
 * PURPOSE:
 */
 
#ifndef _MY_STACK_HPP_
#define _MY_STACK_HPP_

#include <iostream>
#include <list>

template <class T>
class MyStack : private std::list<T>
{
public:
  //Push/Insert/Stack a new value to the Stack
  void push(const T &val);
  //Remove an element from the Stack. In this case, The first element on top.
  void pop();
  //Return the value of the element on top of the Stack.
  const T& top() const;
  // Return True or False depending on whether the Stack is empty or not
  bool isEmpty() const;
  // Absolutely remove all elements from the Stack.
  void Clear();
};

#endif
