#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum seçmen ve adaylar
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// adayların adı,oy sayısı,elenme durumu
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Aday dizisi
candidate candidates[MAX_CANDIDATES];

// seçmen ve aday sayısı
int voter_count;
int candidate_count;

// prototipler
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // geçersiz kullanım olup olmadığını kontrol
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // aday dizisini doldurma
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // oy sorgusu
    for (int i = 0; i < voter_count; i++)
    {

        
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    while (true)
    {
        //kalan adaylara verilen oyları hesaplama
        tabulate();

        // kazanıp kazanılmadğının kontrolü
        bool won = print_winner();
        if (won)
        {
            break;
        }

        
        int min = find_min();
        bool tie = is_tie(min);

        //beraberlik olursa herkes kazanır
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // oy sayısı min olanları eleme
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// oy geçerliyse adayı kaydet
bool vote(int voter, int rank, string name)
{
    
    for(int i = 0; i<candidate_count; i++) {
        if(strcmp(candidates[i].name,name) == 0) {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

//tablo haline getir
void tabulate(void)
{
    // TODO
    for (int i = 0; i < voter_count; i++){
        for(int j = 0; j < candidate_count; j++) {
            if(candidates[preferences[i][j]].eliminated == false) {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}

// kazanan varsa kazananı yazdır
bool print_winner(void)
{
    // TODO
     for (int i = 0; i < candidate_count; i++){

            if(candidates[i].votes > voter_count/2) {
               printf("%s\n",candidates[i].name);
                return true;
            }

    }
    return false;
}

// Kalan herhangi bir adayın sahip olduğu minimum oy sayısını iade etme
int find_min(void)
{
    // TODO
    int min = voter_count;
    for (int i = 0; i < candidate_count; i++){

            if(candidates[i].votes < min && candidates[i].eliminated == false) {
               min = candidates[i].votes;
            }
    }
    return min;
}

// berbare kalma 
bool is_tie(int min)
{
    // TODO
    int eliminate = 0;
    int counter = 0;
     for (int i = 0; i < candidate_count; i++){

            if(!candidates[i].eliminated ) {
               eliminate++;
            }
            if(candidates[i].votes == min){
                counter++;
            }
    }

    if(eliminate == counter){
        return true;
    }
    return false;
}

// son aday eleme
void eliminate(int min)
{
    // TODO
     for (int i = 0; i < candidate_count; i++){

            if(candidates[i].votes == min ) {
               candidates[i].eliminated = true;
            }

    }
    return;
}