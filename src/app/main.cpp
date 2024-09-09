#include "../include/include.h"
#include "../messanger/messanger.h"

#include <iostream>

#ifdef __linux__

struct Messanger;

int main(int argc, char** argv)
{
        Application app(argc, argv);

        Messanger messanger;
        messanger.show();

        return app.exec();
}

#else
        #error "linux only"
#endif