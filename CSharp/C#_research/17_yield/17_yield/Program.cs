using System;
using System.Collections;
using System.Collections.Generic;


namespace _yield
{
	
	class MainClass
	{
		static IEnumerable<int> Fibs (int fibCount)
		{
			for ( int i = 0, prevFib = 1, curFib = 1; i < fibCount; i++)
			{
				Console.Write ("\t => loop :: {0}\n", prevFib);
				yield return prevFib;
				Console.Write ("--> {0} - {1} \n", i, prevFib);
				int newFib = prevFib + curFib;
				prevFib = curFib;
				curFib = newFib;
				Console.Write ("--> {0} - {1} \n\n", i, prevFib);
			}
		}

		public static void Main (string[] args)
		{
			foreach( int fib in Fibs(6))
				Console.WriteLine ("main => {0}",fib);
		}
	}
}
