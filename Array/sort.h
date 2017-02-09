#ifndef sort
#define sort

#define INT_MAX 65535
#define INT_MIN -65535

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int getPartition(int *a,int start,int end)
{
	int pivot = end,index = start,i,temp;

	for(i = start ; i < end ; ++i)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i],&a[index]);
			++index;
		}
	}

	swap(&a[pivot],&a[index]);

	return index;
}

void quickSort(int *a,int start,int end)
{
	if(start<end)
	{
		int part = getPartition(a,start,end);
		quickSort(a,start,part-1);
		quickSort(a,part+1,end);
	}	
}

void insertionSort(int *a,int size)
{
int last = size-1,start = 1,hole,temp;

	while(start < size)
	{
		hole = start;
		temp = a[start];

		while(hole > 0 && a[hole-1] > temp)
		{
			a[hole] = a[hole-1];
			--hole;
		}

		a[hole] = temp;
		++start;
	}
}

void bubbleSort(int *a,int size)
{
int i,j,n = size-1;

	for(i = 0 ; i < size ; ++i)
	{
		for(j = 0 ; j < n - i ; ++i)
		{
			if(a[j] > a[j+1])
				swap(&a[j+1],&a[j]);
		}
	}
}


void selectionSort(int *a,int size)
{
int i,j,n = size - 1;

	for(i = 0 ; i < size ; ++i)
	{
		for(j = i+1 ; j < n ; ++j)
		{
			if(a[i] > a[j])
				swap(&a[i],&a[j]);
		}
	}
}

int getMax(int *a,int size)
{
int i,max = INT_MAX;

	for(i = 0 ; i < size ; ++i)
	{
		if(a[i] > max)
			max = a[i];
	}

	return max;
}

void Sort(int *a,int size,int exp)
{
int count[10] = {0};
int temp[size];
int i;

	for(i = 0 ; i < size ; ++i)
		++count[(a[i]/exp)%10];

	for(i = 1 ; i < size ; ++i)
		count[i] += count[i-1];

	for(i = size-1; i >= 0 ; --i)
	{
		temp[count[(a[i]/exp)%10]-1] = a[i];
		--count[(a[i]/exp)%10];
	}

	for(i = 0 ; i < size ; ++i)
		a[i] = temp[i];
}

void radixSort(int *a,int size)
{
int i,max;

	max = getMax(a,size);

	for(i = 1 ; (max/i) > 0 ; i *= 10)
		Sort(a,size,i);
	
}

#endif
