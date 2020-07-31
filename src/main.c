#include <stdio.h>
#include <windows.h>

#include "harmony.h"

int harmony_createApplication()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	harmony_context_t *ctx = harmony_createContext();

	int result = harmony_initialize(ctx, 640, 480, "Harmony", 1);

	harmony_world_t *world = harmony_createWorld();

	harmony_node_t *nodes[10];
	for (int i = 0; i < 10; i++)
	{
		nodes[i] = harmony_createNode(world->baseNode);
	}

	harmony_destroyContext(ctx);
	harmony_terminate();

	return 0;
}

