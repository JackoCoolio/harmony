#ifdef __cplusplus
extern "C"
{
#endif
    
#define GLEW_STATIC
    
    // Harmony Core
#include "harmony_context.h"
    
    // Data types & general utilities
#include "harmony_vector.h"
#include "harmony_linked_list.h"
#include "harmony_timer.h"
#include "harmony_file.h"
#include "harmony_buffer.h"
#include "harmony_log.h"
    
    // Graphics
#include "harmony_shader.h"
#include "harmony_renderer.h"
#include "harmony_texture.h"
#include "harmony_batch.h"
    
    // Entry point
#include "harmony_entry.h"
    
#define main harmony_createApplication
    
#ifdef __cplusplus
}
#endif
