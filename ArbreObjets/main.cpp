#include <QCoreApplication>
#include "Instance.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Instance i1("i1");
    Instance i2("i2", &a);
    Instance i3("i3", &i2);

    {
    Instance i4("i4", &i1);
    }

    Instance *i5 = new Instance("i5", &a);
    new Instance("i6", i5);

    new Instance("i7"); //Cette instance ne devrait pas être détruite...
}

/*

  a  : 0x2ab0           -> détruit en 7
    |- i2 : 0x2a68      -> détruit en 3
        |- i3 : 0x2a48  -> détruit en 2
    |- i5 : 0x4da0      -> détruit en 5
        |- i6 : 0x9640  -> détruit en 6

  i1 : 0x2a98           -> détruit en 4
    |- i4 : 0x2a28      -> détruit en 1

  i7 : 0x5ff0


 */
