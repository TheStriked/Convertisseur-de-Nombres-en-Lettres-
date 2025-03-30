#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* nombre[] = {"","un","deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf"};
char* dizaine_rare[] = {"", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept" , "dix-huit", "dix-neuf"};
char* dizaine[] = {"", "dix", "vingt", "trente", "quarante", "cinquante", "soixante", "soixante-dix", "quatres-vingt", "quatres-vingt-dix"};
char* centaine[] = {"", "cent", "mille", "million", "milliard", "billion", "billard"};

char* saisir_chaine(int* s){
    unsigned int caractere;
    char *NUMb= NULL;
    int i,j;
printf("Donner un nombre  : ");

    while((caractere = getchar()) != '\n'){
        NUMb = (char*)realloc(NUMb, (((*s)+1)*sizeof(char)));
        NUMb[(*s)++] = caractere;
    }

    NUMb = (char*)realloc(NUMb, (((*s)+1)*sizeof(char)));
    NUMb[*s] = '\0';

    return NUMb;
}

//MARK: REEL VALIDE
bool reele_valid(char* NUMb) {
    int i = 0, virCompt = 0, taille = strlen(NUMb);
    
    if(NUMb[0] == '-' || NUMb[0] == '+') 
    {
        i++;
    }
    
    while ((NUMb[i] >= '0' && NUMb[i] <= '9') || NUMb[i] == '.' && NUMb[i] != '\0')
    {
        i++;
    }

    if(i == taille) {
        return true;
    }
    else {
        return false;
    }


}

void deviser_chaine(char* NUMb, char part_entier[20], char part_decimal[20]){
    char *tab;
    int i,j,tailleNUMb=strlen(NUMb);

    // DEVISEER
    tab = strtok(NUMb, ".");
    if(tab != NULL){
        strcpy(part_entier, tab);

        tab = strtok(NULL, ".");
        if(tab != NULL)
            strcpy(part_decimal, tab);
        else
            strcpy(part_decimal,"");
    }
   
    int langeur_entier= strlen(part_entier);
    int r= langeur_entier % 3;
    
    if(r == 0)
        return;
   langeur_entier += 3-r;
    
    for(j=0; j<3-r; j++){
        for(i=langeur_entier; i >= 0; i--){
            part_entier[i+1] = part_entier[i];
        }
        part_entier[j] = '0';
    }

    int langeur_decimal = strlen(part_decimal);
    r = langeur_decimal % 3;
    
    if(r == 0)
        return;
    langeur_decimal += 3-r;
   
    for(j=0; j<3-r; j++){
        for(i=langeur_decimal ; i >= 0 ; i--){
            part_decimal[i+1] = part_decimal[i];
        }
        part_decimal[j] = '0';
    }
}

int cent_deg(int n){
    if(n <= 3)
        return 0;
    
    else if(n <= 6)
        return 2;
    
    else if(n <= 9)
        return 3;
    
    else if(n <= 12)
        return 4;
    
    else if(n <= 15)
        return 5;
    
    else if(n <= 18)
        return 6;
}

void converte_unite(char* s, int n){
    int i,index,k;
    k = cent_deg(n);
    int j ;
    for(i=0; i<n; i+=3){
        j = 0;
        index = s[i+j] - '0';
        if(s[i+j] != '1') printf("%s ", nombre[index]);
        if(s[i+j] != '0') printf("%s ",centaine[1]);
        j++;
      	if(s[i+j] == '1'){
            if(s[i+j+1] == '0'){
                printf("dix ");}
            else{
                index = s[i+j+1] - '0';
                printf("%s ",dizaine_rare[index]);
            }
        j += 2;
        }

        else if(s[i+j] == '7'){
            if(s[i+j+1] == '0'){
                printf("soixante-dix ");
            }
            else{
                index = s[i+j+1] - '0';
                printf("soixante %s ",dizaine_rare[index]);
            }
        j += 2;
        }

        else if(s[i+j] == '9'){
            if(s[i+j+1] == '0'){
                printf("quatres-vingt ");
            }
            else{
                index = s[i+j+1] - '0';
                printf("quatres-vingt %s ",dizaine_rare[index]);
            }
        j += 2;
        }
       
        else if (j <=2){
            index = s[i+j] - '0';
            printf("%s ", dizaine[index]);
            j++;
        }
        
        if(j <= 2){
            index = s[i+j] - '0';
            printf("%s ", nombre[index]);
        }
        
        printf("%s ", centaine[k]);
        if(k == 2)
            k -= 2;
        else
            k--;
    }
}


//MARK: MAIN START
int main() {

    int longeur_caractere=0,langeur_entier,langeur_decimal;
    char* nbr_lett;
    char part_entier[20];
	char part_decimal[20];
    bool check;

    nbr_lett = saisir_chaine(&longeur_caractere);
    check = reele_valid(nbr_lett);
    if(check == false) {
        printf("ERROR!!\n");
    }
    else {
        
        deviser_chaine(nbr_lett, part_entier, part_decimal);

        langeur_entier = strlen(part_entier);
        converte_unite(part_entier, langeur_entier);
        langeur_decimal = strlen(part_decimal);
    
        if(langeur_decimal != 0)  printf("virgule ");

        langeur_decimal = strlen(part_decimal);
        converte_unite(part_decimal, langeur_decimal);
    }

    

    return 0;
    
}



//MARK: END