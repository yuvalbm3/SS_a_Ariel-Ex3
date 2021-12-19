//
// Created by yuval on 11/12/2021.
//
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TXT 1024


void gematria(char *word, int wlen, char *txt, int tlen){
    char *res = (char*)malloc(sizeof(char) * TXT);
    int k=0; //point to res
    int valw=0; // word value
    for (int i = 0; i < wlen; ++i) {
        if(isalpha(word[i])){
            valw+=((int)(toupper(word[i]))-64);
        }
    }
    int valt=0; // value of txt between j to i
    int i=0, j=0; // j point to began of txt, i point to end of txt
    int stword=1;
    int first=0; //flag if this is the first char of the txt
    int flag=1;
    while(flag){
        if( j==tlen || i>tlen){
            flag=0;
        }
        else if(valt < valw){
            if(!isalpha(txt[0]) && first==0){
                i++;
                j++;
                first++;
            }
            else if(!isalpha(txt[j]) && j<i){
                j++;
            }
            else if(isalpha(txt[i])){
                valt+=(int)((int)(toupper(txt[i]))-64);
                if(i<tlen){
                    i++;
                }
            }
            else{
                i++;
            }
        }
        else if(valt > valw){
            if(j<i){
                j++;
            }
            i=j;
            valt=0;
        }
        else if(valt == valw){
            int t=0;
            int tmp=0;
            if(stword){
                tmp++;
                for (t=t+j; t <i ; t++) {
                    res[k] = txt[t];
                    k++;
                }
                stword=0;
            }
            if(!stword && tmp==0){
                res[k] = '~';
                k++;
                for (t=t+j; t <i ; t++) {
                    res[k] = txt[t];
                    k++;
                }
            }
            j++;
            i=j;
            valt=0;
        }
    }
    printf("Gematria Sequences: ");
    printf("%s\n", res);
    free(res);
}

char atbash_help(char a){
    char b;
    if(isalpha(a)){
        if(islower(a)){
            b=26-((int)a-96);
            b=b+97;
            return b;
        }
        else if(isupper(a)){
            b=26-((int)a-64);
            b=b+65;
            return b;
        }
    }
    return a;
}

void atbash(char *word, int wlen, char *txt, int tlen){
    char *res1 = (char*) calloc(TXT, sizeof(char));
    int k=0;    // count the chars in order
    int r=0;    // count the chars of revers in order
    int flag=1; //flag for getting out of the while loop
    int first=0;
    int p=0;  //point to res
    int isrev = 0;  // boolean say if the word is reverse ir not
    int i=0;    //counter
    int j=0;    //counter for reverse
    while(flag){
        if(i>tlen-wlen || j>tlen-wlen){
            flag=0;
        }
        else if(k==wlen || r==wlen){
            if(isrev==1){
                i=j-wlen;
            }
            else if(isrev==0){
                i=i-wlen;
            }
            if(first==0){
                first=1;
                for (int l = 0; l < wlen; l++, p++, i++) {
                    res1[p] = txt[i];
                }
            }
            else if(first==1){
                res1[p] = '~';
                p++;
                for (int l = 0; l < wlen; l++, p++, i++) {
                    res1[p] = txt[i];
                }
            }
            isrev=0;
            k=0;
            r=0;
        }
        else if(isalpha(txt[i])){
            if(word[k] == atbash_help(txt[i])){
                i++;
                k++;
            }
            else if(word[wlen-r-1] == atbash_help(txt[j])){
                j++;
                r++;
                if(r==wlen){
                    isrev=1;
                }
            }
            else{
                i++;
                j++;
                k=0;
                r=0;
            }
        }
        else{
            i++;
            j++;
        }
    }
    printf("Atbash Sequences: ");
    printf("%s\n", res1);
    free(res1);

}

void anagram(char *word, int wlen, char *txt, int tlen){
    char *res2 = (char*)calloc(TXT, sizeof(char));
    int sum=0;
    for (int i = 0; i < wlen; ++i) {
        sum+=word[i];
    }
    int fl=0;
    int t=0;
    int cnt=0;
    int space=0;
    int first=1;
    int flag=1;
    while(flag){
        if(fl>tlen){
            flag=0;
        }
        else if(cnt==wlen){
            int tmp=sum;
            if(t == 15){
                printf("as");
            }
            for (int i = cnt+space; i > 0 ; --i) {
                if(isalpha(txt[fl-i])){
                    tmp-=txt[fl-i];
                }
            }
            if(tmp==0){
                fl=fl-(cnt+space);
                if(first){
                    for (int i = 0; i < cnt+space; i++, t++) {
                        res2[t] = txt[fl];
                        fl++;
                    }
                    first=0;
                }
                else{
                    res2[t]='~';
                    t++;
                    for (int i = 0; i < cnt+space; i++, t++) {
                        res2[t] = txt[fl];
                        fl++;
                    }
                }
            }
            cnt=0;
            space=0;
            fl = fl-wlen+1;
        }
        else if(isalpha(txt[fl])) {
            //printf('%c\n', txt[fl]);
            int tmp = cnt;
            for (int i = 0; i < wlen ; ++i) {
                if(txt[fl] == word[i]){
                    fl++;
                    cnt++;
                    break;
                }
            }
            if(cnt!=0 && tmp==cnt){
                cnt=0;
            }
            if(cnt==0){
                fl++;
            }
        }
        else if(txt[fl]==' ' && cnt>0){
            space++;
            fl++;
        }
        else{
            space=0;
            cnt=0;
            fl++;
        }

    }
    printf("Anagram Sequences: ");
    printf("%s", res2);
    free(res2);
}
