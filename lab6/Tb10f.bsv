import Randomizable::*;
import Elevator10f::*;
import Vector::*;

module mk10Floors();
        ElevatorNF myElevator <- mkElevatorNF();
        Reg#(int) realFloor <- mkReg(0);
        Reg#(int) step <- mkReg(0);
        Reg#(Moving) moving <- mkReg(STOP);
        Reg#(Direction) direction <- mkReg(UP);
        Reg#(Bool) update <- mkReg(False);
	Reg#(Bool) setFloor <-mkReg(False);
	Reg#(int) move_up_timer <- mkReg(0);
	Reg#(int) move_down_timer <- mkReg(0);
	Reg#(int) trace_step <- mkReg(0);

        (* descending_urgency ="start, step_1, step_2, step_3, step_4, finish, check_stop, update_state, move_up, move_down, nothing" *)
        rule start if (realFloor == 0 && step == 0 && !update);
                myElevator.setCurrentFloor(realFloor);
                step <= -1;
                update <= True;
        endrule

        rule step_1 if ( realFloor == 0 &&step == - 1 && !update && moving == STOP);
                myElevator.floor_down_request(5);
                $display("The elevator stops at floor %d", realFloor);
                $display("Request to go down from Floor 5");
                step <= 1;
                update <= True;
	endrule

       rule step_2 if ( realFloor == 5 && moving == STOP && step == 1 && !update);
                $display("The elevator stops at floor %d", realFloor);
                myElevator.floor_des_request(0);
                $display("destination is set to Floor 0");
                myElevator.floor_up_request(3);
                $display("Request to go up from Floor 3");
                step <= 2;
                update <= True;
        endrule

        rule step_3 if (realFloor == 0 && moving == STOP && step == 2 && !update);
                $display("The elevator stops at floor %d", realFloor);
                update <= True;
                step <= 3;
        endrule

        rule step_4 if ( realFloor == 3 && moving == STOP && step == 3 && !update);
                $display("The elevator stops at floor %d", realFloor);
                $display("desitination is set to Floor 0");
                myElevator.floor_des_request(0);
                step <= 4;
                update <= True;
        endrule

        rule finish if ( realFloor== 0 && moving== STOP && step ==4 && !update);
                $display("The elevator stops at floor %d", realFloor);
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
                //$display("No state change");
                update <= True;
        endrule
endmodule
