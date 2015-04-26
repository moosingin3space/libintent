// Prevents double-definitions
#pragma once

#include "stringptr.h"
#include <string.h>
#include <memory.h>

// Defines a tuple for storing data
typedef struct {
    int param_id;
    stringptr_t buffer;
} tuple_t;

// Defines an intent
typedef struct {
    stringptr_t url;

    int num_params;
    tuple_t* params;
} intent_t;

// Defines a type for function pointers that respond to intents
typedef void (*IntentHandler)(const intent_t intent);

// Register an intent from a protocol
int intent_register(const stringptr_t protocol, IntentHandler handler);

// De-register an intent from a protocol
int intent_deregister(const stringptr_t protocol);
