#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    Base *tmp = generate();
    identify(tmp);
}
