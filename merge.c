#include <stdio.h>

int a[20], b[20];

void merge(int l, int m, int r)
{
    int i=l, j=m+1, k=l;

    while(i<=m && j<=r)
    {
        if(a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while(i<=m)
        b[k++] = a[i++];

    while(j<=r)
        b[k++] = a[j++];

    for(i=l; i<=r; i++)
        a[i] = b[i];
}

void sort(int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;

        sort(l,m);
        sort(m+1,r);
        merge(l,m,r);
    }
}

int main()
{
    int n,i;

    scanf("%d",&n);

    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    sort(0,n-1);

    for(i=0; i<n; i++)
        printf("%d ",a[i]);

    return 0;
}