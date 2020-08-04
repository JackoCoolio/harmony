#ifdef __cplusplus
extern "C"
{
#endif

// Long list of includes.
#include "harmony_context.h"
#include "harmony_node.h"
#include "harmony_linked_list.h"
#include "harmony_loop.h"

// Entry point
#include "harmony_entry.h"
// Entry point

#ifndef HARMONY_DISABLE_MAIN
#define main harmony_createApplication
#endif

#ifdef __cplusplus
}
#endif
