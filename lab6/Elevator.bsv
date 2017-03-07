package Elevator;
import Vector::*;
import ElevatorInterface::*;
//typedef 3 NUM_FLOOR;

// assume the elevator is currently going up due to request from the floors above or the current floor 
// or destinations to the floor above or the current floor 
// return the next foor that the elevator should stop, otherwise return the current floor
function int nextFloorUpStop(Vector#(NUM_FLOOR, Bool) floor_up_pressed, Vector#(NUM_FLOOR, Bool) floor_down_pressed, Vector#(NUM_FLOOR, Bool) floor_des, int currentFloor);
	if(currentFloor == 0)
		if(floor_des[0] == True || floor_up_pressed[0] == True)
			return 0;
		else if(floor_des[1] == True || floor_up_pressed[1] == True)
			return 1;
		else if(floor_des[2] == True || floor_down_pressed[2] == True)
			return 2;
		else if(floor_down_pressed[1] == True)
			return 1;
		else
			return 0;
	else if(currentFloor == 1)
		if(floor_des[1] == True || floor_up_pressed[1] == True)
			return 1;
		else if(floor_des[2] == True || floor_down_pressed[2] == True)
			return 2;
		else
			return 1;
	else //currentFloor == 2
			return 2;
endfunction

// assume the elevator is currently going down due to request from the floors below or the current floor 
// or destinations to the floor below or the current floor 
// return the next foor that the elevator should stop, otherwise return the current floor
function int nextFloorDownStop(Vector#(NUM_FLOOR, Bool) floor_up_pressed, Vector#(NUM_FLOOR, Bool) floor_down_pressed, Vector#(NUM_FLOOR, Bool) floor_des, int currentFloor);
	if(currentFloor == 2)
		if(floor_des[2] == True || floor_down_pressed[2] == True)
			return 2;
		else if(floor_des[1] == True || floor_down_pressed[1] == True)
			return 1;
		else if(floor_des[0] == True || floor_up_pressed[0] == True)
			return 0;
		else if(floor_up_pressed[1] == True)
			return 1;
		else
			return 2;
	else if(currentFloor == 1)
		if(floor_des[1] == True || floor_down_pressed[1] == True)
			return 1;
		else if(floor_des[0] == True || floor_up_pressed[0] == True)
			return 0;
		else
			return 1;
	else // currentFloor == 0
			return 0;
endfunction

// assume the elevator is in arbitrary floor and the moving direction can be up or down
//  return the next foor that the elevator should stop, otherwise return the current floor
function int nextFloorStop(Vector#(NUM_FLOOR, Bool) floor_up_pressed, Vector#(NUM_FLOOR, Bool) floor_down_pressed, Vector#(NUM_FLOOR, Bool) floor_des, int currentFloor, Direction direction); 
	if(direction == DOWN)
		if(currentFloor == 2)
			return nextFloorDownStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		//Check for request to go down from top floor, otherwise go down
		else if(currentFloor == 1)
			if(floor_down_pressed[2] == True)
				return nextFloorUpStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
			else
				return nextFloorDownStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else if(currentFloor == 0)
			return nextFloorUpStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else
			return currentFloor;
	else // if(direction == UP)
		if(currentFloor == 0)
			return nextFloorUpStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		//Check for request to go down, otherwise go up
		else if(currentFloor == 1)
			if(floor_up_pressed[0] == True)
				return nextFloorDownStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
			else
				return nextFloorUpStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else if(currentFloor == 2)
			return nextFloorDownStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else
			return currentFloor;
endfunction 

(* synthesize *)
module mkElevator(Elevator);
	// DO NOT change these registers
	Reg#(Vector#(NUM_FLOOR, Bool)) floor_up_pressed <- mkReg(replicate(False));
	Reg#(Vector#(NUM_FLOOR, Bool)) floor_down_pressed <- mkReg(replicate(False));
	Reg#(Vector#(NUM_FLOOR, Bool)) floor_des <- mkReg(replicate(False));

	Reg#(int) currentFloor <-mkReg(0);
	Reg#(Direction) direction_reg <-mkReg(UP);
	Reg#(Moving) moving_reg <-mkReg(STOP);

	//(* descending_urgency = "setCurrentFloor, floor_0_up_request, floor_1_up_request, floor_1_down_request, floor_2_down_request, floor_0_des_request, floor_1_des_request, floor_2_des_request, moving, direction, goingUp, goingDown, stopGoingUp, stopGoingDown, changeDirection" *) 
	//rules
	rule goingUp;
	endrule 

	rule goingDown;
	endrule
	
	rule stopGoingUp;
	endrule

	rule stopGoingDown;
	endrule

	rule changeDirection;
	endrule

	// do not change the following part
	method Action floor_0_up_request;
		floor_up_pressed[0] <= True;
	endmethod

	method Action floor_1_up_request;
		floor_up_pressed[1] <= True;
	endmethod

	method Action floor_1_down_request;
		floor_down_pressed[1] <= True;
	endmethod

	method Action floor_2_down_request;
		floor_down_pressed[2] <= True;
	endmethod

	method Action floor_0_des_request;
		floor_des[0] <= True;
	endmethod 

	method Action floor_1_des_request;
		floor_des[1] <= True;
	endmethod

	method Action floor_2_des_request;
		floor_des[2] <= True;
	endmethod

	method Action setCurrentFloor(int floor);
		currentFloor <= floor;
	endmethod

	method Moving moving;
		return moving_reg;
	endmethod

	method Direction direction;
		return direction_reg;
	endmethod
endmodule

endpackage
