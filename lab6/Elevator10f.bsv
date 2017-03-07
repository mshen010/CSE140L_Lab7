package Elevator10f;
import Vector::*;

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
