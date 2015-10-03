using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


//https://msdn.microsoft.com/en-us/library/8b0bdca4.aspx
//How to: Know the Difference Between Passing a Struct and Passing a Class Reference to a Method (C# Programming Guide)


namespace ConsoleApplication1
{

    class TheClass 
    {
        public string willChange;
    }

    struct TheStruct
    {
        public string willChange;
    }



    class Program
    {
        //static methods
        static void ClassTaker(TheClass c)
        {
            c.willChange = "Changed";
        }

        static void StructTaker(TheStruct s)
        {
            s.willChange = "Changed";
        }


        static void Main(string[] args)
        {
            TheClass testClass = new TheClass();
            TheStruct testStruct = new TheStruct();

            testClass.willChange = "Not changed";
            testStruct.willChange = "Not Changed";

            ClassTaker(testClass);
            StructTaker(testStruct);

            Console.WriteLine("Class field = {0}", testClass.willChange);
            Console.WriteLine("Struct field = {0}", testStruct.willChange);

            // Keep the console window open in debug mode.
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();

        }
    }
}
