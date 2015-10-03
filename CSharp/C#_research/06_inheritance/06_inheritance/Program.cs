using System;

namespace _inheritance
{

	class MyBase
	{
		public String Name { get; set;}

		public virtual void display()
		{
			Console.WriteLine ("MyBase");	
		}

		public MyBase(){}
		public MyBase (string name)
		{
			this.Name = name;
		}
	}

	class MySubClass: MyBase 
	{
		// inherites propertie Name from Base class

		public int Id { get; set;} 

		//polimorphism
		public override void display()
		{
			Console.WriteLine ("MySubClass");	
		}

		public MySubClass () {}

		//base call base class constructor
		public MySubClass (string nome, int Id): base(nome)
		{
			this.Id = Id;
		}
	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			MySubClass mc = new MySubClass { Name = "Rodrigues", Id = 2 };

			Console.WriteLine ("{0} - {1}", mc.Name,  mc.Id);
			mc.display ();
		}
	}
}
