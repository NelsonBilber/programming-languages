using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ParallelLoopBreak
{
	class Program
	{
		static void HalfOperation()
		{
			Thread.SpinWait(int.MaxValue / 2);
		}
		static void Main(string[] args)
		{
			int cancelValue;

			if(!int.TryParse(args[0], out cancelValue))
			{
				return;
			}

			Parallel.For(0, 20, (index, loopState) =>
				{
					Console.WriteLine("Task {0} started...", index);
					HalfOperation();
					if (cancelValue == index)
					{
						loopState.Break();
						Console.WriteLine("Loop Operation cancelling. Task {0} cancelled...", index);
						return;
					}
					if (loopState.LowestBreakIteration.HasValue)
					{
						if (index > loopState.LowestBreakIteration)
						{
							Console.WriteLine("Task {0} cancelled", index);
							return;
						}
					}
					HalfOperation();
					Console.WriteLine("Task {0} ended.", index);
				});
			Console.WriteLine("Press enter to exit");
			Console.ReadLine();
		}

	}
}
