
import java.util.*;

class QuickSort
{

    public static void printArray(int[] list)
    {
	for (int i = 0; i < list.length - 1; i++)
	    System.out.print(list[i] + ", ");
	System.out.println(list[list.length - 1]);
    }

    public static void sort(int[] list, int low, int high)
    {
	int i = low;
	int j = high;
	// calc pivot
	int pivot = list[low + (high - low) / 2];
	// split
	while (i <= j)
	{
	    while (list[i] < pivot) i++;
	    while (list[j] > pivot) j--;
	    if (i <= j)
	    {
		int temp = list[i];
		list[i] = list[j];
		list[j] = temp;
		i++;
		j--;
	    }
	}
	if (low < j) sort(list, low, j);
	if (i < high) sort(list, i, high);
    }

    public static void main(String[] args)
    {
	
	int size = Integer.parseInt(args[0]);
	int[] list = new int[size];
	System.out.print("Generating Numbers");
	int frac = size / 10;
	for (int i = 0; i < size; i++)
	{
	    if (i % frac == 0) System.out.print(".");
	    int n = (int)(Math.random() * 100000);
	    list[i] = n;
	}
	System.out.println("\nSorting");
	long startTime = System.currentTimeMillis();

	//int[] list = {1, 3, 2, 5, 4, 7, 6, 9, 8};
	QuickSort.sort(list, 0, list.length - 1);
	long stopTime = System.currentTimeMillis();
	System.out.println("Done!");
	System.out.println("Sort finished sorting " + size + " elements in " + (stopTime - startTime) + " milliseconds");
	//printArray(list);
    }
}
