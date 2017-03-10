package Elevator10f;
import Vector::*;

function int nextFloorUpStop(Vector#(NUM_FLOOR, Bool) floor_up_pressed, Vector#(NUM_FLOOR, Bool) floor_down_pressed, Vector#(NUM_FLOOR, Bool) floor_des, int currentFloor);
	int temp;
	Integer i = 0;
	int count = fromInteger(i);
	for(i=0; i < 10; i=i+1)
	begin
		if(floor_des[currentFloor] == True || floor_up_pressed[currentFloor] == True)
			temp = currentFloor;
		else if(floor_des[currentFloor] == True || floor_down_pressed[currentFloor] == True)
			temp = currentFloor;
		else
			temp = 9;
	end
	return temp;
endfunction

// assume the elevator is currently going down due to request from the floors below or the current floor 
// or destinations to the floor below or the current floor 
// return the next foor that the elevator should stop, otherwise return the current floor
function int nextFloorDownStop(Vector#(NUM_FLOOR, Bool) floor_up_pressed, Vector#(NUM_FLOOR, Bool) floor_down_pressed, Vector#(NUM_FLOOR, Bool) floor_des, int currentFloor);
	int temp;
	Integer i = 0;
	int count = fromInteger(i);
	for(i=9; i >= 0; i=i+1)
	begin
		if(floor_des[currentFloor] == True || floor_down_pressed[currentFloor] == True)
			temp = currentFloor;
		else if(floor_des[currentFloor] == True || floor_up_pressed[currentFloor] == True)
			temp = currentFloor;
 		else
			temp = 0;
	end
	return temp;
endfunction

function int nextFloorStop(Vector#(NUM_FLOOR, Bool) floor_up_pressed, Vector#(NUM_FLOOR, Bool) floor_down_pressed, Vector#(NUM_FLOOR, Bool) floor_des, int currentFloor, Direction direction); 
	for(i=0; i < 10; i=i+1)
	begin
		if(currentFloor == 9)
			temp = nextFloorDownStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else if(direction == DOWN && i > currentFloor && floor_down_pressed[i] == True)
			temp = nextFloorUpStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else if(direction == DOWN && i <= currentFloor && floor_down_pressed[i] == True)
			temp = nextFloorDownStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else if(direction == UP && i < currentFloor && floor_up_pressed[i] == True)
			temp = nextFloorDownStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else if(direction == UP && i >= currentFloor && floor_up_pressed[i] == True)
			temp = nextFloorDownStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else if(currentFloor == 0)
			temp = nextFloorUpStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else
			temp = currentFloor;
	end
	return temp;
	else // if(direction == UP)
		if(currentFloor == 0)
			return nextFloorUpStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		//Check for request to go down, otherwise go up
		else if(currentFloor == 1)
			if(floor_up_pressed[0] == True || floor_des[0] == True)
				return nextFloorDownStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
			else
				return nextFloorUpStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else if(currentFloor == 2)
			return nextFloorDownStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor);
		else
			return currentFloor;
endfunction 
// assume the elevator is in arbitrary floor and the moving direction can be up or down
typedef enum {UP, DOWN} Direction deriving(Bits, Eq);
typedef enum {START, STOP} Moving deriving(Bits, Eq);
typedef 10 NUM_FLOOR;

interface ElevatorNF;
        method Action floor_up_request(int i);
        method Action floor_down_request(int i);
        method Action floor_des_request(int i);

        method Action setCurrentFloor(int floor);

        method Moving moving;
        method Direction direction;
endinterface

(* synthesize *)
module mkElevatorNF(ElevatorNF);
	Reg#(Vector#(NUM_FLOOR, Bool)) floor_up_pressed <- mkReg(replicate(False));
	Reg#(Vector#(NUM_FLOOR, Bool)) floor_down_pressed <- mkReg(replicate(False));
	Reg#(Vector#(NUM_FLOOR, Bool)) floor_des <- mkReg(replicate(False));

	Reg#(int) currentFloor <-mkReg(0);
	Reg#(Direction) direction_reg <-mkReg(UP);
	Reg#(Moving) moving_reg <-mkReg(STOP);

	//(* descending_urgency = "setCurrentFloor, floor_up_request, floor_down_request, floor_des_request, moving, direction, goingUp, goingDown, stopGoingUp, stopGoingDown, changeDirection" *) 
	//rules
	rule goingUp if(direction_reg == UP && moving_reg == STOP && nextFloorStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor,direction_reg) > currentFloor);
			moving_reg <= START;
	endrule
	// Stops when des_floor is reached 
	rule goingDown if(direction_reg == DOWN && moving_reg == STOP && nextFloorStop(floor_up_pressed, floor_down_pressed, floor_des, currentFloor,direction_reg) < currentFloor);
			moving_reg <= START;
	endrule
	// Starts going up or changes direction
	rule stopGoingUp if(direction_reg == UP && moving_reg == START && nextFloorStop(floor_up_pressed,floor_down_pressed,floor_des,currentFloor,direction_reg) == currentFloor);
		moving_reg <= STOP;
		floor_up_pressed[currentFloor] <= False;
		floor_down_pressed[currentFloor] <= False;
		floor_des[currentFloor] <= False;
	endrule
	// Starts going down or changes direction
	rule stopGoingDown if(direction_reg == DOWN && moving_reg == START && nextFloorStop(floor_up_pressed,floor_down_pressed,floor_des,currentFloor,direction_reg) == currentFloor);
		moving_reg <= STOP;
		floor_up_pressed[currentFloor] <= False;
		floor_down_pressed[currentFloor] <= False;
		floor_des[currentFloor] <= False;
	endrule
	// Changes direction
	rule changeDirection if(moving_reg == STOP && nextFloorStop(floor_up_pressed,floor_down_pressed,floor_des,currentFloor,direction_reg) != currentFloor);
		if(direction_reg == DOWN)
			direction_reg <= UP;
		else
			direction_reg <= DOWN;
	endrule
	// do NOT change the following part
	method Action floor_up_request(int i);
		if ( i >= 0 && i <fromInteger(valueOf(NUM_FLOOR)))
			floor_up_pressed[i] <= True;
		else
		 	begin
				$display("invalid floor");
				$finish;
			end
	endmethod
	
        method Action floor_down_request(int i);
		if ( i >= 0 && i <fromInteger(valueOf(NUM_FLOOR)))
			floor_down_pressed[i] <= True;
		else
		 	begin
				$display("invalid floor");
				$finish;
			end
	endmethod

	method Action floor_des_request(int i);
		if ( i >= 0 && i <fromInteger(valueOf(NUM_FLOOR)))
			floor_des[i] <= True;
		else
		 	begin
				$display("invalid floor");
				$finish;
			end
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
