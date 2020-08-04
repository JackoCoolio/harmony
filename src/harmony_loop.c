
#include <stdio.h>

#include "harmony_loop.h"
#include "harmony_linked_list.h"
#include "harmony_timer.h"

void updateNode(harmony_node_t *node, long long delta)
{
    harmony_ll_t *head = node->children;
    while (1)
    {
        if (!head->data)
            break;
        
        updateNode(head->data, delta);

        if (!head->next)
            break;
        
        head = head->next;
    }

    // ---Actually update the node---
    printf("Updating node %p\n", node);
    // ------------------------------
}

void harmony_doTick(harmony_world_t *world)
{

    // Get current time
    uint64_t now = harmony_getNanoseconds();

    // Calculate time since last Tick
    uint64_t delta = now - world->lastTick;

    // Set last Tick to be right now
    world->lastTick = now;

	harmony_node_t *baseNode = world->baseNode;
    updateNode(baseNode, delta);
}

