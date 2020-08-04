#include "harmony_entry.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    printf("Harmony Engine initialized!\n");

	return harmony_createApplication(argc, argv);
}