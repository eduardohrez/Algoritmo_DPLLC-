/*contruct by Eduardo H_R */
#include <iostream>
#include <string.h>
#include "algpdll.h"

using namespace std;

int main ()
{
    int size1=0;
    //string ejemp1=("(A|~B)&(~A|C)&(~B|~C)&(C)")
    //string ejemp1=("(~x1|~x2)&(x1|~x2)&(~x1|~x3)"
    //string ejemp1=("(x2 | ~x3 | ~x1) & (x2 | x6 | x3) & (x2 | ~x6 ) & (x1 | x5)");
    //string ejemp1=("(x1|x2 )&(y1|~x1)&(x3|~x1)&(x4|~y2|~x1)&(x4|z1|~x1)&(x4|m1|~x1)&(z1|~x4|~x1)&(z1|m1|~x1)&(~m1|~x4|~x1)&(~m1|~z1|~x1)&(y2|~x2)&(x5|~x2)&(t1|~z1|~x2)&(t1|m1|~x2)&(z1|~t1|~x2)&(z1|m1|~x2)&(~m1|~x4|~x2)&(~m1|~z1|~x2)&(~x4|~t1|~z1|~m1)");
    string ejemp1=("(x1|x2 )&(y1|~x1)&(x3|~x1)&(x4|~y2 |~x1)&(x4| z1|~x1)&(x4|m1|~x1)&(z1|~x4|~x1)&(z1|m1|~x1)&(~m1|~x4|~x1)&(~m1|~z1|~x1)&(y2|~x2)&(x5|~x2)&(t1|~z1|~x2)&(t1|m1|~x2)&(z1|~t1|~x2)&(z1|m1|~x2)&(~m1|~x4|~x2)&(~m1|~z1|~x2)&(~x4|~t1|~z1|~m1)"); // crear la formula conjuntiva que se enviara y procesara
    algpdll *example= new algpdll(ejemp1); // crear el objeto de la libreria y se envia la formula

    cout<<example->gen_llproces()<<endl; // regreso de las varaibles las cuales hace a la formula verdadera en caso que lo sea de otra forma regresara empty

}