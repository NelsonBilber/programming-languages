using System;

//delagates - function to pointers in c++

namespace _delegates
{
	public delegate int Transform(int x);
	public delegate object ObjectRetreiver();

	class Util
	{
		public static void Transform (int []values, Transform t)
		{
			for (int i = 0; i < values.Length; i++) {
				values [i] = t (values [i]);
			}
		}
	}

	class MainClass
	{
		static int Square (int x) { return x * x; }
		static string RetriveString ( ) {return "hello";}
	
		public static void Main (string[] args)
		{
			Transform t = Square; //creates delegate
			// Transform t = new Transform(Square)
			Console.WriteLine (t(3)); //invokes delegate and prints result

			int[] values = { 1, 2, 3 };
			Util.Transform (values, Square);

			foreach (int i in values) {
				Console.Write (i + " ");
			}

			Console.Write ("\n");

			ObjectRetreiver o = RetriveString;
			//ObjectRetreiver o = new ObjectRetreiver (RetriveString);
			object result = o ();
			Console.WriteLine (result);
		}
	}
}
