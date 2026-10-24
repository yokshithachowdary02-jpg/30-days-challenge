#include <stdio.h>

void rotate(int a[], int n, int k)
{
    int i, temp;
    k = k % n;
    if (k < 0)
        k += n;

    for (i = 0; i < k; i++)
    {
        temp = a[n - 1];
        for (int j = n - 1; j > 0; j--)
            a[j] = a[j - 1];
        a[0] = temp;
    }
}

int main()
{
    int a[12], n, i, j, k, r, d;
    int total = 0, minimum, maximum;
    int second = 0, found = 0;
    int peakCount = 0, run = 1, longest = 1;
    int divisibleCount = 0;
    float average;

    do
    {
        printf("Enter N (5 to 12): ");
        if (scanf("%d", &n) != 1)
            return 1;
        if (n < 5 || n > 12)
            printf("Invalid input. Try again.\n");
    } while (n < 5 || n > 12);

    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Enter reading (0 to 1000): ");
            if (scanf("%d", &a[i]) != 1)
                return 1;
            if (a[i] < 0 || a[i] > 1000)
                printf("Invalid reading. Try again.\n");
        } while (a[i] < 0 || a[i] > 1000);
    }

    printf("Original readings: ");
    minimum = maximum = a[0];
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        total += a[i];
        if (a[i] < minimum)
            minimum = a[i];
        if (a[i] > maximum)
            maximum = a[i];
    }
    average = (float)total / n;

    printf("\nSum=%d", total);
    printf("\nAverage=%f", average);
    printf("\nMinimum=%d", minimum);
    printf("\nMaximum=%d", maximum);

    for (i = 0; i < n; i++)
    {
        if (a[i] < maximum && (!found || a[i] > second))
        {
            second = a[i];
            found = 1;
        }
    }

    if (found)
        printf("\nSecond largest=%d", second);
    else
        printf("\nNo second-largest distinct value");

    for (i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            peakCount++;
        }
    }

    for (i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            run++;
        else
            run = 1;
        if (run > longest)
            longest = run;
    }

    printf("\nLocal peaks=%d", peakCount);
    printf("\nLongest increasing run=%d", longest);

    while (1)
    {
        printf("\nEnter K: ");
        if (scanf("%d", &k) == 1)
            break;
        printf("Invalid input. Try again.\n");
        while (getchar() != '\n');
    }

    rotate(a, n, k);

    printf("Rotated readings: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    while (1)
    {
        printf("\nEnter R (0 to 99): ");
        if (scanf("%d", &r) == 1 && r >= 0 && r <= 99)
            break;
        printf("Invalid input. Try again.\n");
        while (getchar() != '\n');
    }

    d = (r % 9) + 1;
    for (j = 0; j < n; j++)
    {
        if (a[j] % d == 0)
            divisibleCount++;
    }

    printf("\nD=%d", d);
    printf("\nDivisible count=%d\n", divisibleCount);

    return 0;
}
