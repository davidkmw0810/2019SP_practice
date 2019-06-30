#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

//핸들러 함수 구현

int main(void) {
    void (*hand)(int);

    //핸들러 세팅

    //handler 설정이 제대로 되지 않았을 경우 에러 리턴
    if (hand == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    //pause 함수로인터럽트가 올때까지  대기

    return 0;
}
