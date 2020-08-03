#ifndef HARMONY_NODE_H
#define HARMONY_NODE_H

struct harmony_ll_t;

// Node
typedef struct harmony_node_t
{
	struct harmony_node_t *parent;
	struct harmony_ll_t *children;
} harmony_node_t;

// World
typedef struct
{
	harmony_node_t *baseNode;
	long long lastTick;
} harmony_world_t;

harmony_world_t *harmony_createWorld();

harmony_node_t *harmony_createNode(harmony_node_t *parent);

#endif
