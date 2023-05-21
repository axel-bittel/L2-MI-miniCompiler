# Compilateur - Rapport de Projet

Magnoli Mathieu MI<br>
Bittel  Axel    MI

<br>

## Introduction

Dans le cadre de ce projet, nous avons développé un compilateur qui effectue la traduction d'un sous-code du langage C vers une représentation intermédiaire visualisable en DOT (Graphviz). Cette expérience nous a permis d'explorer les aspects pratiques de la compilation, tout en consolidant nos compétences en travail d'équipe et en mettant en pratique les concepts théoriques abordés en cours. Nous avons également été confrontés à diverses difficultés techniques.

<br><br>

## Organisation du travail

Nous avons tous deux activement contribué à toutes les parties du développement. Nous avons travaillé en binôme, ce qui nous a permis de tirer parti de nos compétences complémentaires : Axel => pratique, Mathieu => théorique. La collaboration entre les aspects théoriques et pratiques nous a permis de mettre en place des structures réalistes et adaptées à notre projet. De plus, tout au long du projet, les explications de chacun ont permis une compréhension plus en profondeur de ce projet mais aussi de la matière en générale.

Pour faciliter notre travail d'équipe, nous avons utilisé trois outils essentiels :

1. Trello - Gestion des tâches : <br>
Nous avons utilisé Trello comme outil de gestion de projet pour organiser et suivre nos tâches. Nous avons créé des listes représentant différentes phases du projet, telles que l'analyse lexicale, l'analyse syntaxique, analyse sémantique, etc. Nous avons pu suivre l'avancement de notre binôme sans devoir se réunir à chaque fois.

2. Git - Collaboration et versionnage : <br>
Nous avons utilisé Git comme système de contrôle de version pour gérer notre code. Nous avons créé un dépôt GitHub. Cela nous a permis de travailler simultanément sur le code. 

3. Docker Fedora - Environnement uniforme : <br>
Afin de garantir une cohérence dans nos environnements de développement, nous avons utilisé Docker avec une image Fedora. Cela nous a permis de travailler sur des machines différentes tout en étant assurés d'utiliser le même système d'exploitation.

<br><br><br>

## Choix de développement

Dans le but de simplifier l'implémentation du compilateur, nous avons choisi d'utiliser une structure d'arbre abstrait binaire. Cela nous a permis de bénéficier d'une représentation plus concise et plus facile à manipuler que la gestion d'arbres à n fils. De plus, en faisant ce choix, nous avons pu réutiliser la structure d'arbre binaire ainsi que quelques fonctions associées que nous avions déjà écrites lors de projets antérieurs. La réutilisation d'une structure qui nous est familière nous a permis de gagner du temps et nous a aidé dans la conception de l'arbre. En utilisant un arbre binaire, nous avons pu simplifier les algorithmes de parcours, de génération de code et d'optimisation.
Cependant cela a crée des noeuds intermédiaires.<br><br>
Exemple sur la façon de stocker l'ensemble des noeuds des fonctions :<br>
<img src="Code.dot.svg"
     alt="Markdown Monster icon"
     style="left" /><br>
Nous avons donc dû, durant la traduction en DOT, ignorer ces noeuds intermédiaires.<br>

<br><br>

## Nos structures de données
```c
typedef struct s_tree
{
	void			*content;
	struct s_tree	*f_a;
	struct s_tree	*f_b;
}				t_tree;
```
Cette structure représente un arbre binaire généraliste. Elle contient un pointeur vers le contenu du nœud (content = ici un t_node), un pointeur vers le fils a (f_a) et un pointeur vers le fils b (f_b). <br>
```c
typedef struct	s_node
{
	int                      line;
	char                     type;
	void                     *datas;
	struct s_symbol_table    *table;
}				t_node;
```
Cette structure représente un nœud de l'arbre abstrait. Elle enregistre le numéro de ligne (line), le type du nœud (type), des données spécifiques au type de nœud (datas), et un pointeur vers la table des symboles associée (table, si elle existe). <br>

```c
typedef	struct	s_declaration
{
	int       type;
	char      *name;
	int       cst;
}				t_declaration;
```

Cette structure généraliste représente des informations sur des éléments syntaxiques. Elle enregistre le type de la déclaration (type), le nom de l'identificateur (name), et une valeur constante (cst).<br>

```c
typedef	struct	s_symbol_table
{
	int                      size;
	char				     type_table;
	t_symbol_table_elem      *begin;
	t_symbol_table_elem      *end;
}				t_symbol_table;
```
Cette structure représente une table des symboles. Elle contient un pointeur vers le premier élément de la table (begin) et un pointeur vers le dernier élément (end). Elle enregistre également la taille de la table et le type de la table (Global, fonction ou block). <br>

```c
typedef	struct	s_symbol_table_elem
{
	char                          *name;
	char                          type_identificateur;
	char                          type;
	short                         nb_args;				
	struct s_list_dimension       *list_dimension;	
	struct s_symbol_table_elem    *next;
}				t_symbol_table_elem;
```
Cette structure représente un élément de la table des symboles. Elle enregistre le nom de l'identificateur (name), le type d'identificateur (type_identificateur : fonction,variable), le type de l'élément (type : int / void), le nombre d'arguments pour les fonctions (nb_args), une liste des dimenssions pour les tableaux (list_dimension), et un pointeur vers le prochain élément de la table des symboles (next). <br>

<br>

```c
typedef struct stack_symbol_table
{
	t_symbol_table                *table;
	struct stack_symbol_table     *next;
}				t_stack_symbol_table;
```
Cette structure représente une pile de tables des symboles. Elle contient un pointeur vers une t_symbol_table et un pointeur vers la prochaine pile de tables des symboles (next). Elle est utilisée notamment pour l'analyse sémantique. <br><br>

```c
typedef struct s_list_dimension
{
	int                      dim;
	struct s_list_dimension  *next;
}			t_list_dimension;
```
Cette structure représente une liste chaînée de dimenssions. Elle enregistre une dimension (dim) et un pointeur vers la prochaine dimension (next). Elle est utilisée pour représenter les dimenssions des tableaux multidimensionnels. <br>

<br><br>

## Passes
Notre compilateur est un compilateur en deux passes. <br><br>

1) Notre première passe a pour but, dans un premier temps de réaliser le parsing du code miniC. L'analyse lexicale vérifie l'appartenance des chaines de caractères du code au langage et renvoie des tokens. L'analyse syntaxique utilise ces tokens pour déterminer la structure grammaticale du code miniC et génère notre arbre abstrait. Lors de notre première passe, nous créons et enrichissons également notre table des symboles.<br>

2) Notre seconde passe a pour but de lancer l'analyse sémantique mais également de traduire notre arbre abstrait en arbre dot. L'analyse sémantique vérifie la validité sémantique de notre code miniC. Cela implique entre autre la vérification des types, des identificateurs, la détection des erreurs et des incohérences potentielles dans le code. Lors de la seconde passe, un code à l'origine d'un graphe au format .dot est également généré. Ce graphe représente le code source miniC de manière graphique. <br>

<br><br><br><br>

## Nos difficultés

Dans un premier temps, nous avons commis une erreur dans la création de l'arbre abstrait. En effet, à cause d'une mauvaise lecture du sujet, nous avons commencé par construire un arbre syntaxique complet. Cependant, après une relecture complète et conjointe du sujet, nous avons rapidement pu rectifier notre arbre grâce à des modifications mineures dans la création de ce dernier. Cette expérience nous a rappelé l'importance de l'adaptabilité et de la bonne définition des attentes dans la résolution des problèmes.

<br><br>

## Notre expérience

Ce projet de compilation nous a offert une expérience précieuse et passionnante dans le développement d'un compilateur.
La seul déception est de ne pas avoir fait un compilateur complet vers un langage assembleur.
<br><br>
🏆No leaks certified🏆<br>