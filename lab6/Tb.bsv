import Randomizable::*;
import staffElevator::*;
import Elevator::*;
import ElevatorInterface::*;
import Vector::*;

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
    Randomize#(Vector#(NUM_FLOOR, Bool)) floor_up_pressed <- mkGenericRandomizer;
    Randomize#(Vector#(NUM_FLOOR, int)) floor_up_des <- mkGenericRandomizer;
    Randomize#(Vector#(NUM_FLOOR, Bool)) floor_down_pressed <- mkGenericRandomizer;
    Randomize#(Vector#(NUM_FLOOR, int)) floor_down_des <- mkGenericRandomizer;

    Randomize#(int) currentFloor <- mkGenericRandomizer;
    Randomize#(Bool) direction <- mkGenericRandomizer;

    Reg#(Bool) nextTest <- mkReg(True);
    Reg#(Vector#(NUM_FLOOR, Bool)) up_pressed <- mkReg(replicate(False));
    Reg#(Vector#(NUM_FLOOR, int)) up_des <- mkReg(replicate(0));
    Reg#(Vector#(NUM_FLOOR, Bool)) down_pressed <- mkReg(replicate(False));
    Reg#(Vector#(NUM_FLOOR, int)) down_des <- mkReg(replicate(0));
    Reg#(Vector#(NUM_FLOOR, Bool)) des <- mkReg(replicate(False));
    Reg#(int) current <- mkReg(0);
    Reg#(Bool) c_direction <- mkReg(False);
    Reg#(Bool) reset_des_reg <- mkReg(False);
    Reg#(Bool) display <- mkReg(False);
    Reg#(Bool) up_floor <- mkReg(True);
    Reg#(int) phase <- mkReg(1);
    Reg#(int) tle <- mkReg(0);

    rule upFloor if ( !nextTest && !all_clear(up_pressed, down_pressed, des) && phase == 0);
        phase <= 1;
        //$display("upFloor %d %d",  nextFloorStop( up_pressed, down_pressed, des, current, UP), nextFloorStop( up_pressed, down_pressed, des, current, DOWN) );
        up_floor <= False;
        if ( c_direction == True)
        begin
                current <= nextFloorStop( up_pressed, down_pressed, des, current, UP);
                if ( current >  nextFloorStop( up_pressed, down_pressed, des, current, UP))
                c_direction <= False;
        end
        else if ( c_direction == False) begin 
                 current <= nextFloorStop( up_pressed, down_pressed, des, current, DOWN);
                if ( current < nextFloorStop(up_pressed, down_pressed, des, current, DOWN))
                c_direction <= True;
	end
    endrule

    rule go_to_next_stop if ( !nextTest && !all_clear(up_pressed, down_pressed, des) && phase == 1);
        phase <= 2;
        up_floor <= True;
        reset_des_reg <= True;
        tle <= tle + 1;
        $display("The elevator stops at Floor %d", current);
        if (tle > 20)
        begin
                $display("FAIL: ELEVATOR STALLS");
                $finish(0);
        end
        if (c_direction == True)
        begin
                //$display("go up");
                //current <= nextFloorStop( up_pressed, down_pressed, des, current, UP);
                if (up_pressed[current]) begin
                        up_pressed[current] <= False;
                        des[regularize(up_des, UP)[current]] <= True;
                end else if ( !des[current] && !up_pressed[current])
                begin
                        if (down_pressed[current])
                        begin
                                down_pressed[current] <= False;
                                des[regularize(down_des,DOWN)[current]] <= True;
                                c_direction <= False;
                        end
                end
        end
        else if (c_direction ==False)
        begin
                //$display("go down %d %d",nextFloorStop( up_pressed, down_pressed, des, current, DOWN), current );
                //current <= nextFloorStop( up_pressed, down_pressed, des, current, DOWN);
                if (down_pressed[current]) begin
                        down_pressed[current] <= False;
                        des[regularize(down_des,DOWN)[current]] <= True;
                end else if ( !des[current] && !down_pressed[current])
                begin
                        if (up_pressed[current])
                        begin

                                //$display("ok %d", regularize(up_des,UP)[current]);
                                up_pressed[current] <= False;
                                des[regularize(up_des, UP)[current]] <= True;
                                c_direction <= True;
                        end
                end
        end
    endrule

    rule finish if (!nextTest && all_clear(up_pressed, down_pressed, des));
        cycle <= cycle + 1;
        $display("FINISH TEST %d", cycle);
        nextTest <= True;
    endrule

    rule reset_des if (!nextTest && phase == 2 );
        phase <= 0;
        //$display("reset_des_reg");
        if (des[current]) begin
                reset_des_reg <= False;
                des[current] <= False;
        end
    endrule


    rule test if (nextTest);
        if(cycle == 0) begin
            floor_up_pressed.cntrl.init;
            floor_up_des.cntrl.init;
            floor_down_pressed.cntrl.init;
            floor_down_des.cntrl.init;
            currentFloor.cntrl.init;
            direction.cntrl.init;
            cycle <= cycle + 1;
        end else if(cycle == 128) begin
            $display("FINISH ALL TEST");
            $finish;
        end else if (!display) begin
            let static_current <- currentFloor.next;
            let static_c_direction <- direction.next;
            let static_up_pressed <- floor_up_pressed.next;
            let static_down_pressed <- floor_down_pressed.next;
            let static_up_des <- floor_up_des.next;
            let static_down_des <- floor_down_des.next;
            static_up_pressed[valueOf(NUM_FLOOR)-1] = False;
            static_down_pressed[0] = False;
            current <= abs(static_current % fromInteger(valueOf(NUM_FLOOR)));
            c_direction <= static_c_direction;
            up_pressed <= static_up_pressed;
            down_pressed <= static_down_pressed;
            up_des <= static_up_des;
            down_des <= static_down_des;
            display <= True;
            tle <= 0;
            $display("START TEST %d", cycle);
        end else if (display) begin
            $display("currentFloor=%d",abs(current % fromInteger(valueOf(NUM_FLOOR))) );
            Direction dir = UP;
            if (c_direction == False)
                dir = DOWN;

            if (dir == UP)
                $display("MOVING DIRECTION: UP");
            else
                $display("MOVING DIRECTION: DOWN");

            for ( Integer i = 0; i < valueOf(NUM_FLOOR); i = i + 1 )
                begin
                        if (up_pressed[i])
                                $display("A PERSON AT FLOOR %d REQUEST TO GO UP, ONCE ENTERED CABIN HE OR SHE WILL PRESS FLOOR %d", i, regularize(up_des,UP)[i] );
                        if (down_pressed[i])
                                $display("A PERSON AT FLOOR %d REQUEST TO GO DOWN, ONCE ENTERED CABIN HE OR SHE WILL PRESS FLOOR %d", i, regularize(down_des,DOWN)[i]);
                end
            display <= False;
            nextTest <= False;
            //cycle <= cycle + 1;
        end
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
