# FTL-Clone

## Concepts

![image](https://github.com/user-attachments/assets/a282cd63-44c4-40e7-89a7-7be276a86d33)

The main reference of this game is a space strategy - FTL. There user control Ship in the space that combined from different stars.
Some stars is empty, some may contains an enemy and some is a Store/Factrory where user may repair own ship or buy new components.


## TODO
- [x]  Map
  - [x] Node|Star: it is a simple shape that has circle shape;
  - [x] Grap of nodes: the main idea is bind Nodes (1-3 nodes). I release it using adjacencyList  and highlith edges. Also each node has isVisible flag:  it is mean that user will see only neighbour hyperways;
  - [x] Type of node: we have  Node, NodeShadow (manevrity will automatically increased), NodeWithEnemy (node where fight could be init), NodeStore (node where user will be able to repaire| buy smt);
  - [x] Movement: movement is controlled by mouse, LBTM on Node will start movement, Player is able move only to linked Nodes from start Node, movement cost a fuel; 
  - [x] Map generation: it is the most interesting part. I implemented cluster generation it is mean that we have one Node as root of cluster and group random nodees around cluster. Map can be generated larger than screen size but it is a not a problem, because we have a scrool zoom and camero folloving Player Ship. 
 
- [ ]  Player Ship
  - [x] Base Ship class 
  - [x] Health
  - [x] Damage
  - [x] Shield
  - [x] Speed
  - [x] resources
  - [ ] Crew
  - [ ] Modules System
 
- [ ] Enemy Ship
  - [x] Base Ship class 
  - [x] Health
  - [x] Damage
  - [ ] Shield
  - [ ] Speed
  - [ ] Type of enemies
  - [ ] Crew
  - [ ] Modules System

- [ ] Fight
  - [x] Base Fight
  - [ ] Remuneration
  - [ ] Type of Weapons
  - [ ] Escape
  - [ ] Module demage

- [ ] UI
  - [x] Player Ship states (Health, Shield...)
  - [ ] Enemy States
  - [ ] Esc / Pause
  - [ ] You won! / You died!

- [ ] Additional features
  - [ ] Save | Load
  - [ ] Different types of player ship
  - [ ] The level of difficulty
  - [ ] Crew control | undirect control
  - [ ] Network
  - [ ]  Network + 

  
  ## How to play

- Player ship started on one of hub root;
- Use LBM to set up moving to target node;
NOTE: user can move only throuth hyperways
![image](https://github.com/user-attachments/assets/0ed6650e-6816-4155-9c37-511a42869886)
- WIP: sometimes when you dockToStar fight can be init. I you win you will earn money and some fuel;
- WIP: if you ship will be destroyed you will lose;
- WIP: visit store to exchange money on resources or repair ship

## References
![image](https://github.com/user-attachments/assets/4dd00b8c-9365-4b93-991e-ab76b6c70c19)
![image](https://github.com/user-attachments/assets/9cf3df6e-0293-499d-b658-3675917d6be8)
![image](https://github.com/user-attachments/assets/d0b2c919-a9f9-463d-9587-620280e32805)
![image](https://github.com/user-attachments/assets/7769f499-b01c-460e-a70d-d15036d92295)







