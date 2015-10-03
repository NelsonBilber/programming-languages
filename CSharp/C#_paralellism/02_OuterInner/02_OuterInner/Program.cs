
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;



namespace _OuterInner
{
	class MainClass
	{
		public static void Main (string[] args)
		{
				Task outer = new Task(
				() =>
						{
					Console.WriteLine("Outer task.");
							var inner=Task.Factory.StartNew(() => Console.WriteLine("Inner task."));
							inner.Wait();
						});
					outer.Start();
			Console.WriteLine("star task.");
					outer.Wait();

					Console.WriteLine("Press enter to exit");
					Console.ReadLine();
				}
			}

		
}
