/*
ASSIGNMENT NO:G-27
Roll_No:
Title:Write a Java program which will demonstrate a concept of Interfaces and packages: In this
assignment design and use of customized interfaces and packages for a specific application
are expected
Class:-SE-A
Batch:-SA-1
Roll no.:-01*/

import subtask.StudentInfo;   //package import statement
import java.io.*;
interface Exam    //Interface declaration 
{
	public void acceptMarks() throws IOException;
	public void cal();
}

class Student implements Exam
{
	int n;
	public int sum=0;
	public double per;
	int []marks=new int[10];
	
	//Function to accept student marks
	public void acceptMarks() throws IOException
	 {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter no. of subjects : ");
		n=Integer.parseInt(br.readLine());
		System.out.println("\nEnter marks : ");
		for(int i=0;i<n;i++)
			marks[i]=Integer.parseInt(br.readLine());
	 }
	 
	//Function to calculate total and percentage
	public void cal()
	 {
		for(int i=0;i<n;i++)
		 	sum=sum+marks[i];
		per=sum/n;
	 }
}

class ass14
{
	public static void main(String ar[]) throws IOException
	 {
		Student s1=new Student();   //create object for class Student 
		StudentInfo s2=new StudentInfo();   //create object for class StudentInfo(in package subtask)
		s1.acceptMarks();
		s1.cal();
		s2.displayMarks(s1.sum,s1.per);
	 }
}

/*OUTPUT*/

/*
Enter no. of subjects : 
5

Enter marks : 
60
40
50
80
70
Total= 300
Percentage= 60
*/
