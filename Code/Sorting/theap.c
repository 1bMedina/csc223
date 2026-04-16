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



#include "bdsctest.h"
#include "heapsort.h"

#define MAX_INTS 100

arrays_eq(a, b, n)
int a[];
int b[];
int n;
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

copy_arr(src, dst, n)
int src[];
int dst[];
int n;
{
    int i;
    for (i = 0; i < n; i++)
        dst[i] = src[i];
}

t_normal()
{
    int arr[6];
    int exp[6];
    int data[6];
    data[0] = 5;
    data[1] = 3;
    data[2] = 8;
    data[3] = 1;
    data[4] = 9;
    data[5] = 2;
    exp[0] = 1;
    exp[1] = 2;
    exp[2] = 3;
    exp[3] = 5;
    exp[4] = 8;
    exp[5] = 9;
    copy_arr(data, arr, 6);
    hsort(arr, 6);
    ASSERT(arrays_eq(arr, exp, 6));
}

t_sorted()
{
    int arr[5];
    int exp[5];
    arr[0] = 1;  arr[1] = 2;  arr[2] = 3;
    arr[3] = 4;  arr[4] = 5;
    exp[0] = 1;  exp[1] = 2;  exp[2] = 3;
    exp[3] = 4;  exp[4] = 5;
    hsort(arr, 5);
    ASSERT(arrays_eq(arr, exp, 5));
}

t_revsrt()
{
    int arr[5];
    int exp[5];
    arr[0] = 5;  arr[1] = 4;  arr[2] = 3;
    arr[3] = 2;  arr[4] = 1;
    exp[0] = 1;  exp[1] = 2;  exp[2] = 3;
    exp[3] = 4;  exp[4] = 5;
    hsort(arr, 5);
    ASSERT(arrays_eq(arr, exp, 5));
}

t_single()
{
    int arr[1];
    arr[0] = 42;
    hsort(arr, 1);
    ASSERT(arr[0] == 42);
}

t_dupes()
{
    int arr[6];
    int exp[6];
    arr[0] = 4;  arr[1] = 2;  arr[2] = 4;
    arr[3] = 1;  arr[4] = 2;  arr[5] = 4;
    exp[0] = 1;  exp[1] = 2;  exp[2] = 2;
    exp[3] = 4;  exp[4] = 4;  exp[5] = 4;
    hsort(arr, 6);
    ASSERT(arrays_eq(arr, exp, 6));
}

t_fileio()
{
    int data[MAX_INTS];
    int n;
    int i;
    int ok;
    int val;
    FILE *fin;
    FILE *fout;
    fin = fopen("input.txt", "r");
    ASSERT(fin != 0);
    n = 0;
    while (n < MAX_INTS) {
        if (fscanf(fin, "%d", &val) != 1)
            break;
        data[n] = val;
        n = n + 1;
    }
    fclose(fin);
    ASSERT(n > 0);
    hsort(data, n);
    ok = 1;
    for (i = 0; i < n - 1; i++) {
        if (data[i] > data[i + 1]) {
            ok = 0;
            break;
        }
    }
    ASSERT(ok);
    fout = fopen("output.txt", "w");
    ASSERT(fout != 0);
    for (i = 0; i < n; i++)
        fprintf(fout, "%d\n", data[i]);
    fclose(fout);
}

main()
{
    START_TESTING("Heap Sort");
    TEST_CASE("Normal sort");
    t_normal();
    TEST_CASE("Already sorted");
    t_sorted();
    TEST_CASE("Reverse sorted");
    t_revsrt();
    TEST_CASE("Single element");
    t_single();
    TEST_CASE("Duplicates");
    t_dupes();
    TEST_CASE("File IO");
    t_fileio();
    END_TESTING();
}
