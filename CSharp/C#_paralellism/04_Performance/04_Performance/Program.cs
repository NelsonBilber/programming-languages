using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Diagnostics;
using System.Threading.Tasks;

namespace Performance
{
	class Program
	{
		static bool Normalize()
		{
			Console.WriteLine("Normalizing [Task {0} : Thread {1}]", 
				Task.CurrentId, Thread.CurrentThread.ManagedThreadId);
			Thread.SpinWait(int.MaxValue);
			return true;
		}

		static void Main(string[] args)
		{
			var sw = new Stopwatch();
			var intArray = new [] { 1, 2, 3, 4 };

			//var result = intArray.Where((index)=>Normalize());
			var result = intArray.AsParallel().Where((index) => Normalize());

			sw.Start();
			foreach (int item in result)
			{
				Console.WriteLine("Item={0}", item);
			}
			sw.Stop();
			Console.WriteLine("Elapse time: {0}: seconds", 
				sw.ElapsedMilliseconds / 1000);

			Console.WriteLine("Press Enter to Continue");
			Console.ReadLine();
		}
	}
}
