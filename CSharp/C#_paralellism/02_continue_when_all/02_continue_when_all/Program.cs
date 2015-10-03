using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace _continue_when_all
{
	class Program
	{
		static int PerformCalculation() { return 42; }

		static void Main(string[] args)
		{
			var TaskA = new Task<int>(() =>
				{
					Console.WriteLine("TaskA started.");
					return PerformCalculation();
				});
			var TaskB = new Task<int>(() =>
				{
					Console.WriteLine("TaskB started.");
					return PerformCalculation();
				});

			var total=Task.Factory.ContinueWhenAll(new Task<int>[] { TaskA, TaskB },
				(tasks) => Console.WriteLine(
					"Total = {0}", tasks[0].Result + tasks[1].Result));

			TaskA.Start();
			TaskB.Start();

			Task.WaitAll(TaskA, TaskB);
			total.Wait();

			Console.WriteLine("Press enter to exit");
			Console.ReadLine();

		}
	}

}
