// Prevents double-definitions
#pragma once

#include <czmq.h>
#include "stringptr.h"
#include <string.h>
#include <memory.h>

typedef struct {
    int param_id;

    stringptr_t buffer;
} tuple_t;

typedef struct {
    stringptr_t url;

    int num_params;
    tuple_t* params;
} intent_t;


