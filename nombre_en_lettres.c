#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* nombre[] = {"","un","deux","trois","quatre","cinq","six","sept","huit","neuf"};
char* dizaine_rare[] = {"","onze","douze","treize","quatorze","quinze","seize","dix-sept","dix-huit","dix-neuf"};
char* dizaine[] = {"","dix","vingt","trente","quarante","cinquante","soixante","soixante-dix","quatre-vingt","quatre-vingt-dix"};
char* centaine[] = {"","cent","mille","million","milliard","billion","billard"};

char* saisir_chaine(int* s){
    unsigned int caractere;
    char *NUMb = NULL;
    *s = 0;
    printf("Donner un nombre : ");

    while((caractere = getchar()) != '\n'){
        NUMb = realloc(NUMb, (*s+1)*sizeof(char));
        NUMb[(*s)++] = caractere;
    }

    NUMb = realloc(NUMb, (*s+1)*sizeof(char));
    NUMb[*s] = '\0';
    return NUMb;
}

bool reele_valid(char* NUMb){
    int i = 0, virCompt = 0, taille = strlen(NUMb);
    if(taille == 0) return false;
    
    if(NUMb[0] == '-' || NUMb[0] == '+') {
        i++;
        if(taille == 1) return false;
    }
    
    while(i < taille){
        if(NUMb[i] == '.'){
            virCompt++;
            if(virCompt > 1) return false;
        }
        else if(NUMb[i] < '0' || NUMb[i] > '9') return false;
        i++;
    }
    return true;
}

void deviser_chaine(char* NUMb, char part_entier[20], char part_decimal[20]){
    char *tab;
    strcpy(part_entier, NUMb);
    part_decimal[0] = '\0';

    tab = strtok(NUMb, ".");
    if(tab != NULL){
        strcpy(part_entier, tab);
        tab = strtok(NULL, ".");
        if(tab != NULL) strcpy(part_decimal, tab);
    }
}

void afficher_nombre(char* s, bool is_negatif){
    int n = strlen(s);
    if(n == 0) return;
    
    if(is_negatif) printf("moins ");
    
    if(n == 1){
        printf("%s ", nombre[s[0]-'0']);
        return;
    }
    
    if(n == 2){
        if(s[0] == '1'){
            if(s[1] == '0') printf("dix ");
            else printf("%s ", dizaine_rare[s[1]-'0']);
        }
        else if(s[0] == '7'){
            if(s[1] == '0') printf("soixante-dix ");
            else printf("soixante %s ", dizaine_rare[s[1]-'0']);
        }
        else if(s[0] == '9'){
            if(s[1] == '0') printf("quatre-vingt-dix ");
            else printf("quatre-vingt %s ", dizaine_rare[s[1]-'0']);
        }
        else{
            if(s[0] != '0') printf("%s ", dizaine[s[0]-'0']);
            if(s[1] != '0') printf("%s ", nombre[s[1]-'0']);
        }
        return;
    }
}

int main(){
    int taille = 0;
    char* nbr_lett = saisir_chaine(&taille);
    char part_entier[20], part_decimal[20];
    
    if(!reele_valid(nbr_lett)){
        printf("ERROR!!\n");
    }
    else{
        deviser_chaine(nbr_lett, part_entier, part_decimal);
        
        bool is_negatif = (part_entier[0] == '-');
        if(is_negatif || part_entier[0] == '+') memmove(part_entier, part_entier+1, strlen(part_entier));
        
        afficher_nombre(part_entier, is_negatif);
        
        if(strlen(part_decimal) > 0){
            printf("virgule ");
            afficher_nombre(part_decimal, false);
        }
        printf("\n");
    }
    
    free(nbr_lett);
    return 0;
}
