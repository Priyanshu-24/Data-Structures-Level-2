// make a max heap from the given array
// leaf nodes need not to be heapified, so taking starting index in build_head from the first non-leaf element

// now make the last element as largest element and call heapify for the rest

void heap_sort(int a[], int n)
{
	build_heap(a, n);       // making max heap

	for(int i=n-1;i>=0;i--)
	{
		swap(a[0], a[i]);        // as a[0] is the largest term

		heapify(a,i,0);         // call heapify on the reduced heap
	}
}

void build_heap(int a[], int n)      // building max heap
{
	for(int i=n/2-1;i>=0;i--)
		heapify(a,n,i);
}

void heapify(int a[], int n, int i)
{
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;

	if(left<n && a[left] > a[largest])
		largest = left;

	if(right<n && a[right] > a[largest])
		largest = right;

    
    if(largest != i)              // if root is not largest
    {
    	swap(a[largest], a[i]);   // make root the largest element

    	heapify(a,n,largest);     // heapify the affected sub-tree
    }
	
}

// in-place sorting alogorithm
// not stable => as operations in heap can change the relative position of the elements

