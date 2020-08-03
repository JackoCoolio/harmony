#ifndef HARMONY_LOOP_H
#define HARMONY_LOOP_H

#ifdef HARMONY_BUILD_WINDOWS
#include "windows.h"
#else
#error "Harmony is not compatible with non-Windows operating systems!"
#endif

#include "harmony_node.h"

void harmony_doTick(harmony_world_t *world);

#endif

