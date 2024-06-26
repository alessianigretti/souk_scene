# souk_scene
WIP small densely populated market scene with customer/merchant interactions featuring FSMs, Perception System and GAS

https://github.com/alessianigretti/souk_scene/assets/17513294/7df3d865-9fc7-47f3-a607-59de8e8a4c78

Features:
- Finite State Machine x2 (Customer and Merchant)
  - https://github.com/alessianigretti/souk_scene/blob/main/Source/souk_scene/Components/FiniteStateMachineComponent.cpp
- States implemented as Gameplay Ability (GAS)
  - https://github.com/alessianigretti/souk_scene/blob/main/Source/souk_scene/Components/FiniteStateMachineTaskBase.h
- State interruption configurability
- State injection into other states
- Syncing between the two FSMs
- Visual improvements: DoF post-processing FX

Future work:
- Utility-based decisions within states to determine the outcome of an interaction
- Support for multiple Merchant characters belonging to the same Shop
- Support for multiple Customer characters interacting with the same Shop

![Screenshot 2024-06-19 151837](https://github.com/alessianigretti/souk_scene/assets/17513294/5ed9b78d-5bec-4bd4-9b60-097077c24d18)
![Screenshot 2024-06-19 151942](https://github.com/alessianigretti/souk_scene/assets/17513294/bb9f315d-5e4b-472e-842a-483e9e11003a)
![Screenshot 2024-06-19 152024](https://github.com/alessianigretti/souk_scene/assets/17513294/0f2c2fd0-ef17-47f3-a125-0f8def835f23)
![Screenshot 2024-06-19 152323](https://github.com/alessianigretti/souk_scene/assets/17513294/2118d463-55e8-491b-b719-0906b9c996f2)

Assets credits: 
- Environment and props: City of Brass: Environment and City of Brass: Props by https://www.uppercut-games.com/
- Placeholder characters and animations: Mixamo
