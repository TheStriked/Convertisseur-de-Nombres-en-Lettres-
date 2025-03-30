Voici ton texte formaté pour être directement copié-collé dans un fichier `README.md` :  

```md
# **Convertisseur de Nombres en Lettres (Français)**  

**Un programme en C qui transforme les nombres en leur écriture littérale française.**  

## **📝 Description**  
Ce programme convertit un nombre (entier ou décimal) saisi par l’utilisateur en son équivalent en lettres, conformément aux règles orthographiques françaises. Par exemple :  
- **123** → *"cent vingt-trois"*  
- **45,67** → *"quarante-cinq virgule soixante-sept"*  

### **Fonctionnalités :**  
✅ **Gestion des nombres positifs et négatifs**  
✅ **Prise en charge des nombres décimaux (séparateur `.`)**  
✅ **Conversion précise selon les règles françaises (70 = "soixante-dix", 80 = "quatre-vingts")**  
✅ **Validation de l’entrée utilisateur**  

---

## **📋 Fonctionnement**  
1. **Saisie du nombre**  
   - L’utilisateur entre un nombre (ex. `123.45`).  
   - Le programme vérifie si l’entrée est valide.  

2. **Séparation partie entière / décimale**  
   - Le nombre est divisé en deux parties :  
     - **Partie entière** (ex. `123` → *"cent vingt-trois"*)  
     - **Partie décimale** (ex. `45` → *"quarante-cinq"*)  

3. **Conversion en lettres**  
   - Utilisation de tableaux prédéfinis pour les unités, dizaines et centaines.  
   - Respect des particularités françaises (11-16, 70-99).  

4. **Affichage du résultat**  
   - Exemple : `123.45` → *"cent vingt-trois virgule quarante-cinq"*  

---

## **🚀 Utilisation**  
1. **Compiler le programme :**  
   ```sh
   gcc nombre_en_lettres.c -o nombre_en_lettres
   ```
2. **Exécuter :**  
   ```sh
   ./nombre_en_lettres
   ```
3. **Saisir un nombre :**  
   ```
   Donner un nombre : 123.45
   ```
4. **Résultat :**  
   ```
   cent vingt-trois virgule quarante-cinq
   ```

---

## **📌 Exemples de Sortie**  
| Entrée       | Sortie en Lettres                              |
|--------------|------------------------------------------------|
| `42`         | *quarante-deux*                                |
| `-123.45`    | *moins cent vingt-trois virgule quarante-cinq* |
| `1000000`    | *un million*                                   |

---

## **⚙️ Améliorations Possibles**  
- Prise en charge des **nombres supérieurs au milliard**.  
- Gestion des **variantes régionales** (Belgique, Suisse).  
- Interface utilisateur améliorée.  

---

### **🎯 Résumé**  
Un outil pratique pour convertir des nombres en lettres, utile pour :  
- Les factures et documents financiers.  
- Les applications éducatives.  
- La localisation de logiciels.  

