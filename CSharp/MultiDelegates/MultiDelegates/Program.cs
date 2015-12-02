using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiDelegates
{
    class Program
    {

        public delegate void MultiMethod(); // same signature of methods

        static public void FirstDelegate()
        {
            Console.WriteLine("First Delegate ...");
        }

        static public void SecondDelegate()
        {
            Console.WriteLine("Second Delegate ...");
        }

        static void Main(string[] args)
        {
            MultiMethod dlg;

            dlg = new MultiMethod( FirstDelegate);
            dlg();
            dlg += new MultiMethod(SecondDelegate);
            Console.WriteLine();
            dlg();
            dlg -= new MultiMethod(FirstDelegate);
            Console.WriteLine();
            dlg();
        }
    }
}
