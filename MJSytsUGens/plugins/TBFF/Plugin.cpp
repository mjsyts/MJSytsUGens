#include "TBFF.h"

static InterfaceTable* ft;

PluginLoad(TBFFUGens) {
    ft = inTable;
    registerUnit<TBFF>(ft, "TBFF", false);
}
