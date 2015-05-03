#include "internal.h"

int fork_intent_manager_process(pid_t* pid, int apipe[2])
{
    static bool process_started = false;
    static pid_t mgr_process;
    static int mgr_pipe[2];

    if (process_started) {
        *pid = mgr_process;
        return 0;
    } 

    if (pipe(mgr_pipe)) {
        // Pipe creation unsuccessful
        return EIO;
    }
    mgr_process = fork();
    if (mgr_process < (pid_t)0) {
        // Fork failed, return child process error
        return ECHILD;
    } else if (mgr_process == (pid_t)0) {
        // This is the child process
        // TODO run the intent manager
    } else {
        // This is the parent process.
        *pid = mgr_process;
        memcpy(apipe, mgr_pipe, 2*sizeof(int));
    }
    process_started = true;
    return 0;
}
