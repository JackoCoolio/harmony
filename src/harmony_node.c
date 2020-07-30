
#include <malloc.h>
#include <stddef.h>

#include "harmony_node.h"
#include "harmony_linked_list.h"

harmony_world_t *harmony_createWorld()
{
	harmony_world_t *world = malloc(sizeof(harmony_world_t));
	world->baseNode = harmony_createNode(NULL);
	return world;
}

harmony_node_t *harmony_createNode(harmony_node_t *parent)
{
	harmony_node_t *node = malloc(sizeof(harmony_node_t));
	node->parent = parent;
	node->children = malloc(sizeof(harmony_ll_t));
	// harmony_ll_append(parent->children, node);
	return node;
}

