using System;


/* ---------------------------------------------------------------------------------
 * 
 * Abstract class vs Interfaces
 * 
 * - Abstract classes can contain implementations of methods, fields
 * contructos, ..., While interface can only contains methods method
 * and proprieties prototypes
 * - class can inherit multiple interfaces but only one class (abstract or concrete)
 * - Interface defines something can do (how it behaves) while abstract class 
 * defines what something is
 * - Interfaces implicity all members are abstract
 * --------------------------------------------------------------------------------*/


namespace _abstract
{
	public abstract class MyAbs
	{
		public abstract decimal myvalue { get;}

		public void  print()
		{
			Console.WriteLine ("bla ...");
		}
			
	}

	class Myclass: MyAbs
	{
		public int Id { get; set;}
		public override decimal myvalue { get { return 10;}}
	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			Myclass c = new Myclass();
			Console.WriteLine (c.myvalue);
			c.print ();
		}
	}
}
