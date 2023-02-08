#include <string.h>
#include "NetworkGoban.hpp"
#include "GoBan.hpp"

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "usage: %s <local|network>\n", argv[0]);
        return -1;
    }
    if (strcmp(argv[1], "local") == 0)
    {
        GoBan go("tiechui", "cuihua");
        go.run();
    }
    else if (strcmp(argv[1], "network") == 0)
    {
        NetworkGoban netgo("tiechui", "cuihua");
        netgo.run();
    }
    else
    {
        cout << "unknow mode: " << argv[1] << endl;
        return -1;
    }
    return 0;
}
