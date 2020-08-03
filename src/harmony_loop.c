
#include <stdio.h>

#include "harmony_loop.h"
#include "harmony_linked_list.h"

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

    // TODO: FInish this.

    long long delta;

    #ifdef HARMONY_BUILD_WINDOWS
    LARGE_INTEGER curTime;
    QueryPerformanceCounter(&curTime);
    delta = curTime.QuadPart - world->lastTick;
    world->lastTick = curTime.QuadPart;
    #else
    #error "Harmony is not compatible with non-Windows operating systems!"
    #endif

	harmony_node_t *baseNode = world->baseNode;
    updateNode(baseNode, delta);
}

