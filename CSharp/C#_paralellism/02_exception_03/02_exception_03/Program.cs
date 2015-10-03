using System;
using System.Threading;
using System.Threading.Tasks;


namespace _exception_03
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

				Parallel.Invoke(new Action[] { MethodA, MethodB, MethodC });

			}
			catch(AggregateException ae){
				ae.Handle(ex =>
					{
						Console.WriteLine(ex.Message);
						return true;
					});

			}
		}
	}

}
