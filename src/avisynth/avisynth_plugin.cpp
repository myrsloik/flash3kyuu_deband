#define USE_AVISYNTH_INTERFACE 6
#define CONCAT2(a, b) a##b
#define CONCAT(a, b) CONCAT2(a, b)

#include <avisynth.h>

#include "../compiler_compat.h"
#include "filter_impl.hpp"

const AVS_Linkage *AVS_linkage = nullptr;

F3KDB_API(const char*) AvisynthPluginInit3(IScriptEnvironment* env, const AVS_Linkage* const vectors) {
    AVS_linkage = vectors;
    env->AddFunction("flash3kyuu_deband", 
        F3KDB_AVS_PARAMS, 
        Create_flash3kyuu_deband, 
        NULL);
    env->AddFunction("f3kdb", 
        F3KDB_AVS_PARAMS, 
        Create_flash3kyuu_deband, 
        NULL);

    return "f3kdb";
}