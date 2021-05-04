# Introduction

Dans ce depôt se trouve le projet Abalone du binôme Sylla Alhassanne et Lahyaoui Ayoub.
Le projet respectera le design pattern MVC mais implementera aussi d'autre design patern tel que le design pattern Observer/Observable.
Ce depôt sera continuellement mis a jour par les deux membres du binôme en fonction de l'avancée du projet.

#### Description d'Abalone:
Abalone est un jeu de stratégie combinatoire abstrait où s’affrontent deux joueurs.
Un joueur joue avec des billes blanches, l’autre avec des billes noires. Le but du jeu est d’être le premier à faire sortir 6 billes adverses du plan de jeu en les poussant avec ses propres billes.

**Confer : Wikipedia**

#### Auteurs de ce projet:
Sylla, Alhassanne.
Matricule: 52192.
Groupe: D212.

Lahyaoui, Ayoub. 
Matricule: 54895.
Groupe: D122.

# Rapport

## Modélisation métier:
![alt text](Analyse/Image/AbaloneModelisation.PNG?raw=true)

**Model** : Interface représentant l'interface Model du design pattern MVC.

**Game** : Classe qui rassemble les éléments nécessaire du jeu pour pouvoir présenter une facade à la vue.

**GameStatus** : Enumération représentant les différents états du jeu.

**Board** : Classe représentant le tableau de jeu, un Board est composé de tableaux d'hexagones.

**Hexagon** : Classe représentant une case du tableau, 
        elle a un attribut _isFree mis a vrai lors du déplacement d'une bille sur la case et 
        un attribut de type enumération définissant le type de la l'hexagon.

**HexagonType** : Enumération représentant le type de l'hexagon.

**Player** : Classe représentant un joueur, il possède un statut (PlayerStatus), 
        une couleur et un compteur de bille perdue.

**PlayerStatus** : Enumération représentant le statut du joueur.

**Color** : Enumération représentant la couleur du joueur et de billes.

**Marble** : Classe représentant une bille sur le tableau de jeu, 
        une bille possède une position sur le tableau et une couleur.

**Position** : Classe représentant une position du tableau.

**Direction** : Enumération représentant une direction d'un mouvement, 
        sera utile lors de l'automatisation de la vérification de la présence de billes 
        dans la direction du mouvement donné.

###### Date de remise:
vendredi 19 février 2021 à 18h00.

## Implémentation Console:
***Execution*** : Ouvrir le projet avec QTcreator, compiler puis executer.

***Utilisation***: Le projet respecte la notation ABA-PRO.

![alt text](Mode%20d'emploi/Image/AbaloneExecution.png?raw=true)

**Notation des coups ABA-PRO**

*Les mouvements au jeu Abalone peuvent être de deux types :*

- Déplacement en ligne : quand on déplace une bille (ou plusieurs) dans une direction.
On indique un tel mouvement par la position de départ suivie de la position d'arrivée de
la bille. Si on déplace un groupe de billes on décrit toujours le déplacement de la bille en "queue"
du mouvement. C'est-à-dire celle sur laquelle on pousserait pour effectuer ce déplacement.
Par exemple, le mouvement I8H7, dénote le déplacement de la
bille de la position I8 à la position H7. Le déplacement de cette bille correspond en fait
au déplacement de tout un groupe de trois billes blanches (on pousse le groupe d'une case
dans une direction).

- Déplacement latéral : quand on déplace deux ou trois billes latéralement.
Un tel mouvement est indiqué par la position de la première bille du groupe, suivie de
la position de la dernière bille du groupe, et enfin suivie de la position d'arrivée de la
première bille mentionnée. Par exemple, le mouvement C3C5D3,
dénote le déplacement du groupe de trois billes entre C3 et C5 vers la position où la
première se trouve en D3.

**Confer : Page 9-10 de l'énoncé du projet Abalone 2020-2021 Esi He2b**

###### Date de remise:
vendredi 2 avril 2021 à 18h00.

## Implémentation Graphique:
***Execution*** : 
Windows -> ouvrir le dossier "Executable" a la racine du projet et executer l'installer dans Executable/Windows/installer.exe.
Linux -> executer en ligne de commande l'executable Executable/abalone-Gui.

Si vous rencontrez des difficultés à executer le projet avec l'une des manières énoncés
vous pouvez toujour ouvrir le projet avec Qtcreator, compiler puis executer.

***Utilisation***: Le projet respecte la notation ABA-PRO.

[](Mode%20d'emploi/Video/abalone-GUI.mkv)
###### Date de remise:
vendredi 7 mai 2021 à 18h00

