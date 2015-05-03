#include "libintent.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>

#define INTENT_DIRECTORY ".intent/handler"

int _create_intent_directory()
{
    // First, find the user's home directory
    struct passwd* pw = getpwuid(getuid());
    const char* homedir = pw->pw_dir;

    // Now, concatenate strings to find the intent directory
    char intentDirBuf[128];
    if (strlcpy(intentDirBuf, homedir, sizeof(intentDirBuf)) >= sizeof(intentDirBuf)) {
        goto toolong;
    }
    if (strlcat(intentDirBuf, INTENT_DIRECTORY, sizeof(intentDirBuf)) >= sizeof(intentDirBuf)) {
        goto toolong;
    }

    // Figure out whether the intent directory exists
    struct stat s = {0};
    int err;

    if ((err = stat(INTENT_DIRECTORY, &s))) {
        // Existence problem?
        if (err == ENOENT) {
            // Make intent directory with permissions 0700
            if (err = mkdir(INTENT_DIRECTORY, S_IRWXU)) {
                return err;
            }
        } else {
            // If not, just return the error
            return err;
        }
    } 

    // Now, the intent directory exists
    return 0;

toolong:
    // TODO please figure out a better way of dealing with this
    return EPERM;
}

int intent_register(const char* protocol, IntentHandler handler)
{
    int err;
    if ((err = _create_intent_directory())) {
        return err;
    }

    // Check for a file that is named after the protocol

    // TODO complete this later
    return 0;
}
