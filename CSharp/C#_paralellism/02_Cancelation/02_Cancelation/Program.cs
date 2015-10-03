using System;
using System.Threading;
using System.Threading.Tasks;

namespace _Cancelation
{
	class MainClass
	{
		static void DoSomething(){
			Thread.SpinWait (int.MaxValue);
		}

		public static void Main (string[] args)
		{

			CancellationTokenSource cancellattionSource = new CancellationTokenSource ();
			CancellationToken token = cancellattionSource.Token;


			try{

				Task TaskA=Task.Factory.StartNew(() =>
					{
						while (true)
						{
							DoSomething();
							if (token.IsCancellationRequested)
							{

								token.ThrowIfCancellationRequested();
							}
						}

					}, token);

				Thread.Sleep(1000);
				cancellattionSource.Cancel();

				TaskA.Wait();


			}
			catch(AggregateException ex){
				Console.WriteLine (ex.InnerException.Message);
			}



			Console.WriteLine ("Press any key");
			Console.ReadLine ();
		}
	}
}
