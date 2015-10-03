using System;

namespace _boxing_unboxing_as_is
{
	public class A 
	{}

	public class B: A
	{}

	class MainClass
	{
		public static void Main (string[] args)
		{
			B b = new B();
			A a = b; // Upcast

			Console.WriteLine (a == b);

			A aa = b;

			B bb = (B)aa; //Downcast

			Console.WriteLine (aa == bb);

			// as operator performs a downcast that evaluates null

			A aaa = new A ();
			B bbb = aaa as B;
			Console.WriteLine (aaa == bbb);

			// is operator tests whether a reference conversion would succeed

			if (a is B)
				Console.Write ("true");
			else
				Console.Write ("false");

			// boxing - convert a value type instace to a reference type instance

			int x = 10;
			object obj = x;

			// unboxing - convert value to otiginal value

			int z = (int)obj;

			Console.Write ("\n{0}",z);

		}
	}
}
