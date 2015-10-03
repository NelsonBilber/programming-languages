using System;

namespace _static
{
	//can't be instancieted
	public static class Test
	{
		public static void testP()
		{
			Console.WriteLine ("Test");
		}
	}

	public class TestNormal
	{
		public static string Print { get; set;}
	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			Test.testP ();
			TestNormal.Print = "x";
		}
	}
}
