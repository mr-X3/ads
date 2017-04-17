import java.lang.*;
import java.io.*;
class sample<T>
{
	T t;
	
	public void get(T o)
	{
		t=o;		
	}
	public void print()
	{
		System.out.println(t);
	}
}
class tem extends Exception
{
	tem(String str)
	{
		super(str);
	}
	public static void main(String ar[])throws IOException
	{
		int a;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String s1=new String("HELLO WORLD");
		sample s=new sample();
		System.out.println("ENTER A NUMBER : ");
		try{
		a=Integer.parseInt(br.readLine());
				if(a>18)
				{
					s.get(a);
					s.print();
				}
		else
			throw new tem("NUMBER SHOULD GREATER THAN 18");
		}
		catch(tem e)
		{
			System.out.println(e);
		}
		
		s.get(s1);
		s.print();
	}
}
