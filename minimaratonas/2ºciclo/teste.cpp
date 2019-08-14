#include<bits/stdc++.h>
using namespace std;

typedef struct Coordenadas
{
    double x;
    double y;
}C;

bool compara(C a,C b)
{
    if(a.y == b.y)
    {
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main()
{
    C v[10];

    scanf("%lf %lf",&v[0].x,&v[0].y);

    scanf("%lf %lf",&v[1].x,&v[1].y);

    scanf("%lf %lf",&v[2].x,&v[2].y);

    double a = ((v[2].y - v[1].y)) / (v[2].x - v[1].x);

    double b = v[2].y - (a * v[2].x);

    v[3].y = v[0].y;

    v[3].x = (v[3].y - b) / a;

    double h1 = v[2].y - v[0].y;

    double h2 = v[1].y - v[0].y;

    double ba = (v[3].x - v[0].x);

    double t1 = (h1 * ba) ;

    double t2 = (h2 * ba) ;

    cout << setprecision(0) << fixed;

    cout << abs( (t1 - t2)) << endl;

    return 0;
}
