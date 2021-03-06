#include "Dog.h"

Dog::Dog() {

	Energy = 0;
	Hunger = 0;

	State_Sleep = new DogStateSleep;
	State_Eat = new DogStateEat;
	State_Walk = new DogStateWalk;

	Current_State = State_Sleep;

}

void Dog::Update() {
	
	Current_State->Update(this);

}

void Dog::Change_State(States _State) {

	Current_State->Exit(this);

	switch(_State) {
		case Sleep:
			Current_State = State_Sleep;
			break;
		case Eat:
			Current_State = State_Eat;
			break;
		case Walk:
			Current_State = State_Walk;
		default: 
			break;
	}

	Current_State->Enter(this);

}
