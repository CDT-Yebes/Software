#include "scope.h"
#ifdef HAVE_ANSI_CPLUSPLUS_HEADERS
#include <iostream>
#else // HAVE_ANSI_CPLUSPLUS_HEADERS
#include <iostream.h>
#endif // HAVE_ANSI_CPLUSPLUS_HEADERS


using namespace std;

int main( int argc, char *argv[] )
{
    //kcg main test here is to test if "scope.*" generated files
    //really compile well. If we're here, then they probably compile.
    cout << "...passed" << endl;
}
