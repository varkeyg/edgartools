#include <iostream>
#include "common.h"
#include "insider.h"

using namespace std;

int main()
{
    //Baglino Andrew D - TSLA
    //https://www.sec.gov/Archives/edgar/data/1318605/000179056521000003/0001790565-21-000003-index.htm
    string url = "https://www.sec.gov/Archives/edgar/data/1318605/000179056521000003/0001790565-21-000003.txt";

    Insider ins(url);
    ins.getTransactions();

    //cout << "Hellodd!" << endl;
    return 0;
}