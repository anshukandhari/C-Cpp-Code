#include <cstdio>
#include <algorithm>
#include <cmath>
#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;

struct point
{
    long x, y;
};
struct dist
{
    long  x_1,y_1,x_2,y_2, distance;
} dis;

inline bool OrdX(const point &a, const point &b)
{
    if(a.x==b.x)
    {
        return a.y<b.y;
    }
    return a.x<b.x;
}

inline int OrdY(const point &a, const point &b)
{
    if(a.y==b.y)
    {
        return a.x<b.x;
    }
    return a.y<b.y;
}


// is - function that check is a an element of X_L array
inline bool is(const point &a, point *X_L, int p, int k)
{
    if(p<=k)
    {
        int center = (p+k)/2;

        if(X_L[center].x == a.x)
        {
            return true;
        }
        if(X_L[center].x > a.x)
        {
            return is(a, X_L, p, center-1);
        }
        else
        {
            return is(a, X_L, center+1, k);
        }
    }

    return false;
}


// odl - function takes two points and return distance between them ^2
inline long long odl(const point &a, const point &b)
{
    return ((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y));
}


int tmp;

// fun - function that returns the pair of closest points using divide & conquer
struct dist fun(int n, point *X, point *Y)
{
    // if there are less that 4 points - it checks it using bruteforce
    if(n<4)
    {
        if(odl(X[0], X[1]) < dis.distance)
        {
            dis.distance = odl(X[0],X[1]);
            dis.x_1 = X[0].x;
            dis.y_1 = X[0].y;
            dis.x_2 = X[1].x;
            dis.y_2 = X[1].y;
        }

        if(n==3)
        {
            if(odl(X[0], X[2]) < dis.distance)
            {
                dis.distance = odl(X[0],X[2]);
                dis.x_1 = X[0].x;
                dis.y_1 = X[0].y;
                dis.x_2 = X[2].x;
                dis.y_2 = X[2].y;
            }
            if(odl(X[1], X[2]) < dis.distance)
            {
                dis.distance = odl(X[1],X[2]);
                dis.x_1 = X[1].x;
                dis.y_1 = X[1].y;
                dis.x_2 = X[2].x;
                dis.y_2 = X[2].y;
            }
        }
    }
    // otherwise it divides points into two arrays and runs fun 
    // recursively foreach part
    else
    {
        int p=n/2;

        int PPP = (X[p].x + X[p-1].x)/2;


        point *X_L = new point[p];
        point *X_R = new point[n-p];
        point *Y_L = new point[p];
        point *Y_R = new point[n-p];

        REP(i,p)
        X_L[i] = X[i];

        for(int r=p; r<n; r++)
        {
            X_R[r-p] = X[r];
        }

        int length_Y_L = 0;
        int length_Y_R = 0;

        REP(i,n)
        {
            if(is(Y[i], X_L, 0, p))
            {
                Y_L[length_Y_L++] = Y[i];
            }
            else
            {
                Y_R[length_Y_R++] = Y[i];
            }
        }


        dist D_L = fun(p, X_L, Y_L);
        dist D_R = fun(n-p, X_R, Y_R);
        dist D;

        if(D_L.distance < D_R.distance)
        {
            D = D_L;
        }
        else
        {
            D = D_R;
        }

        tmp = 0;
        point *Y2 = new point[n];

        double from = sqrt((double)D.distance);

        for(int r=0; r<n; r++)
        {
            if(Y[r].x > (long long)PPP-from && Y[r].x < (long long)PPP + from)
            {
                Y2[tmp++] = Y[r];
            }
        }

        //--tmp;
        //int xxx = min(7, tmp-r);
        int r = 0;
        for(int j=1; j<min(7, tmp-r); j++)
        {
            if(odl(Y2[r], Y2[r+j]) < D.distance)
            {
                D.distance = odl(Y2[r], Y2[r+j]);
                D.x_1 = Y2[r].x;
                D.y_1 = Y2[r].y;
                D.x_2 = Y2[r+j].x;
                D.y_2 = Y2[r+j].y;
            }
            r++;
        }

        dis = D;

    }
    return dis;
}

int main()
{
    int n;

    n = 7;

    point *X = new point[n];
    point *Y = new point[n];

    for(int i=0; i< 7; i++)
    {
        X[i].x = 0;
        X[i].y = 10*i;
    }

    /*
    REP(i,n)
    {
    scanf("%lld %lld", &X[i].x, &X[i].y);
    }
    */
    sort(X, X+n, OrdX);

    REP(i,n)
    Y[i] = X[i];

    sort(Y, Y+n, OrdY);

    dis.distance = odl(X[0], X[1]);

    dis.x_1 = X[0].x;
    dis.y_1 = X[0].y;
    dis.x_2 = X[1].x;
    dis.y_2 = X[1].y;

    dist wynik = fun(n, X, Y);

    printf(" %lld %lld\n %lld %lld\n", wynik.x_1, wynik.y_1, wynik.x_2, wynik.y_2);
    return 0;
}
