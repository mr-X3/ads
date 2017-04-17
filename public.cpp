//import java.lang.*;
import java.io.*;
import java.io.BufferedReader;
class P
{
	private int x;
	protected int y;
	public int z;
	public P()
	{
		x=10;
		y=200;
		z=30;
	}
	void show()
	{
		System.out.println("PRIVATE MEMBER : "+x);
	}
	
}
class D extends P
{
	public D()
	{
		super();
	}
	public void display()
	{
		super.show();
		System.out.println("PROTECTED MEMBER : "+y);
		
	}
}
class hello1
{
 	public static void main(String args[])throws IOException
	{
	
		int a;
		D obj=new D();
		obj.display();
		System.out.println("PUBLIC MEMBER : "+obj.z);    //PUBLIC MEMBER CAN ACCESS IN ANY METHOD
		System.out.println("\n\t Enter the value for a ");
		BufferedReader b=new BufferedReader(new InputStreamReader(System.in));	
		a=Integer.parseInt(b.readLine());
		int i=0,fact=1;
		while(i<=a)		
		{
			fact=fact+(fact*i);
			i++;
		}
		System.out.print(fact);
		}
}