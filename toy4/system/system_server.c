#include <stdio.h>
#include <sys/prctl.h>

#include <system_server.h>
#include <gui.h>
#include <input.h>
#include <web_server.h>

int system_server()
{
    printf("나 system_server 프로세스!\n");

    while (1) {
        sleep(1);
    }

    return 0;
}

int create_system_server()
{
    pid_t systemPid;
    const char *name = "system_server";

    printf("여기서 시스템 프로세스를 생성합니다.\n");

    /* fork 를 이용하세요 */
    switch (SystemPid = fork()) {
        case -1:
                printf("fork failed\n");
        case 0:
                /* change process name */
                if (prctl(PR_SET_NAME, (unsigned ling) name) < 0)
                        perror("prtcl()");
                system_server();
                break;
        default:
                break;
        }    
    return 0;
}
