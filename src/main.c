#include <stdio.h>
#include <windows.h>

#include "harmony.h"

int harmony_createApplication()
{
	harmony_context_t *ctx = harmony_createContext();

	int result = harmony_initialize(ctx, 640, 480, "Harmony", 1);

	Sleep(2000);

	harmony_destroyContext(ctx);
	harmony_terminate();

	return 0;
}

