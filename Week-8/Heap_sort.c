#include <stdio.h>
#include <conio.h>

void heap_sort(int a[], int n);
void heap_const(int a[], int n);
void heap_adj(int a[], int n);

void main()
{
int n, i, a[50];

printf("Enter number of elements\n");
scanf("%d", &n);

printf("Enter array elements\n");
for(i = 0; i < n; i++)
scanf("%d", &a[i]);

heap_sort(a, n);

printf("Sorted array\n");
for(i = 0; i < n; i++)
printf("%d ", a[i]);

getch();
}

void heap_sort(int a[], int n)
{
int i, temp;

heap_const(a, n);

for(i = n - 1; i > 0; i--)
{
temp = a[0];
a[0] = a[i];
a[i] = temp;

heap_adj(a, i);
}
}

void heap_const(int a[], int n)
{
int i, j, k, item;

for(k = 1; k < n; k++)
{
item = a[k];
i = k;
j = (i - 1) / 2;

while(i > 0 && item > a[j])
{
a[i] = a[j];
i = j;
j = (i - 1) / 2;
}

a[i] = item;
}
}

void heap_adj(int a[], int n)
{
int i, j, item;

j = 0;
item = a[j];
i = 2 * j + 1;

while(i <= n - 1)
{
if(i + 1 <= n - 1)
{
if(a[i] < a[i + 1])
i++;
}

if(item < a[i])
{
a[j] = a[i];
j = i;
i = 2 * j + 1;
}
else
break;
}

a[j] = item;
}
