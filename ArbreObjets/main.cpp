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
