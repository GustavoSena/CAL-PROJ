
#include <sstream>
#include "src/Base.h"
#include "src/menus.h"

using namespace std;


int main() {

    Base b("..\\resources\\files\\Base.txt");
    main_menu(&b);
    b.updateFiles();

    exit(0);
}







