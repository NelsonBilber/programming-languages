using System;
using System.Threading.Tasks;
using System.Threading;

namespace _lambda
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			var TaskA = Task<int>.Factory.StartNew (
				(val) => 
				{
				return ((string)val).Length;
				} , "tessmdjo");

			TaskA.Wait ();

			Console.WriteLine (TaskA.Result);
		}
	}
}
