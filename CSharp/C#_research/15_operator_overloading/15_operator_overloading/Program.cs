using System;

namespace _operator_overloading
{

	class A 
	{
		public int Counter { set; get;}

		public static A operator+ ( A a, A b)
		{
			A sum = new A ();

			sum.Counter = a.Counter + b.Counter;

			return sum;
		}
	}


	class MainClass
	{
		public static void Main (string[] args)
		{
			A a = new A ();
			a.Counter = 5;
			A b = new A ();
			b.Counter = 6;

			A sum = a + b;

			Console.WriteLine (sum.Counter);
		}
	}
}
