---
author: Lena SAVY-LARIGALDIE
title: FPGA/VHDL/Cours1.md
---

# VHDL (VHSIC Hardware Description Language)

Le VHDL a vu le jour en 1983 dans le cadre de l'initiative VHSIC (Very High Speed Integrated Circuit) lancee par le DoD des Etats-Unis (United-States Department of Defense) afin de developper des circuits electroniques integres a tres haute vitesse.

Sa syntaxe est inspiree du langage [Ada](https://github.com/Plunne/Nemo/tree/main/ADA).

Contrairement a la plus part des langages, le VHDL est un langage de description materiel (HDL : Hardware Description Langage). Il a pour fonction de definir le comportement et l'architecture des des Circuits Logiques Programmables (PLD : Programmable Logical Device).

> **Quelques exemples populaires de PLD programmables en VHDL :**
> 
> - **ASIC** : Application Specific Integrated Circuit
> - **CPLD** : Complex Programmable Logical Device
> - **FPGA** : Field Programmable Gate Array

# I - Composants

Un FPGA est compose de blocs logiques configurables (CLB : Configurable Logic Bloc) qui peuvent prendre la forme d'une porte logique au choix (AND, OR, NOT, etc.) et dont on peut choisir les interactions entre eux.

Nous pouvons creer des ensembles de blocs logiques que l'on appelle des composants.

## 1.1 - Definition d'un composant

Un composant est definit selon une entite et une architecture.

### 1.1.1 - Entite

L'entite permet de definir les entrees/sorties de notre composant.

```vhdl
entity nomEntite is
    
    port
    (
        -- Definition des entrees/sorties
    );

end nomEntite;
```

### 1.1.2 - Architecture

L'architecture permet de definir la structure et les interactions internes de notre composant.

```vhdl
architecture nomArchitecture of nomEntite is

    -- Definition de la structure interne

begin

    -- Definition des interactions internes

end nomArchitecture;
```

# II - Types

# III - Ports

Les ports sont les points d'entrees/sorties de notre composant.

 Syntaxe | Direction
:-------:|:------------------
  `in`   | Entree
  `out`  | Sortie
 `inout` | Bidirectionnel
`buffer` | Sortie reentrantre

```vhdl
nomDuPort : <direction> <typeDuPort>
```

# IV - Structure Interne

## 4.1 - Component

Dans un composant il est possible dans inclure d'autres.

Il faut donc redefinir les ports de ces derniers pour interagir avec eux dans notre nouveau composant.

```vhdl
component nomComposantInterne
    port(
        -- Redefinition des entrees/sorties
        -- Du point de vue exterieur a nomComposantInterne
        -- Pour le point de vue interieur a notre nouveau composant
    );
end component nomComposantInterne;
```

## 4.2 - Signal

Pour communiquer entre deux composants internes il faut creer un signal interne afin de relier les ports de ces composants.

```vhdl
signal nomSignal : <typeDuSignal>
```

# V - Interactions Internes

## 5.1 - Connexion

Maintenant que nos ports sont definis il faut pouvoir les connecter.

```vhdl
nomPortA <= nomPortB;
```

## 5.2 - Affectation

Il est possible d'affecter une valeur a un port.

```vhdl
nomPortA <= valeur;
```

## 5.3 - Operations

Il est bien egalement possible d'effectuer des operations plus complexes.

```vhdl
nomPortA <= nomPortB and nomPortC;
```

## 5.4 - WHEN

Le mot cle `WHEN` est similaire au **case** en [C](https://github.com/Plunne/Nemo/blob/main/C/Cours/Cours1.md#switch) et s'utilise sous 2 formes.

### 5.4.1 - WITH SELECT WHEN

Avec `WITH` et `SELECT` : Equivalent au **switch** en [C](https://github.com/Plunne/Nemo/blob/main/C/Cours/Cours1.md#switch).

```vhdl
WITH choix SELECT 
    nomPortA <= valeur1 WHEN choix1 ELSE,
                valeur2 WHEN choix2 ELSE,
                valeur3 WHEN choix3 ELSE,
                valeur0 WHEN others;
```

### 5.4.2 - WHEN ELSE

Avec `ELSE` tout seul : Equivalent au **else if** en [C](https://github.com/Plunne/Nemo/blob/main/C/Cours/Cours1.md#else-if).

```vhdl
nomPortA <= valeur1 WHEN condition1 ELSE
            valeur2 WHEN condition2 ELSE
            valeur3 WHEN condition3 ELSE
            valeur0;
```