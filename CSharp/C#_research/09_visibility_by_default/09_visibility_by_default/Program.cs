using System;


/*
 * 
 * - classes and struct can that are declared with a namesapce
 * be eiher public or internal. Internal is the default if no
 * access is specified
 * - class/struct members are private by default
 * - interfaces are internal by default
 * - delegates internal acess when declared directly and private
 * when nested
 * - access modifiers are internal by default
 * 
 * Members of        Default member visibility
 *  enum             public   
 *  class            private
 *  interface        public 
 *  struct           private 
 * ----------------------------------------- */


namespace _visibility_by_default
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			int[] vect = new int [10];

			for(int i = 0; i < 10; i++)
			{
				vect[i] = i;
			}

			for(int i = 0; i < 10; i++)
			{
				Console.WriteLine(vect[i]);
			}

			Console.WriteLine ("Hello World!");
		}
	}
}
