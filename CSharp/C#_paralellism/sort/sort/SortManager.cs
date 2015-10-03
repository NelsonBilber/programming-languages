using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Diagnostics;

namespace SortParallel
{
    class SortResults : IDisposable
    {
        public  SortResults(string name)
        {
             sortName = name;
             _stopwatch.Start();
        }

        private Stopwatch _stopwatch = new Stopwatch();
        private string sortName;

        public void Dispose()
        {
            _stopwatch.Stop();
            results.Add(string.Format("{0} : {1:N0}ms", sortName, 
                _stopwatch.ElapsedMilliseconds));
        }

        static public List<string> results { get { return propResult; } }
        static private List<string> propResult = new List<string>();
    }

    class SortManager
    {
        private static List<int> integerList = new List<int>();
        private static Barrier sortBarrier = new Barrier(3);

        private static void PopulateIntegerList(uint size)
        {
            Random randomNumber = new Random(DateTime.Now.Millisecond);
            for (int count = 0; count < size; ++count)
            {
                integerList.Add(randomNumber.Next());
            }
        }

       public static void DoSort(uint length)
        {

            PopulateIntegerList(100000);

            // Bubble Sort Region

			/* List<int> bubbleList = integerList.ToList();
            Task taskBubbleSort = new Task(() => 
            {
               sortBarrier.SignalAndWait();
               using (new SortResults("Bubble Sort"))
               {
                   SortAlgorithms.BubbleSort(bubbleList);
               }
            });
            taskBubbleSort.Start();*/
   
            // Insertion Sort Region

            List<int> insertionList = integerList.ToList();
            Task taskInsertionSort = new Task(() => 
            {
                sortBarrier.SignalAndWait(); 
                using (new SortResults("Insertion Sort"))
                {
                    SortAlgorithms.InsertionSort(insertionList); 
                }
            });
            taskInsertionSort.Start();

            // Pivot Sort Region
			/*
            List<int> pivotList = integerList.ToList();
            Task taskPivotSort = new Task(() => 
            {
                sortBarrier.SignalAndWait(); 
                using (new SortResults("Pivot Sort"))
                {
                    SortAlgorithms.PivotSort(pivotList, 0, pivotList.Count-1, 1); 
                }
            });
            taskPivotSort.Start();*/

           // Wait for the sorts to complete and display results

			//Task.WaitAll(new Task[] { taskBubbleSort, taskInsertionSort, taskPivotSort });
			//Task.WaitAll(new Task[] { taskBubbleSort });
			Task.WaitAll(new Task[] { taskInsertionSort });
			//Task.WaitAll(new Task[] { taskPivotSort });
           foreach (string result in SortResults.results)
           {
               Console.WriteLine(result);
           }

           Console.WriteLine("Press enter to exit");
           Console.ReadLine();
       }

    }
}
