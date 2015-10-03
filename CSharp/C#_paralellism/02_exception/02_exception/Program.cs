using System;
using System.Threading;
using System.Threading.Tasks;


namespace _exception
{
	class MainClass
	{

		public static void Main (string[] args)
		{
			Task TaskA = null;
			try{

				TaskA = Task.Factory.StartNew(() => {
					int a  = 5, b = 0;
					a/=b;
				});

			}catch(AggregateException ae){
				Console.WriteLine ("Task has" + TaskA.Status.ToString());
				Console.WriteLine (ae.InnerException);
			}
		}
	}
}
