using System;

namespace _iterators
{
	class MainClass
	{

		public static System.Collections.Generic.IEnumerable<int>
		EvenSequence(int firstNumber, int lastNumber)
		{
			// Yield even numbers in the range. 
			for (int number = firstNumber; number <= lastNumber; number++)
			{
				if (number % 2 == 0)
				{
					yield return number;
				}
			}
		}

		public static void Main (string[] args)
		{
			foreach (int number in EvenSequence(5, 18))
			{
				Console.Write(number.ToString() + " ");
			}
			// Output: 6 8 10 12 14 16 18
			Console.ReadKey();
		}
	}
}
