# Projet : TicTacToe et Puissance 4

## 📄 Résumé de ce qu'il fallait faire
L'objectif de ce projet était de développer deux jeux classiques : 
1. **TicTacToe (Morpion)** : Permettant à deux joueurs (ou un joueur contre une IA) de jouer sur un plateau 3x3 pour aligner trois symboles identiques.
2. **Évolution vers un jeu plus complexe** : Puissance 4

Le projet devait être conçu de manière modulaire, avec un code organisé dans plusieurs fichiers et la possibilité de compiler les deux jeux avec **CMake**.

---

## 🔧 Résumé de ce que j'ai fait
### TicTacToe
J'ai commencé par implémenter un jeu de **TicTacToe** classique avec un plateau 3x3. Ensuite, j'ai voulu offrir la possibilité de jouer sur des plateaux plus grands (4x4 ou 5x5) pour rendre le jeu plus intéressant. 

Au départ, j'avais des problèmes liés à l'utilisation de **types incompatibles** (comme `char` et `int`) et cela rendait difficile la manipulation dynamique des tailles de plateau. Grâce aux séances de TD et au soutien en programmation, j'ai pu corriger ces problèmes en utilisant **`std::vector`** pour représenter dynamiquement le plateau. Maintenant, le jeu fonctionne parfaitement avec des plateaux de tailles variables, configurables par l'utilisateur.

### Puissance 4
Pour le **Puissance 4**, j'ai repris la base du code du TicTacToe et je l'ai modifiée pour répondre aux règles spécifiques du jeu :
- Un plateau de 6x7 cases.
- Alignement de 4 jetons horizontalement, verticalement, ou en diagonale.
- J'ai rencontré peu de difficultés sur cette partie, car la structure du code du TicTacToe était suffisamment flexible pour s'adapter.

---

## 💡 Conclusion
Ce projet m'a permis de consolider mes compétences en C++ sur plusieurs aspects :
- Organisation du code en fichiers et utilisation de headers.
- Utilisation de `std::vector` pour créer des plateaux de tailles variables.
- Comprendre et corriger mes erreurs grâce au débogage de VSCode.

Je suis satisfait du résultat final et de la manière dont j'ai pu surmonter les problèmes rencontrés. Ce projet m'a aussi permis de mieux comprendre l'importance de structurer correctement son code dès le début pour faciliter les extensions et les modifications.

---

## 🛠️ Instructions pour compiler et exécuter
1. Assurez-vous d'avoir **CMake** installé sur votre machine.
2. Clonez ce dépôt ou téléchargez les fichiers.
3. Créez un dossier `build` :
   ```bash
   mkdir build && cd build
