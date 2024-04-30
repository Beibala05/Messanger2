#include "../include/include.h"
#include "../messanger/messanger.h"

#include <iostream>

#if defined(__linux__) || defined(_WIN32)

class Messanger;

int main(int argc, char** argv)
{
        Application app(argc, argv);

        Messanger messanger;
        messanger.show();

        return app.exec();
}

#else
        #error "run failure"
#endif