Enable desktop notifications for Virginia's Community Colleges Mail.
   OK  No thanks

1 of 3,731
code
Inbox

Conrad Skelly <cgs46207@email.vccs.edu>
Attachments
Apr 15, 2026, 9:21 PM (10 hours ago)
to me

hi here is updated code! should work. 

for file IO make a input.txt and put one int per line ex:

66
12
24
18
89

it should give a sorted file called output.txt I had trouble seeing the contents of this txt on my machine so if you also have trouble use the a:w command to write it to the folder you cpm is in and read it for there!
 3 Attachments
  •  Scanned by Gmail



#include "heapsort.h"

swap(arr, i, j)
int arr[];
int i;
int j;
{
    int tmp;
    tmp    = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

sift_dn(arr, root, last)
int arr[];
int root;
int last;
{
    int left;
    int large;
    int going;
    going = 1;
    while (going) {
        left  = 2 * root + 1;
        large = root;
        if (left <= last)
            if (arr[left] > arr[large])
                large = left;
        if (left + 1 <= last)
            if (arr[left + 1] > arr[large])
                large = left + 1;
        if (large == root) {
            going = 0;
        } else {
            swap(arr, root, large);
            root = large;
        }
    }
}

hsort(arr, n)
int arr[];
int n;
{
    int i;
    int tail;
    if (n < 2)
        return;
    for (i = n / 2 - 1; i >= 0; i--)
        sift_dn(arr, i, n - 1);
    for (tail = n - 1; tail > 0; tail--) {
        swap(arr, 0, tail);
        sift_dn(arr, 0, tail - 1);
    }
}
