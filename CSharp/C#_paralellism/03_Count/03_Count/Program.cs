using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Count
{
	class Program
	{
		static int[] intArray = new int [] { 1, 10, 4, 3, 10, 20, 30, 5 };
		static int count=0;

		static void Main(string[] args)
		{
			Parallel.For(0, intArray.Length, ()=>0, (index, loopState, subtotal) =>
				{
					if (intArray[index] > 5)
					{      
						++subtotal;
						Console.WriteLine("Thread {0}: Task {1}: Value {2}, Partial {3}",
							Thread.CurrentThread.ManagedThreadId, index,
							intArray[index], subtotal);                    }
					return subtotal;
				},


				//o valor que vai entrar recebe como para um apontador para
				// o count (global) e a actualização do subtotal por cada loop

				(subtotal)=>
				{      
					Interlocked.Add(ref count, subtotal);       
				});

			Console.WriteLine("Count is {0}\n", count);

			Console.WriteLine("Press enter to exit");
			Console.ReadLine();
		}
	}
}
