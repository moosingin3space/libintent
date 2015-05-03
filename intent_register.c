#include "libintent.h"
#include "internal.h" 

int intent_register(const char* protocol, IntentHandler handler)
{
    int err;
    if ((err = create_intent_directory())) {
        return err;
    }

    // Check for a file that is named after the protocol

    // TODO complete this later
    return 0;
}
