#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <string.h>

#define INTENT_DIRECTORY ".intent/handler"

int create_intent_directory();

// Intent manager process stuff

int fork_intent_manager_process(pid_t* pid,
                                int apipe[2]);

// TODO intent manager functions

int join_intent_manager_process(pid_t* pid, 
                                int apipe[2]);
