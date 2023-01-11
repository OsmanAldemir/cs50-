#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "dictionary.h"

//tablodaki düğümü göterir
typedef struct node 
{
    char word[LENGHT+1];// dictionary h
    struct  node *next;   
    
};

// tablodaki kova sayısı
const unsigned int N=26;

//hash tablosu
node *hashtable[N];
int words=0;

// kelimeyi 1 sayisa hashler
unsigned int hash(const char *word){
 return tolower(word[0])-'a';
    
}

// sözlüğü belleğe yükler, bu gerçekleşirse true döner ,olmassa false döner
bool load(const char *dictionary){
    FILE *pointer1=fopen(dictionary,"r");
    if(pointer1==NULL)
    return 0;
    char dicwords[lenght+1];
    while(fscanf(pointer1,"%s",dicwords)!=EOF){
        node *n=malloc(sizeof(node));
        if(n=NULL)
        return 0;
        strcpy(n->word,dicwords);
        int x=hash(dicwords);
        if(hashtable[x]==NULL){
            n->next=NULL;
            hashtable[x]=n;
        }

          else{
            n->next = hashtable[x];
            hashtable[x]=n;
          }
          words++;
    }
    fclose(pointer1);
    return true;
} 

// sözlükteki kelime sayisini geri döndürür
//sözlük yünklenmemişse 0 döndürcel
unsigned int size(void){
    return words;
}

//kelime sözlükte varsa true yoksa false döndürcek

bool control(const char *word){
    int temp=hash(word);
    node *cursor=hashtable[temp];
    while(cursor!=NULL){
        if(strcasecmp(cursor->word,word)==0) return true;
        cursor=cursor->next;
    }
    return 0;
}

//sözlüğü bellekten temizler temizlenirse true ölmazsa false döner
bool unload(void){
    for(int i=0;i<N;i++){
        node *cursor=hashtable[i];
        node *temp=cursor;
        while(cursor !=NULL){
            cursor=cursor->next;
            free(temp);
            temp=cursor;
        }
    }
    return true;
}