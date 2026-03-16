#include <stdio.h>

#define MAXSIZE 100

int heap[MAXSIZE];
int hsize;

initheap()
{
    hsize = 0;
}

swap(arr, a, b)
int arr[];
int a, b;
{
    int t;
    t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

insert(val)
int val;
{
    int pos, parent;

    if (hsize >= MAXSIZE) {
        printf("Heap is full\n");
        return 0;
    }

    heap[hsize] = val;
    pos = hsize;
    hsize = hsize + 1;

    while (pos > 0) {
        parent = (pos - 1) / 2;

        if (heap[parent] >= heap[pos])
            break;

        swap(heap, parent, pos);
        pos = parent;
    }

    return 1;
}

removemax()
{
    int top, i, left, right, largest;

    if (hsize == 0) {
        printf("Heap is empty\n");
        return -1;
    }

    top = heap[0];
    heap[0] = heap[hsize - 1];
    hsize = hsize - 1;

    i = 0;

    for (;;) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if (left < hsize && heap[left] > heap[largest])
            largest = left;

        if (right < hsize && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(heap, i, largest);
        i = largest;
    }

    return top;
}

printheap()
{
    int i;

    if (hsize == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Heap: ");
    for (i = 0; i < hsize; i++) {
        printf("%d ", heap[i]);
    }

    printf("\nMax: %d\n", heap[0]);
}

main()
{
    int choice, val, removed;

    initheap();

    for (;;) {
        printf("\n1 Insert\n2 Remove Max\n3 Display\n4 Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            insert(val);
            printf("Inserted %d\n", val);
        }
        else if (choice == 2) {
            removed = removemax();
            if (removed != -1)
                printf("Removed max: %d\n", removed);
        }
        else if (choice == 3) {
            printheap();
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
