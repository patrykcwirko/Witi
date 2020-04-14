#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;


struct PWD
{
    uint32_t p;
    uint32_t w;
    uint32_t d;
    uint32_t o;
};

uint32_t schedule(const std::string& data_set)
{
    uint32_t N, x = 0;
    vector<PWD> dane;
    fstream data("witi_data.txt");
    string tmp;
    uint32_t m = 0, c = 0, temp = 0;

    dane.reserve(100);
    //pomija dupuki nie natrafi na np. data.12
    while (tmp != data_set) data >> tmp;

    //zczytuje ilość zadań
    data >> N;

    //zczytuje parametry zadań
    for (uint32_t i = 0; i < N; ++i)
    {
        uint32_t p, w, d;
        data >> p >> w >> d;
        dane.push_back(PWD{ p,w,d,i });
    }


    for (uint32_t i = 0; i < N; ++i)
    {
        m = m + dane[i].p;
        //sprawda czy suma p, które były jest mniejsza od d aktualnego zadania
        if (m < dane[i].d)temp = 0; else temp = m - dane[i].d;
        c = c + (temp)*dane[i].w;
        //cout << c << endl;
    }

    return c;
}

int main()
{
    cout << "\n" << "suma witi: " << schedule("data.15:") << endl;

    return 0;
}

