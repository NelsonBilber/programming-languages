using System;

/* ------------------------------
 * Proprieties
 * 
 * Examples from Microsoft MSDN
 * ------------------------------*/

namespace _proprieties
{
	public class MyDate
	{
		// value bu default
		private int month = 7;
		private string name;
		private static int counter;


		public int Month
		{
			get { return month; }

			//controls the values
			set {
				if((value > 0 ) && (value < 13))
				{
					month = value;
				}
			}
		}

		public string Name{
			get
			{
				return name != null ? name : "NA"; 
			}

			set 
			{
				name = value;
			}
		}

		public static int Counter
		{
			get {  return counter++;}
		}

		//ctor
		public MyDate()
		{
			counter+=2;
		}
	}

	public class Employee {
		private string name;

		public string Name {
			get{ return name; }
			set{ name = value;}
		}
	}

	public class Manager: Employee
	{
		private string name;

		public new string Name
		{
			get { return name;}
			set { name = value + " , Manager"; }
		}
	}

	//autoimplement proprieties

	class Customer
	{
		public int CustomerId{ get; set;}
	}

	class MainClass
	{
		public static void Main (string[] args)
		{

			MyDate d = new MyDate ();
			d.Month = 13;
			Console.WriteLine (d.Month);
			d.Month = 10;
			Console.WriteLine (d.Month);
			Console.WriteLine (MyDate.Counter);

			Manager m1 = new Manager ();
			m1.Name = "Nelson";

			((Employee)m1).Name = "Rodrigues";

			System.Console.WriteLine ("Name in the derived class is: {0}", m1.Name);
			System.Console.WriteLine ("Name in the base class is: {0}", ((Employee)m1));
	
			Customer c = new Customer ();
			c.CustomerId = 12;

			Console.WriteLine ("Auto proprieties = {0}", c.CustomerId);
		}
	}
}
