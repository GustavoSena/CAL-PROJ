
#include <sstream>
#include "src/Base.h"
#include "src/menus.h"
#include "src/graphDrawing.h"
#include "src/resultGenerator.h"


using namespace std;





int main() {

    Base b("..\\resources\\files\\Base.txt");
    int id=main_menu(b);
    chooseCity(&b);
    chooseAlgorithm(&b,id);

    b.updateFiles();

    exit(0);
}







