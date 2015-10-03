using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections.Concurrent;
using System.Threading;
using System.Diagnostics;
using System.Threading.Tasks;

namespace Example
{
	class FunctionTracker: IDisposable
	{
		private static ConcurrentStack<string> log=new ConcurrentStack<string>();
		private StackTrace stackTrace = new StackTrace();
		private string functionName;
		private DateTime startTime=DateTime.Now;

		public FunctionTracker()
		{ 
			functionName=stackTrace.GetFrame(1).GetMethod().Name;
			log.Push(string.Format("{0} started: {1}", functionName, 
				startTime.ToLongTimeString()));
		}

		public void Dispose()
		{
			DateTime endTime=DateTime.Now;
			TimeSpan tsDuration = endTime.Subtract(startTime);
			log.Push(string.Format("{0} stopped: {1} [{2}]",
				functionName, endTime.ToLongTimeString(), tsDuration.TotalMilliseconds)); 
		}

		public void Stop()
		{
			Dispose();
		}

		public static void Dump()
		{
			string item;
			while (log.TryPop(out item))
			{
				Console.WriteLine(item);
			}
		}

		public static void Display()
		{
			foreach (string item in log)
			{
				Console.WriteLine(item);
			}
		}
	}


	class Program
	{
		public static void FuncA()
		{
			using (new FunctionTracker())
			{
				Thread.Sleep(1000);                
			}
		}

		public static void FuncB()
		{
			using (new FunctionTracker())
			{
				Thread.Sleep(2000);                
			}
		}

		static void Main(string[] args)
		{
			using (new FunctionTracker())
			{
				Parallel.Invoke(() => FuncA(), () => FuncB());                
			}
			FunctionTracker.Display();

			Console.WriteLine("Press enter to exit");
			Console.ReadLine();
		}
	}
}
