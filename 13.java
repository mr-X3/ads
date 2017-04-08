/*Assignment no:-13
Title:-Write a program on template and exception handling in java.
Class:-SE-A
Batch:-SA-4
Roll no.:-64*/
import java.io.*;
import java.util.Scanner;
class Excp13
{
  public static void main(String[] args) 
{
  int a, b, result;
 
  Scanner input = new Scanner(System.in);
  System.out.println("Input two integers");
 
  a = input.nextInt();
  b = input.nextInt();
 
  // try block
 
  try 
  {
    result  = a / b;
    System.out.println("Result = " + result);
  }
 
  // catch block
 
  catch (ArithmeticException e) 
  {
    System.out.println("Exception caught: Division by zero.");
  }
  }
}
----------------OUTPUT-------------------------------------------------
gescoe@gescoe-OptiPlex-3010:~$ cd Desktop/
gescoe@gescoe-OptiPlex-3010:~/Desktop$ javac Excp13.java
gescoe@gescoe-OptiPlex-3010:~/Desktop$ java Excp13
Input two integers
4 
2
Result = 2
gescoe@gescoe-OptiPlex-3010:~/Desktop$ java Div1
Input two integers
4
0
Exception caught: Division by zero.
gescoe@gescoe-OptiPlex-3010:~/Desktop$ 




