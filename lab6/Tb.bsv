import Randomizable::*;
import staffElevator::*;
import Elevator::*;
import ElevatorInterface::*;
import Vector::*;
import LFSR::*;
import FIFO::*;
import TbNextFloor::*;
(* synthesize *)
module mkNextFloorUpStop();
    Reg#(Bit#(32)) cycle <- mkReg(0);
    Randomize#(Vector#(NUM_FLOOR, Bool)) floor_up_pressed <- mkGenericRandomizer;
    Randomize#(Vector#(NUM_FLOOR, Bool)) floor_down_pressed <- mkGenericRandomizer;
    Randomize#(Vector#(NUM_FLOOR, Bool)) floor_des <- mkGenericRandomizer;
    Randomize#(int) currentFloor <- mkGenericRandomizer;

    rule test;
        if(cycle == 0) begin
            floor_up_pressed.cntrl.init;
            floor_down_pressed.cntrl.init;
            floor_des.cntrl.init;
	    currentFloor.cntrl.init;
        end else if(cycle == 128) begin
            $display("PASSED");
            $finish;
        end else begin
            Vector#(NUM_FLOOR, Bool) up_pressed <- floor_up_pressed.next;
            Vector#(NUM_FLOOR, Bool) down_pressed <- floor_down_pressed.next;
            Vector#(NUM_FLOOR, Bool) des <- floor_des.next;

	    down_pressed[0] = False;
	    up_pressed[valueOf(NUM_FLOOR)-1] = False;

	    int current <- currentFloor.next ;
            if(staff_nextFloorUpStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR))) ) != nextFloorUpStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR)))) ) begin
		$display("FAIL %d", cycle);
		for ( Integer i = 0; i < valueOf(NUM_FLOOR); i = i + 1 )
			begin
				$display("floor_up_pressed[%d]=%b",i,up_pressed[i]);
				$display("floor_down_pressed[%d]=%b",i,down_pressed[i]);
				$display("floor_des[%d]=%b",i, des[i]);
			end
		$display("currentFloor=%d",abs(current % fromInteger(valueOf(NUM_FLOOR))) );
		$display("Expected=%d, Your answer=%d",staff_nextFloorUpStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR))) ), nextFloorUpStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR)) )) );
                $finish;
            end
		else begin
		end
        end
        cycle <= cycle + 1;
    endrule
endmodule

(* synthesize *)
module mkNextFloorDownStop();
    Reg#(Bit#(32)) cycle <- mkReg(0);
    Randomize#(Vector#(NUM_FLOOR, Bool)) floor_up_pressed <- mkGenericRandomizer;
    Randomize#(Vector#(NUM_FLOOR, Bool)) floor_down_pressed <- mkGenericRandomizer;
    Randomize#(Vector#(NUM_FLOOR, Bool)) floor_des <- mkGenericRandomizer;
    Randomize#(int) currentFloor <- mkGenericRandomizer;

    rule test;
        if(cycle == 0) begin
            floor_up_pressed.cntrl.init;
            floor_down_pressed.cntrl.init;
            floor_des.cntrl.init;
	    currentFloor.cntrl.init;
        end else if(cycle == 128) begin
            $display("PASSED");
            $finish;
        end else begin
            Vector#(NUM_FLOOR, Bool) up_pressed <- floor_up_pressed.next;
            Vector#(NUM_FLOOR, Bool) down_pressed <- floor_down_pressed.next;
            Vector#(NUM_FLOOR, Bool) des <- floor_des.next;

	    down_pressed[0] = False;
	    up_pressed[valueOf(NUM_FLOOR)-1] = False;

	    int current <- currentFloor.next ;
            if(staff_nextFloorDownStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR))) ) != nextFloorDownStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR)))) ) begin
		$display("FAIL");
		for ( Integer i = 0; i < valueOf(NUM_FLOOR); i = i + 1 )
			begin
				$display("floor_up_pressed[%d]=%b",i,up_pressed[i]);
				$display("floor_down_pressed[%d]=%b",i,down_pressed[i]);
				$display("floor_des[%d]=%b",i, des[i]);
			end
		$display("currentFloor=%d",abs(current % fromInteger(valueOf(NUM_FLOOR))) );
		$display("Expected=%d, Your answer=%d",staff_nextFloorDownStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR))) ), nextFloorDownStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR)) )) );
                $finish;
            end
		else begin
		end
        end
        cycle <= cycle + 1;
    endrule
endmodule

function Bool all_clear( Vector#(NUM_FLOOR, Bool) up_pressed, Vector#(NUM_FLOOR, Bool) down_pressed, Vector#(NUM_FLOOR, Bool) des);
        return (up_pressed == replicate(False) && down_pressed == replicate(False) && des == replicate(False));
endfunction

function Vector#(NUM_FLOOR, int) regularize(Vector#(NUM_FLOOR, int) floor_des,Direction direction);
        Vector#(NUM_FLOOR, int) ret = floor_des;
        if (direction == DOWN)
        begin
                ret[1] = 0;
                for (Integer i = 2; i < valueOf(NUM_FLOOR); i = i +1)
                begin
                        ret[i] = fromInteger(i) - (1+abs(ret[i] % (fromInteger(i) -1 )));
                end

        end
        else
        begin
                ret[valueOf(NUM_FLOOR) -2] = fromInteger(valueOf(NUM_FLOOR) -1);
                for ( Integer i = 0; i < valueOf(NUM_FLOOR) -2; i = i + 1)
                begin
                        ret[i] = fromInteger(i) + (1+abs(ret[i] % (fromInteger(valueOf(NUM_FLOOR)) - fromInteger(i)-1)));
                end
        end
        return ret;
endfunction

(* synthesize *)
module mkNextFloorStop();
    Reg#(Bit#(32)) cycle <- mkReg(0);
    TestNextFloor testTb <- mkTbNextFloor;
    rule test;
        if(cycle == 0) begin
            
        end else if(cycle == 128) begin
            $display("PASSED");
            $finish;
        end else begin
		TestObj x <- testTb.getObj;
            Vector#(NUM_FLOOR, Bool) up_pressed = x.floor_up_pressed;
            Vector#(NUM_FLOOR, Bool) down_pressed  = x.floor_down_pressed;
            Vector#(NUM_FLOOR, Bool) des =  x.floor_des;
	    Direction dir = x.direction;
	    int current = x.currentFloor ;
            if(staff_nextFloorStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR))), dir ) != nextFloorStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR))), dir) ) begin
		$display("FAILED!");
		for ( Integer i = 0; i < valueOf(NUM_FLOOR); i = i + 1 )
			begin
				$display("Floor:%d floor_up_pressed    = %s",i,up_pressed[i]?"True":"False");
                                $display("Floor:%d floor_down_pressed  = %s",i,down_pressed[i]?"True":"False");
                                $display("Floor:%d floor_des           = %s",i, des[i]?"True":"False");
                                $display("----------------------------------------------");
			end
		$display("currentFloor=%d",abs(current % fromInteger(valueOf(NUM_FLOOR))) );
		if (dir == UP)
		    $display("moving direction: UP");
	        else
		    $display("moving direction: DOWN");
		$display("Expected=%d, Your answer=%d",staff_nextFloorStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR))), dir ), nextFloorStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR)) ), dir) );
                $finish;
            end
		else begin
		for ( Integer i = 0; i < valueOf(NUM_FLOOR); i = i + 1 )
			begin
				$display("Floor:%d floor_up_pressed    = %s",i,up_pressed[i]?"True":"False");
				$display("Floor:%d floor_down_pressed  = %s",i,down_pressed[i]?"True":"False");
				$display("Floor:%d floor_des           = %s",i, des[i]?"True":"False");
				$display("----------------------------------------------");
			end
		$display("currentFloor=%d",abs(current %fromInteger(valueOf(NUM_FLOOR))) );
		if (dir == UP)
		    $display("moving direction: UP");
	        else
		    $display("moving direction: DOWN");
		$display("Expected=%d, Your answer=%d",staff_nextFloorStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR)) ), dir), nextFloorStop(up_pressed, down_pressed, des, abs(current % fromInteger(valueOf(NUM_FLOOR)) ), dir) );
			$display("PASS %d\n______________________________________________________________________", cycle);
		end
        end
        cycle <= cycle + 1;
    endrule
endmodule



module mkRules();
        Elevator myElevator <- mkElevator();
        Reg#(int) realFloor <- mkReg(0);
        Reg#(int) step <- mkReg(0);
        Reg#(Moving) moving <- mkReg(STOP);
        Reg#(Direction) direction <- mkReg(UP);
        Reg#(Bool) update <- mkReg(True);
        Reg#(Bool) setFloor <-mkReg(False);
        Reg#(int) move_up_timer <- mkReg(0);
        Reg#(int) move_down_timer <- mkReg(0);
	Reg#(int) trace_step <- mkReg(0);
        //(* descending_urgency ="check_floor_2, start, press_inside, finish, update_state, move_up, move_down, nothing" *)
        (* descending_urgency ="start, step_1, step_2, step_3, step_4, finish, check_stop, update_state, move_up, move_down, nothing" *)
        rule start if (realFloor == 0 && step == 0 && !update);
		//$display("The elevator is at Floor 0");
                myElevator.setCurrentFloor(realFloor);
                step <= -1;
		update <= True;
        endrule

	rule step_1 if ( realFloor == 0 &&step == - 1 && !update && moving == STOP);
		myElevator.floor_2_down_request();
		$display("The elevator stops at floor %d", realFloor);
		$display("Request to go down from Floor 2");
		step <= 1;
		update <= True;

	endrule
        rule step_2 if ( realFloor == 2 && moving == STOP && step == 1 && !update);
		$display("The elevator stops at floor %d", realFloor);
                //$display("Reaches Floor 2, door opened the passenger get in");
                myElevator.floor_0_des_request;
		$display("destination is set to Floor 0");
 		myElevator.floor_1_up_request;
		$display("Request to go up from Floor 1");
 		step <= 2;
		update <= True;
        endrule

        rule step_3 if (realFloor == 0 && moving == STOP && step == 2 && !update);
                //$display("successfully send passenger to Floor G");
		$display("The elevator stops at floor %d", realFloor);
		update <= True;
		step <= 3;
                //$finish(0);
        endrule

	rule step_4 if ( realFloor == 1 && moving == STOP && step == 3 && !update);
		$display("The elevator stops at floor %d", realFloor);
		$display("desitination is set to Floor 0");
		myElevator.floor_0_des_request;
		step <= 4;
		update <= True;
        
	endrule

	rule finish if ( realFloor== 0 && moving== STOP && step ==4 && !update);
		$display("The elevator stops at floor %d", realFloor);
		//$display("PASSED");
		$finish(0);
	endrule

        // common
        rule update_state if (update && !setFloor);
        
                direction <= myElevator.direction;
                moving <= myElevator.moving;
                setFloor <= True;
        endrule
        rule set_floor if (update);
        
	         myElevator.setCurrentFloor(realFloor);
                update <= False;
                setFloor <= False;
        endrule
        rule move_up if (moving == START && direction == UP && realFloor <10 && !update);
        
                if (move_up_timer == 20)
                begin
                        move_up_timer <= 0;
                        myElevator.setCurrentFloor(realFloor+1);
                        realFloor <= realFloor + 1;
                	$display("The elevator is moving up");
                end
                else
                move_up_timer <= move_up_timer + 1;
                update <= True;
        endrule

	rule check_stop if ( moving == STOP && !update);
        
		$display("The elevator stops at floor %d", realFloor);
		update <= True;
	endrule

        rule move_down if (moving == START && direction== DOWN && realFloor > 0 && !update);
        
                if (move_down_timer == 20)
                begin
                        move_down_timer <= 0;
                        myElevator.setCurrentFloor(realFloor-1);
                        realFloor <= realFloor - 1;
                	$display("The elevator is moving down");
                end
                else
                move_down_timer <= move_down_timer + 1;
                update <= True;
        endrule

        rule nothing if (!update);
         	update <= True;
        endrule

endmodule
