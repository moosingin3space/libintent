// Prevents double-definitions
#pragma once

#include <string.h>
#include <memory.h>

// Defines a tuple for storing data
typedef struct {
    int param_id;
    char* buffer;
} tuple_t;

// Defines an intent
typedef struct {
    char* url;

    int num_params;
    tuple_t* params;
} intent_t;

// Defines a type for function pointers that respond to intents
typedef void (*IntentHandler)(const intent_t intent);

// Register an intent from a protocol
int intent_register(const char* protocol, IntentHandler handler);

// De-register an intent from a protocol
int intent_deregister(const char* protocol);
