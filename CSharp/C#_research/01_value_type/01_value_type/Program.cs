using System;


/*--------------------
 * copy by value
 * ------------------- */

namespace _value_type
{
	struct Point {
		public int x, y;
	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			Point p1 = new Point ();
			p1.x = 100;

			Point p2 = p1;

			Console.WriteLine (p1.x);
			Console.WriteLine (p2.x);

			p1.x = 300;

			Console.WriteLine (p1.x);
			Console.WriteLine (p2.x);
		}
	}
}
