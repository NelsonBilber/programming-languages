using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factorial
{
	class Program
	{
		static int total=1;
		const int EXCLUSIVE = 1;
		static object mylock = new object();
		static void Main(string[] args)
		{
			Parallel.For(1, 5+EXCLUSIVE, () => 1, (value, loopState, accumulator) =>
				{
					accumulator*=value;
					return accumulator;
				},
				(accumulator) =>
				{

					//calcular o resultado das threads/tasks
					lock (mylock)
					{
						total *= accumulator;
					}
				});

			Console.WriteLine("The result is {0}", total);

			Console.WriteLine("Press enter to exit");
			Console.ReadLine();
		}
	}
}