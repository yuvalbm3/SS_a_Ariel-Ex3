//
// Created by yuval on 11/12/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TXT 1024
#define WORD 30
#include "ex3.h"

int main(){
    char *word = (char*)malloc(sizeof(char) * WORD);
    char *txt = (char*)malloc(sizeof(char) * TXT);

    char str;
    if(word == NULL || txt == NULL /*|| str == NULL*/){
        printf("error \n");
    }
    scanf("%c", &str);
    int i=0, j=0;
    while(str != ' ' && str != '\n' && str != '\t'){
        word[i] = str;
        i=i+sizeof(char);
        scanf("%c", &str);
    }
    while(str != '~'){
        txt[j] = str;
        j=j+sizeof(char);
        scanf("%c", &str);
    }
    gematria(word, i, txt, j);
    atbash(word, i, txt, j);
    anagram(word, i, txt, j);
    free(word);
    free(txt);


}
//    char *str = malloc(sizeof(char) * (TXT + WORD));
