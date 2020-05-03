#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dlfcn.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <string.h>
#include <termios.h>
#include <pthread.h>
#include <sys/epoll.h>
#include <android/log.h>
#include <sys/mman.h>
#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/ptrace.h>

#define LOG_TAG "bridge"
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)

__attribute__((constructor)) static void setup_hook_libc() {
    LOGD("setup_hook_libc, by _init, may be blocked!!!");

}


int hook_entry(char* cache){
    LOGD("Inject success:%s\n", cache);

    return 0;
} 
