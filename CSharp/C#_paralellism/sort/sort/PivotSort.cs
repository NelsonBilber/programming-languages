using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace SortParallel
{
    public partial class SortAlgorithms
    {
        public static void PivotSort(List<int> integerList, int start, int end, int pivot)
        {
            if (start < end)
            {
                pivot = integerList[end];
                int location = start;
                int bound = end;

                while (location < bound)
                {
                    if (integerList[location] < pivot)
                    {
                        ++location;
                    }
                    else
                    {
                        integerList[bound] = integerList[location];
                        integerList[location] = integerList[bound - 1];
                        --bound;
                    }
                }
                    // Console.WriteLine("start {0} end {1}", start, end);
                    //Console.WriteLine("====location ", location, "bound ", bound);
                    // Console.WriteLine("====pivot {0}", pivot);
                    integerList[bound] = pivot;
                    PivotSort(integerList, start, bound - 1, pivot);
                    PivotSort(integerList, bound + 1, end, pivot);
        
            }
/*            const int pivot = 0;
            List<int> left = new List<int>();
            List<int> right = new List<int>();

            if (sortedList.Count < 1)
            {
                return sortedList;
            }

            int pivotValue = sortedList[pivot];
            List<int> pivotList = new List<int>();
            pivotList.Add(pivotValue);
            sortedList.RemoveAt(pivot);

            for (int index = 0; index < sortedList.Count; ++index)
            {
                if (sortedList[index] <= pivotValue)
                {
                    left.Add(sortedList[index]);
                }
                else
                {
                    right.Add(sortedList[index]);
                }
            }
            List<int> rleft;
            List<int> rright;

            if (sortedList.Count >50)
            {
                double delta = ((double)left.Count) / right.Count;
                if ((delta > .75) && (delta < 1.333))
                {
                    var taskLeft = Task.Factory.StartNew(() => PivotSort(left));
                    var taskRight = Task.Factory.StartNew(() => PivotSort(right));
                    rleft = taskLeft.Result;
                    rright = taskRight.Result;
                }
                else
                {
                    rleft = PivotSort(left);
                    rright = PivotSort(right);
                }
            }
            else
            {
                rleft = PivotSort(left);
                rright = PivotSort(right);
            }
            rleft.Add(pivotValue);
            rleft.AddRange(rright);
            */


      
        }
    }     

}