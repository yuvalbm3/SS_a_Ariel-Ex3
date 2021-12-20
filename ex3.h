//
// Created by yuval on 11/12/2021.
//

#ifndef UNTITLED3_EX3_H
#define UNTITLED3_EX3_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define TXT 1024
#define WORD 30

char gematria(char *word, int wlen, char *txt, int tlen);
char atbash_help(char a);
char atbash(char *word, int wlen, char *txt, int tlen);
char anagram(char *word, int wlen, char *txt, int tlen);
int anagram_help(char *word, int wlen, char this);

#endif //UNTITLED3_EX3_H
