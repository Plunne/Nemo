---
author: Lena SAVY-LARIGALDIE
title: COURS - Scripting en Shell
---

# SHELL

Formateur : [COLIN Matthias](https://github.com/matthcol/scripting202302)

A venir... *(Vient du cours Python, en cours de trad vers Shell)*

> Shell est l'interprete de commande Linux.

## TABLE DES MATIERES
- [SHELL](#shell)
  - [TABLE DES MATIERES](#table-des-matieres)
- [LANCER UN SCRIPT](#lancer-un-script)
- [ENTREE/SORTIE](#entreesortie)
  - [Affichage (echo)](#affichage-echo)
    - [Affichage simple](#affichage-simple)
    - [Characteres a echappement](#characteres-a-echappement)
    - [Concatenation](#concatenation)
- [TRAITER DES ARGUMENTS](#traiter-des-arguments)
- [TRAITER DES ARGUMENTS](#traiter-des-arguments-1)
- [TABLEAUX (LISTES)](#tableaux-listes)
  - [Acces aux elements](#acces-aux-elements)
- [CLI EN FIN DE SCRIPT](#cli-en-fin-de-script)
- [BOOLEEN](#booleen)
- [NONE](#none)
- [STRUCTURES CONDITIONNELLES](#structures-conditionnelles)
  - [IF, ELSE, ELIF](#if-else-elif)
    - [IF](#if)
    - [ELSE](#else)
    - [ELIF](#elif)
  - [MATCH CASE](#match-case)
    - [Valeur](#valeur)
    - [Arguments](#arguments)
- [BOUCLES CONDITIONNELLES](#boucles-conditionnelles)
  - [FOR EACH](#for-each)
  - [WHILE](#while)
- [OPERATEURS](#operateurs)
  - [Arithmetiques](#arithmetiques)
  - [Comparaison](#comparaison)
- [BREAK \& CONTINUE](#break--continue)
  - [Break](#break)
  - [Continue](#continue)
- [PASS](#pass)
- [SYSTEME DE FICHIERS](#systeme-de-fichiers)
  - [Bibliotheques](#bibliotheques)
    - [Operations simples](#operations-simples)
    - [Operations complexes](#operations-complexes)
  - [Pathlib](#pathlib)
    - [Importation](#importation)
    - [Objet Path](#objet-path)
    - [Creation de Dossiers](#creation-de-dossiers)
  - [ShUtil](#shutil)
    - [Importation](#importation-1)
    - [Copie de dossiers](#copie-de-dossiers)
    - [Copie de fichiers](#copie-de-fichiers)

# LANCER UN SCRIPT

```sh
./script.sh
```

**Avec arguments :**

```sh
./script.sh arg1 arg2 arg3
```
# ENTREE/SORTIE

## Affichage (echo)

Afficher du texte et/ou des valeurs.


### Affichage simple

```sh
echo "texte"
```

**Resultat :**

```
texte
```

### Characteres a echappement

Pouvoir inserer des echappements antislash en milieu de chaine.

```sh
echo -e "texte1\ntexte2"
```

**Resultat :**

```
texte1
texte2
```

### Concatenation

Concatener des chaines/valeurs.

```sh
echo "valeur :"1234
```

**Resultat :**

```
valeur :1234
```

> **Note :** *Un espace dans la ligne sera considere comme un espace.*

# TRAITER DES ARGUMENTS

Importer un script `<chemin>/script.sh`

```sh
source <chemin>/script.sh
```

# TRAITER DES ARGUMENTS

Manipuler les arguments.

Code | Description
:-:|:-
`$@` | Tous les arguments
`$#` | Le nombre d'arguments
`$x` | Arguments a l'index `x`
`$_` | Le dernier argument


# TABLEAUX (LISTES)

Les listes en python sont l'equivalent des tableaux en C, en revanche, les listes ont l'avantage d'etre extensibles.

## Acces aux elements

| Syntaxe      | Valeur de retour                         |
|:------------:|:-----------------------------------------|
| `tab[0]`     | Premier element                          |
| `tab[n]`     | Element n+1                              |
| `tab[-1]`    | Dernier element                          |
| `tab[-n]`    | Element n a partir de la fin             |
| `tab[:]`     | Liste tous les elements                  |
| `tab[n1:n2]` | Liste les elements de l'element n1 a n2  |

# CLI EN FIN DE SCRIPT

Entrer dans l'interprete de commande a la fin de l'execution de notre print.

```sh
python -i script.py
```

# BOOLEEN

Le booleen est un type a deux etats vrai/faux.

**Syntaxe :**

| Syntaxe | Valeur |
|:-------:|:------:|
| `True`  | 1      |
| `False` | 0      |

# NONE

Le type `None` est une constante attribuee pour une variable a valeur nulle.

# STRUCTURES CONDITIONNELLES

## IF, ELSE, ELIF

### IF

- **SI** expression **ALORS** instructions

```python
if expression:
    # Instructions
```

### ELSE

- **SI** expression **ALORS** instructions
- **SINON** instructions

```python
if expression:
    # Instructions
else:
    # Instructions
```

### ELIF

- **SI** expression **ALORS** instructions
- **SINON SI** expression **ALORS** instructions
- **SINON** instructions

```python
if expression:
    # Instructions
elif:
    # Instructions
else:
    # Instructions
```

## MATCH CASE

### Valeur

Meme utilisation que le `switch` en C.

```python
match variable:
    case valeur:
        # Instructions
    case _:
        # Instructions par defaut
```
> Il est egalement possible de mettre des expressions dans les cases.

### Arguments

Match permet aussi de recuperer les arguments pour les affecter dans des variables.

```python
match sys.argv[1:]:
    # Affecte l'argument 1 a une variable arg1,
    # Affecte l'argument 2 a une variable arg2,
    # etc...
    case [arg1, arg2, ...]:
        # Instructions
    case _:
        # Instructions par defaut
```

# BOUCLES CONDITIONNELLES

## FOR EACH

Boucle permettant de parcourir tous les elements d'une liste.

- **POUR** Chaque `element`
- **DANS** la variable parcourue `liste`
- **FAIRE** les instructions

```python
for element in liste:
    # Instructions
```

## WHILE

Boucle d'instructions qui se repete **TANT QUE** sa condition est vraie.

- **TANT QUE** l'expression `expression` est vraie
- **FAIRE** les instructions

```python
while expression:
    # Instructions
```

# OPERATEURS

## Arithmetiques

| Operateur | Nom               | Syntaxe  | Valeur de retour                     |
|:---------:|:-----------------:|:--------:|:-------------------------------------|
| `+`       | Addition          | `a + b`  | Somme de `a` et `b`                  |
| `-`       | Soustraction      | `a - b`  | Difference de `a` par `b`            |
| `*`       | Multiplication    | `a * b`  | Produit de `a` et `b`                |
| `/`       | Division          | `a / b`  | Quotient de `a` par `b`              |
| `//`      | Division Entiere  | `a // b` | Quotient entier de `a` par `b`       |
| `%`       | Modulo            | `a % b`  | Reste de la division de `a` par `b`  |
| `**`      | Puissance         | `a ** b` | `a` puissance `b`                    |

## Comparaison

| Operateur  | Nom                 |
|:----------:|---------------------|
| `==`       | Egalite             |
| `!=`       | Difference          |
| `is`       | Meme adresse        |
| `is not`   | Adresse differente  |
| `>`        | Superieur           |
| `<`        | Inferieur           |
| `>=`       | Superieur ou egal   |
| `<=`       | Inferieur ou egal   |
| `in`       | Est dedans?         |
| `not in`   | N'est pas dedans?   |
| `and`      | ET Logique          |
| `or`       | OU Logique          |
| `not`      | NON Logique         |

# BREAK & CONTINUE

## Break

Sortir d'une boucle en cours.

```python
break
```

## Continue

Ne rien faire et continuer la boucle

```python
continue
```

# PASS

Instruction vide.

En python, il est necessaire de marquer le passage dans un bloc avec `pass` si on ne veut rien faire.

```python
pass
```

# SYSTEME DE FICHIERS

## Bibliotheques

### Operations simples

Navigation, Listing, Existence, Creation, Deplacement/Rename, Suppression...

- `pathlib` : API Objet (`Path`)
- `os.path` : API a chaine de caracteres

### Operations complexes

Copie, Copie recursive

- `shutil` : API contenant des fonctions

## Pathlib

### Importation

Importer la classe `Path`.

```python
from pathlib import Path
```

### Objet Path

Creation d'une instance de `Path` qui permettra de manipuler un chemin de fichier.

```python
Mon_Chemin = Path("Chemin/Du/Fichier")
```

### Creation de Dossiers

Creer le dossier `Mon_Chemin` a l'aide de la commande `mkdir` .

```python
if not Mon_Chemin.exists():
    Mon_Chemin.mkdir(parents=True, exists_ok=True)
elif not Mon_Chemin.is_dir():
    print(f"Error: {Mon_Chemin} n'est pas un répertoire")
```

## ShUtil

### Importation

Importer la bibliotheque de fonctions `shutil` .

```python
import shutil
```

### Copie de dossiers

Copie le contenu d'un repertoire et celui de ses sous-dossiers.

```python
shutil.copytree(dossier_a_copier, dossier_de_destination, dirs_exist_ok=True)
```

> **ATTENTION!**
>
> Ne copie que le contenu du dossier, pas le dossier lui meme.

### Copie de fichiers

Copie un fichier vers un repertoire.

```python
shutil.copy(fichier_a_copier, dossier_de_destination)
```