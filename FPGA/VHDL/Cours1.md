---
author: Lena SAVY-LARIGALDIE
title: FPGA/Cours1.md
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

# Composants

Un FPGA est compose de blocs logiques configurables (CLB : Configurable Logic Bloc) qui peuvent prendre la forme d'une porte logique au choix (AND, OR, NOT, etc.) et dont on peut choisir les interactions entre eux.

Nous pouvons creer des ensembles de blocs logiques que l'on appelle des composants.

## Definition d'un composant

Un composant est definit selon une entite et une architecture.

### Entite

L'entite permet de definir les entrees/sorties de notre composant.

```vhdl
entity nomEntite is
    
    port
    (
        -- Definition des entrees/sorties
    );

end nomEntite;
```

### Architecture

L'architecture permet de definir la structure et les interactions internes de notre composant.

```vhdl
architecture nomArchitecture of nomEntite is

    -- Definition de la structure interne

begin

    -- Definition des interactions internes

end nomArchitecture;
```

# Entrees/Sorties

## Types

## Syntaxe d'Entrees/Sorties

# Architecture

## Structure Interne

### Signaux

### Components

## Interactions Internes