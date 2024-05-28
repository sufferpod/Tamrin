// AmirSadra Charmforushan
// Mobina Miri
#include <iostream>
using namespace std;

int *findMax(int *[]);
int main()
{
    int n;
    cin >> n;
    int **pa = new int *[n + 1];
    for (int i = 0; i < n; i++)
    {
        pa[i] = new int();
        cin >> *pa[i];
    }
    pa[n] = NULL;
    int *a = (findMax(pa));
    cout << *a;
    for (int i = 0; i < n; i++)
    {
        delete pa[i];
    }
    delete[] pa;
    return 0;
}

int *findMax(int *pa[])
{
    int *max = pa[0];
    for (int i = 0; pa[i] != NULL; i++)
    {
        if (*pa[i] > *max)
            max = pa[i];
    }
    return max;
}