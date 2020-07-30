#include <stdio.h>
#include <windows.h>

#include "harmony.h"

int harmony_createApplication()
{
	harmony_context_t *ctx = harmony_createContext();

	int result = harmony_initialize(ctx, 640, 480, "Harmony", 1);

	Sleep(2000);

	harmony_world_t *world = harmony_createWorld();
	harmony_node_t *node = harmony_createNode(world->baseNode);
	// harmony_node_t *subnode = harmony_createNode(node);

	Sleep(1000);

	harmony_destroyContext(ctx);
	harmony_terminate();

	return 0;
}

