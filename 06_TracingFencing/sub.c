#define _GNU_SOURCE
#include <string.h>
#include <dlfcn.h>

typedef int (*true_unlink)(const char * filename);

int unlink(const char * filename){
    if (strstr(filename, "PROTECT") != NULL)
        return 0;
    true_unlink true_call;
    true_call = (true_unlink)dlsym(RTLD_NEXT, "unlink");
    return true_call(filename);
}
