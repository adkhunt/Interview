#include<stdio.h>

int findPivot (int *array, int start, int end){

   if (start > end)
      return -1;

   if (start == end)
      return start;

   int mid = (start + end) / 2;

   if (array[mid] > array[mid+1])
      return mid;

   else if (array[mid] < array[mid-1])
      return mid-1;

   else if (array[start] < array[mid])
      return findPivot(array, mid + 1, end);

   return findPivot (array, start, mid-1);
}

int binarySearch (int *array, int start, int end, int elemToSearch)
{

   if(start > end)
      return -1;

   if (array[start] == elemToSearch)
      return start;

   if (array[end] == elemToSearch)
      return end;

   int mid = (start + end) / 2;

   if (array[mid] == elemToSearch)
      return mid;

   if (array[mid] > elemToSearch)
      return binarySearch(array, start, mid-1, elemToSearch);

   return binarySearch(array, mid+1, end, elemToSearch);
}

int searchElem(int *array, int end, int elemToSearch){

  int pivot = findPivot(array, 0, end);

  if (pivot == -1){

      printf ("Array is not rotated\n");
      return -1;
  }

  if (array[pivot] == elemToSearch)
     return pivot;

   if (array[0] > elemToSearch)
      return binarySearch (array, pivot + 1, end, elemToSearch);

   return binarySearch (array, 0, pivot-1, elemToSearch);
}

int main()
{
int array[] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
int size = sizeof(array)/sizeof(array[0]);
int elemToSearch;

   printf ("SIZE = %d\n",size);
   printf ("Enter element to search in array.\n");
   scanf ("%d",&elemToSearch);

   int index = searchElem (array, size-1, elemToSearch);

   if (index == -1){
      printf ("No Element present in array.\n");
   }else{
      printf ("Element Index = %d\n",index);
   }

   return 0;
}
