# Dragon Minigame — C++ OOP

A text-based RPG combat and inventory system built in C++ demonstrating object oriented programming principles including inheritance, polymorphism, and dynamic memory management.

## Overview
The program simulates an RPG-style game where a player battles enemies and manages an inventory of items. Built across 11 files with a clean class hierarchy.

## Class Hierarchy

**Items**
- Item — base class with name, weight, value
- Weapon — extends Item, adds damage stat
- Armor — extends Item, adds defense and equipment slot
- Potion — extends Item, adds heal amount and consumed state

**Enemies**
- Enemy — base class with health, damage, virtual attack method
- Dragon — alternates between fire breath (3x damage) and normal attack
- Goblin — deals double damage if armed with a weapon
- Skeleton — enemy with armor-based damage reduction

**Other**
- Player — has health and attack power, takes damage in combat
- Inventory — manages a weight-limited collection of Item pointers with dynamic memory

## Key C++ Concepts Demonstrated
- Inheritance and virtual functions
- Polymorphism through base class pointers
- Dynamic memory allocation and cleanup
- Abstract interfaces via virtual methods
- Header guards and multi-file organization
- operator overloading prevention via deleted copy constructor

## How to Compile and Run
```bash
g++ main.cpp -o game
./game
```

## Sample Output
- Inventory management with weight limit enforcement
- Turn-based combat rounds against Dragon, Goblin, and Skeleton enemies
- Player and enemy status displayed after each round

## Course
Object Oriented Programming — Arkansas State University — Spring 2026
