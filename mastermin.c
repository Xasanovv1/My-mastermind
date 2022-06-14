#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int isInside(char* str, char c){
    if(str == NULL) return 0;
    for(int i=0; i < strlen(str); i++) {
        if(str[i] == c) return 1;
    }
    return 0;
    // random sonlarda  br hil son qaytarmaslig uchun;
}

char* randCode() {
    srand(time(0));
    char* res = malloc(4);
    int inx = 0;

    while(strlen(res) < 4) {
        char c = rand() % 8 + '0';
        if(isInside(res, c)==0)
         res[inx++] = c ;
    }
    return res;
    // random sonlarni chqaradi
}

int wellPlaced(char* str1, char* str2) {
    int res = 0;
    for(int i=0; i< 4; i++) {
        if(str1[i] == str2[i])
            res++;    
    }
    return res;
    //togri joylashtrilgan qisimlarni sanaydi;
}

int missPlaced(char*str1, char*str2) {
    int res = 0;
    for(int i=0; i < 4; i++) {
        if(isInside(str1, str2[i]) && str1[i]!=str2[i])
            res++;
    }
    return res;
    //randomda kelgan sonlar bor lekin notori joylashtrilganligini hisoblaydi;
}

int wrong_input(char* s) {
    if(strlen(s) != 4){
        return 1;
    }
    for(int i =0; i<strlen(s); i++){
        if(s[i] < '0' || s[i] > '7'){
            return 1;
        }
    }
    return 0;
    // agarda notogri harflar yoki sonlar oshib ketsa notogri kritilganini aytadi;
}



int main(int ac, char** av) {

        char *master = malloc(4), *user = malloc(4);
        int qadam, round = 0;

        master = randCode();

        qadam = 10;

        while(round <= qadam) {
            printf("---\n Round: %d\n > ", round);
            scanf("%s", user);
            if(wrong_input(user)){
                printf("wrong input\n");
                continue;
            }
            int wp = wellPlaced(master, user);
            int mp = missPlaced(master, user);

            if(wp == 4){
                printf("Congratz! You did it!\n");
                break;
            } else {
                printf("Well placed pieces: %d\n", wp);
                printf("Misplaced pieces: %d\n", mp);
            }
            round++;
        }
} 