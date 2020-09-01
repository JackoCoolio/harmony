#include "harmony_entry.h"
#include "harmony_log.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    harmony_log("Harmony Engine initialized!\n");
    
	return harmony_createApplication(argc, argv);
}