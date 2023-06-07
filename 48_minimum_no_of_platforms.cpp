int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);

    int i = 1, j = 0;
    int np = 1;
    int mp = 1;
    while (i < n)
    {
        if (at[i] <= dt[j])
        {
            np++;
            mp = max(mp, np);
            i++;
        }
        else
        {
            j++;
            np--;
        }
    }
    return mp;
}