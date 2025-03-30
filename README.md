# Convertisseur de Nombres en Lettres Françaises

## Description
Un programme en C qui convertit les nombres en leur écriture littérale française exacte, avec gestion des nombres décimaux et négatifs.

## Fonctionnalités
- Conversion précise selon les règles orthographiques françaises
- Prise en charge des nombres décimaux (utilisant le point comme séparateur)
- Gestion des nombres négatifs
- Validation de l'entrée utilisateur
- Support jusqu'au milliard

## Comment utiliser

### Prérequis
- Compilateur C (gcc recommandé)
- Système d'exploitation Linux/Windows/Mac

### Installation
1. Téléchargez le fichier `nombre_en_lettres.c`
2. Ouvrez un terminal dans le dossier contenant le fichier

### Compilation
```bash
gcc nombre_en_lettres.c -o nombre_en_lettres
```

###🚀 Exécution et Exemples d'utilisation**  
```bash
./nombre_en_lettres

Donner un nombre : 123
cent vingt-trois

Donner un nombre : 45.67
quarante-cinq virgule soixante-sept

Donner un nombre : -100
moins cent
```

## **🚀 Exécution et Exemples d'utilisation**  
```bash
./nombre_en_lettres

Donner un nombre : 123
cent vingt-trois

Donner un nombre : 45.67
quarante-cinq virgule soixante-sept

Donner un nombre : -100
moins cent
```

---

## **🤝 Contribuer**  

Les contributions sont les bienvenues ! Veuillez ouvrir une issue ou une pull request pour proposer des améliorations.


---

## **⚠️ Remarques**  

- Les nombres décimaux utilisent le point (.) comme séparateur.
- Le programme gère correctement les particularités françaises (70 = "soixante-dix", 80 = "quatre-vingts", etc.).
- La validation rejette les entrées non numériques.

