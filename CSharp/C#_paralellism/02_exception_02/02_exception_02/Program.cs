using System;
using System.Threading;
using System.Threading.Tasks;

namespace _exception_02
{
	class MainClass
	{
		static void MethodA() {
			throw new Exception ("Task A Exception");
		}

		static void MethodB() {
			throw new Exception ("Task B Exception");
		}

		static void MethodC() {
			throw new Exception ("Task C Exception");
		}
		
		public static void Main (string[] args)
		{
			try{
				var TaskA = Task.Factory.StartNew(MethodA);
				var TaskB = Task.Factory.StartNew(MethodB);
				var TaskC = Task.Factory.StartNew(MethodC);

				Task.WaitAll(new Task[] {TaskA, TaskB, TaskC});
			}
			catch(AggregateException ae){
				foreach (var ex in ae.InnerExceptions) {
					Console.WriteLine (ex.Message);
				}

			}
		}
	}
}
