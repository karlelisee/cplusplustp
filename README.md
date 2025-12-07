# Nombres duaux, vecteurs et matrices (C++ – Sans bibliothèque standard)

Ce projet implémente les **nombres duaux**, ainsi que des structures de données
permettant de manipuler des **vecteurs de nombres duaux** et des **matrices de réels**
en C++, **sans utiliser la bibliothèque standard** (`std::vector`, `std::array`, etc.).

Ce travail suit les consignes du module *Hypercomplex Algebra* de l’École Hexagone.

---

## 🎯 1. Objectif du projet

L’objectif est de :

1. Implémenter un type `DualNumber` représentant un nombre de la forme :

   \[
   a + b\varepsilon \quad \text{avec } \varepsilon^2 = 0
   \]

2. Définir les opérations arithmétiques fondamentales sur ces nombres  
   (addition, soustraction, multiplication, division).

3. Implémenter une structure **safe** pour représenter un **vecteur de nombres duaux**,  
   sans utiliser la STL et en gérant manuellement la mémoire.

4. Implémenter une structure **safe** représentant une **matrice de doubles**,  
   elle aussi sans STL.

5. Surcharger l’opérateur `operator*` pour effectuer la multiplication :

   \[
   (Mv)_i = \sum_{k} M_{ik} v_k
   \]

   où :
   - `M` est une matrice de réels,
   - `v` est un vecteur de nombres duaux,
   - le résultat est un nouveau vecteur de nombres duaux.

---

## 🧮 2. Rappel théorique : nombres duaux

Un nombre dual s’écrit :

\[
a + b\varepsilon,
\]

avec la propriété fondamentale :

\[
\varepsilon^2 = 0.
\]

### Opérations sur les nombres duaux

- **Addition**  
  \[
  (a + b\varepsilon) + (c + d\varepsilon)
  = (a + c) + (b + d)\varepsilon
  \]

- **Soustraction**  
  \[
  (a - c) + (b - d)\varepsilon
  \]

- **Multiplication**  
  \[
  (a + b\varepsilon)(c + d\varepsilon)
  = ac + (ad + bc)\varepsilon
  \]

- **Division**  
  \[
  \frac{a + b\varepsilon}{c + d\varepsilon}
  = \frac{a}{c} + \frac{bc - ad}{c^2}\varepsilon
  \]

- **Exponentielle**  

  \[
  e^{a + b\varepsilon} = e^a + b e^a \varepsilon
  \]

---

---

## ▶️ 3. Comment démarrer le projet

### 1️⃣ Compiler le projet

Assurez-vous d’avoir un compilateur C++ récent (support C++20).

Dans un terminal :

```bash
g++ -std=c++20 dual_matrix.cpp -o dual_matrix