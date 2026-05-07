#include <stdio.h>

#define LEFT 0
#define RIGHT 1

// Function to find position of an element
int searchArr(int a[], int n, int mobile)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == mobile)
            return i;
    }
    return -1;
}

// Function to find largest mobile element
int getMobile(int a[], int dir[], int n)
{
    int mobile_prev = 0;
    int mobile = 0;

    for(int i = 0; i < n; i++)
    {
        // LEFT direction
        if(dir[a[i]-1] == LEFT && i != 0)
        {
            if(a[i] > a[i-1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }

        // RIGHT direction
        if(dir[a[i]-1] == RIGHT && i != n-1)
        {
            if(a[i] > a[i+1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }

    return mobile;
}

// Function to print permutation
void printPermutation(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

// Johnson Trotter function
void johnsonTrotter(int n)
{
    int a[n];
    int dir[n];

    // Initialize permutation and directions
    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    // Print first permutation
    printPermutation(a, n);

    while(1)
    {
        int mobile = getMobile(a, dir, n);

        // If no mobile element
        if(mobile == 0)
            break;

        int pos = searchArr(a, n, mobile);

        // Swap according to direction
        if(dir[mobile - 1] == LEFT)
        {
            int temp = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = temp;
            pos--;
        }
        else if(dir[mobile - 1] == RIGHT)
        {
            int temp = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = temp;
            pos++;
        }

        // Reverse directions of elements greater than mobile
        for(int i = 0; i < n; i++)
        {
            if(a[i] > mobile)
            {
                if(dir[a[i] - 1] == LEFT)
                    dir[a[i] - 1] = RIGHT;
                else
                    dir[a[i] - 1] = LEFT;
            }
        }

        printPermutation(a, n);
    }
}

int main()
{
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
