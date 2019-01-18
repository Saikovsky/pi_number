#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
    int centra;
    int los_x,los_y, los_c;
    int pole_kwadratu;
    int trafienia=0,wszystko=0;
    int x=100,y=100;
    pole_kwadratu=x*y;
    fstream plik("test.pgm",ios::out);
    plik<<"P2\n"<<x<<" "<<y<<"\n 255\n";
    int r = x/2;
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=x;j++)
        {
            centra = sqrt((i-r)*(i-r)+(j-r)*(j-r));
            los_x = (rand() % x)+1;
            los_y = (rand() % y)+1;
            los_c = sqrt((los_x-r)*(los_x-r)+(los_y-r)*(los_y-r));
            wszystko++;
            {
                if(centra<=r)
                {
                    trafienia++;
                    if(los_c<=r)
                    {
                        plik<<"0 ";

                    }
                    else plik<<"200 ";
                }
                else if(centra>r)
                {
                    if (los_c>r) plik<<"0 ";
                    else plik<<"255 ";
                }
            }
        }
        plik<<endl;
    }

    long double pi;
    long double pole_kola;
    float trf = trafienia;
    float wsf = wszystko;
    float rf = r;
    float pol_kw = pole_kwadratu;
    pole_kola = (trf/wsf)*pol_kw;
    pi = pole_kola/(rf*rf);
    cout<<pi;
    plik.close();
    return 0;
}
