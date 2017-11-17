#include <iostream>
#include <fstream>

using namespace std;

void nuskaitymas();
void kiekporu();
void spausdinimas();

int n, virporu, motporu;

int VK[59], VD[59], MK[59], MD[59];

int main() // pagrindine programa
{
    nuskaitymas();
    kiekporu();
    spausdinimas();

    return 0;
}

void nuskaitymas() // skaitymas is failo
{


    int g, p, s;
    ifstream fd("U1.txt");
    fd >> n;
    for(int i=0; i<n; i++)
    {
        VK[i] = 0;
        VD[i] = 0;
        MK[i] = 0;
        MD[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        fd >> g;
        fd >> p;
        fd >> s;
        if(g == 3 && p == 1) VK[s]++;
        if(g == 3 && p == 2) VD[s]++;
        if(g == 4 && p == 1) MK[s]++;
        if(g == 4 && p == 1) MD[s]++;
    }
    fd.close();
}

void kiekporu() // skaicuoju kiek virisku ir moterisku poru
{
    for(int i=0; i<59; i++)
    {
        if(VK[i]+VD[i]>=2) virporu = (VK[i]+VD[i])/2;
        if(MK[i]+MD[i]>=2) motporu = (MK[i]+MD[i])/2;
    }
}

void spausdinimas() // isvedimas i faila
{
    ofstream fr("U1rez.txt");
    fr << motporu << endl;
    fr << virporu << endl;
    fr.close();
}
