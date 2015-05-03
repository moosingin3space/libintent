// Prevents double-definitions
#pragma once

#include <string.h>
#include <memory.h>

// TODO investigate turning the communication objects into
// Nanopb-compatible protocol buffers.

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

// Defines an application
typedef struct {
    char* short_name;
    char* user_name;
    char* version_string;
} application_t;

// Define a type for function pointers that validate intents
typedef int (*IntentValidator) (const intent_t intent);

// Define a type for function pointers that respond to intents
typedef void (*IntentHandler) (const intent_t intent);

// Register an intent at a protocol
int intent_register(const char* protocol, 
                    IntentValidator validator, 
                    IntentHandler handler);

// De-register an intent from a protocol
int intent_deregister(const char* protocol);

// List the intent handlers that can handle the given intent
int intent_list(const intent_t intent, 
                application_t* apps);

// Submits an intent to a specific application
int intent_submit(const intent_t intent, 
                  const application_t app,
                  IntentHandler response_handler);
