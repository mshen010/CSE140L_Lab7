/*
 * Generated by Bluespec Compiler, version 2016.07.beta1 (build 34806, 2016-07-05)
 * 
 * On Tue Mar  7 17:39:05 PST 2017
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkRules.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkRules::MODEL_mkRules()
{
  mkRules_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkRules()
{
  MODEL_mkRules *model = new MODEL_mkRules();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkRules &INST_top = *((MOD_mkRules *)(instance_ptr));
	 tUInt8 DEF_INST_top_INST_myElevator_DEF_NOT_moving_reg___d55;
	 tUInt8 DEF_INST_top_INST_myElevator_DEF_IF_direction_reg_THEN_IF_currentFloor_EQ_2_THE_ETC___d57;
	 tUInt32 DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_floor_des_BIT_0_ETC___d38;
	 tUInt32 DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_floor_des_BIT_2_O_ETC___d28;
	 tUInt32 DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_currentFloor_EQ_ETC___d47;
	 tUInt32 DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_currentFloor_EQ_2_ETC___d42;
	 tUInt32 DEF_INST_top_INST_myElevator_DEF_IF_direction_reg_THEN_IF_currentFloor_EQ_2_THE_ETC___d48;
	 tUInt8 DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_0_5_OR_floor_up_pressed_6_BIT_0_7___d18;
	 tUInt8 DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_1_2_OR_floor_down_pressed_BIT_1_3___d14;
	 tUInt8 DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_2_OR_floor_down_pressed_BIT_2_0___d11;
	 tUInt8 DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_1_2_OR_floor_up_pressed_6_BIT_1_9___d30;
	 tUInt8 DEF_INST_top_DEF_realFloor_EQ_0_AND_moving_2___d20;
	 tUInt8 DEF_INST_top_DEF_NOT_moving_2___d37;
	 tUInt8 DEF_INST_top_DEF_realFloor_EQ_0___d2;
	 tUInt8 DEF_INST_top_DEF_direction__h1431;
	 tUInt8 DEF_INST_top_DEF_moving__h1425;
	 tUInt8 DEF_INST_top_DEF_setFloor__h1021;
	 tUInt32 DEF_INST_top_DEF_b__h395;
	 tUInt8 DEF_INST_top_DEF_update___d6;
	 tUInt8 DEF_INST_top_DEF_NOT_update___d7;
	 INST_top.INST_myElevator.PORT_EN_floor_2_down_request = (tUInt8)0u;
	 INST_top.INST_myElevator.DEF_WILL_FIRE_floor_2_down_request = (tUInt8)0u;
	 INST_top.INST_myElevator.PORT_EN_floor_0_des_request = (tUInt8)0u;
	 INST_top.INST_myElevator.DEF_WILL_FIRE_floor_0_des_request = (tUInt8)0u;
	 INST_top.INST_myElevator.PORT_EN_floor_1_up_request = (tUInt8)0u;
	 INST_top.INST_myElevator.DEF_WILL_FIRE_floor_1_up_request = (tUInt8)0u;
	 INST_top.INST_myElevator.PORT_EN_setCurrentFloor = (tUInt8)0u;
	 INST_top.INST_myElevator.DEF_WILL_FIRE_setCurrentFloor = (tUInt8)0u;
	 DEF_INST_top_DEF_update___d6 = INST_top.INST_update.METH_read();
	 DEF_INST_top_DEF_NOT_update___d7 = !DEF_INST_top_DEF_update___d6;
	 INST_top.DEF_b__h388 = INST_top.INST_realFloor.METH_read();
	 DEF_INST_top_DEF_b__h395 = INST_top.INST_step.METH_read();
	 DEF_INST_top_DEF_moving__h1425 = INST_top.INST_moving.METH_read();
	 DEF_INST_top_DEF_realFloor_EQ_0___d2 = (INST_top.DEF_b__h388) == 0u;
	 DEF_INST_top_DEF_realFloor_EQ_0_AND_moving_2___d20 = DEF_INST_top_DEF_realFloor_EQ_0___d2 && DEF_INST_top_DEF_moving__h1425;
	 INST_top.DEF_CAN_FIRE_RL_finish = (DEF_INST_top_DEF_realFloor_EQ_0_AND_moving_2___d20 && DEF_INST_top_DEF_b__h395 == 4u) && DEF_INST_top_DEF_NOT_update___d7;
	 INST_top.DEF_WILL_FIRE_RL_finish = INST_top.DEF_CAN_FIRE_RL_finish;
	 INST_top.INST_myElevator.METH_RDY_setCurrentFloor();
	 DEF_INST_top_DEF_direction__h1431 = INST_top.INST_direction.METH_read();
	 DEF_INST_top_DEF_NOT_moving_2___d37 = !DEF_INST_top_DEF_moving__h1425;
	 INST_top.DEF_CAN_FIRE_RL_move_down = ((DEF_INST_top_DEF_NOT_moving_2___d37 && DEF_INST_top_DEF_direction__h1431) && !primSLE8(1u,
																       32u,
																       (tUInt32)(INST_top.DEF_b__h388),
																       32u,
																       0u)) && DEF_INST_top_DEF_NOT_update___d7;
	 INST_top.DEF_WILL_FIRE_RL_move_down = INST_top.DEF_CAN_FIRE_RL_move_down;
	 INST_top.DEF_CAN_FIRE_RL_set_floor = DEF_INST_top_DEF_update___d6;
	 INST_top.DEF_WILL_FIRE_RL_set_floor = INST_top.DEF_CAN_FIRE_RL_set_floor;
	 INST_top.DEF_CAN_FIRE_RL_start = (DEF_INST_top_DEF_realFloor_EQ_0___d2 && DEF_INST_top_DEF_b__h395 == 0u) && DEF_INST_top_DEF_NOT_update___d7;
	 INST_top.DEF_WILL_FIRE_RL_start = INST_top.DEF_CAN_FIRE_RL_start;
	 INST_top.DEF_CAN_FIRE_RL_move_up = ((DEF_INST_top_DEF_NOT_moving_2___d37 && !DEF_INST_top_DEF_direction__h1431) && primSLT8(1u,
																     32u,
																     (tUInt32)(INST_top.DEF_b__h388),
																     32u,
																     10u)) && DEF_INST_top_DEF_NOT_update___d7;
	 INST_top.DEF_WILL_FIRE_RL_move_up = INST_top.DEF_CAN_FIRE_RL_move_up && !(INST_top.DEF_WILL_FIRE_RL_start);
	 INST_top.INST_myElevator.METH_RDY_floor_2_down_request();
	 INST_top.DEF_CAN_FIRE_RL_step_1 = ((DEF_INST_top_DEF_realFloor_EQ_0___d2 && DEF_INST_top_DEF_b__h395 == 4294967295u) && DEF_INST_top_DEF_NOT_update___d7) && DEF_INST_top_DEF_moving__h1425;
	 INST_top.DEF_WILL_FIRE_RL_step_1 = INST_top.DEF_CAN_FIRE_RL_step_1;
	 INST_top.DEF_CAN_FIRE_RL_step_3 = (DEF_INST_top_DEF_realFloor_EQ_0_AND_moving_2___d20 && DEF_INST_top_DEF_b__h395 == 2u) && DEF_INST_top_DEF_NOT_update___d7;
	 INST_top.DEF_WILL_FIRE_RL_step_3 = INST_top.DEF_CAN_FIRE_RL_step_3;
	 INST_top.INST_myElevator.METH_RDY_floor_0_des_request();
	 INST_top.INST_myElevator.METH_RDY_floor_1_up_request();
	 INST_top.DEF_CAN_FIRE_RL_step_2 = (((INST_top.DEF_b__h388) == 2u && DEF_INST_top_DEF_moving__h1425) && DEF_INST_top_DEF_b__h395 == 1u) && DEF_INST_top_DEF_NOT_update___d7;
	 INST_top.DEF_WILL_FIRE_RL_step_2 = INST_top.DEF_CAN_FIRE_RL_step_2;
	 INST_top.DEF_CAN_FIRE_RL_step_4 = (((INST_top.DEF_b__h388) == 1u && DEF_INST_top_DEF_moving__h1425) && DEF_INST_top_DEF_b__h395 == 3u) && DEF_INST_top_DEF_NOT_update___d7;
	 INST_top.DEF_WILL_FIRE_RL_step_4 = INST_top.DEF_CAN_FIRE_RL_step_4;
	 INST_top.DEF_CAN_FIRE_RL_check_stop = DEF_INST_top_DEF_moving__h1425 && DEF_INST_top_DEF_NOT_update___d7;
	 INST_top.DEF_WILL_FIRE_RL_check_stop = ((((INST_top.DEF_CAN_FIRE_RL_check_stop && !(INST_top.DEF_WILL_FIRE_RL_step_4)) && !(INST_top.DEF_WILL_FIRE_RL_step_3)) && !(INST_top.DEF_WILL_FIRE_RL_step_2)) && !(INST_top.DEF_WILL_FIRE_RL_step_1)) && !(INST_top.DEF_WILL_FIRE_RL_start);
	 INST_top.DEF_CAN_FIRE_RL_nothing = DEF_INST_top_DEF_NOT_update___d7;
	 INST_top.DEF_WILL_FIRE_RL_nothing = (((((((INST_top.DEF_CAN_FIRE_RL_nothing && !(INST_top.DEF_WILL_FIRE_RL_move_down)) && !(INST_top.DEF_WILL_FIRE_RL_check_stop)) && !(INST_top.DEF_WILL_FIRE_RL_move_up)) && !(INST_top.DEF_WILL_FIRE_RL_step_4)) && !(INST_top.DEF_WILL_FIRE_RL_step_3)) && !(INST_top.DEF_WILL_FIRE_RL_step_2)) && !(INST_top.DEF_WILL_FIRE_RL_step_1)) && !(INST_top.DEF_WILL_FIRE_RL_start);
	 DEF_INST_top_DEF_setFloor__h1021 = INST_top.INST_setFloor.METH_read();
	 INST_top.DEF_CAN_FIRE_RL_update_state = DEF_INST_top_DEF_update___d6 && !DEF_INST_top_DEF_setFloor__h1021;
	 INST_top.DEF_WILL_FIRE_RL_update_state = INST_top.DEF_CAN_FIRE_RL_update_state;
	 INST_top.INST_myElevator.DEF_x__h10658 = INST_top.INST_myElevator.INST_currentFloor.METH_read();
	 INST_top.INST_myElevator.DEF_floor_des__h1624 = INST_top.INST_myElevator.INST_floor_des.METH_read();
	 INST_top.INST_myElevator.DEF_floor_des_BIT_0___h1625 = (tUInt8)((tUInt8)1u & (INST_top.INST_myElevator.DEF_floor_des__h1624));
	 INST_top.INST_myElevator.DEF_floor_des_BIT_1___h1547 = (tUInt8)((tUInt8)1u & ((INST_top.INST_myElevator.DEF_floor_des__h1624) >> 1u));
	 INST_top.INST_myElevator.DEF_floor_des_BIT_2___h1392 = (tUInt8)((INST_top.INST_myElevator.DEF_floor_des__h1624) >> 2u);
	 INST_top.INST_myElevator.DEF_floor_down_pressed__h7759 = INST_top.INST_myElevator.INST_floor_down_pressed.METH_read();
	 INST_top.INST_myElevator.DEF_floor_down_pressed_BIT_1___h1584 = (tUInt8)((tUInt8)1u & ((INST_top.INST_myElevator.DEF_floor_down_pressed__h7759) >> 1u));
	 INST_top.INST_myElevator.DEF_floor_down_pressed_BIT_2___h1506 = (tUInt8)((INST_top.INST_myElevator.DEF_floor_down_pressed__h7759) >> 2u);
	 DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_2_OR_floor_down_pressed_BIT_2_0___d11 = INST_top.INST_myElevator.DEF_floor_des_BIT_2___h1392 || INST_top.INST_myElevator.DEF_floor_down_pressed_BIT_2___h1506;
	 DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_1_2_OR_floor_down_pressed_BIT_1_3___d14 = INST_top.INST_myElevator.DEF_floor_des_BIT_1___h1547 || INST_top.INST_myElevator.DEF_floor_down_pressed_BIT_1___h1584;
	 INST_top.INST_myElevator.DEF_floor_up_pressed__h7356 = INST_top.INST_myElevator.INST_floor_up_pressed.METH_read();
	 INST_top.INST_myElevator.DEF_floor_up_pressed_BIT_0___h1739 = (tUInt8)((tUInt8)1u & (INST_top.INST_myElevator.DEF_floor_up_pressed__h7356));
	 INST_top.INST_myElevator.DEF_floor_up_pressed_BIT_1___h1780 = (tUInt8)((tUInt8)1u & ((INST_top.INST_myElevator.DEF_floor_up_pressed__h7356) >> 1u));
	 DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_1_2_OR_floor_up_pressed_6_BIT_1_9___d30 = INST_top.INST_myElevator.DEF_floor_des_BIT_1___h1547 || INST_top.INST_myElevator.DEF_floor_up_pressed_BIT_1___h1780;
	 DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_0_5_OR_floor_up_pressed_6_BIT_0_7___d18 = INST_top.INST_myElevator.DEF_floor_des_BIT_0___h1625 || INST_top.INST_myElevator.DEF_floor_up_pressed_BIT_0___h1739;
	 INST_top.INST_myElevator.DEF_moving_reg__h10758 = INST_top.INST_myElevator.INST_moving_reg.METH_read();
	 INST_top.INST_myElevator.DEF_direction_reg__h12570 = INST_top.INST_myElevator.INST_direction_reg.METH_read();
	 switch (INST_top.INST_myElevator.DEF_x__h10658) {
	 case 2u:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_floor_des_BIT_2_O_ETC___d28 = DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_2_OR_floor_down_pressed_BIT_2_0___d11 ? 2u : (DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_1_2_OR_floor_down_pressed_BIT_1_3___d14 ? 1u : (DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_0_5_OR_floor_up_pressed_6_BIT_0_7___d18 ? 0u : (INST_top.INST_myElevator.DEF_floor_up_pressed_BIT_1___h1780 ? 1u : 2u)));
	   break;
	 case 1u:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_floor_des_BIT_2_O_ETC___d28 = DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_1_2_OR_floor_down_pressed_BIT_1_3___d14 ? 1u : (DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_0_5_OR_floor_up_pressed_6_BIT_0_7___d18 ? 0u : 1u);
	   break;
	 default:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_floor_des_BIT_2_O_ETC___d28 = 0u;
	 }
	 switch (INST_top.INST_myElevator.DEF_x__h10658) {
	 case 0u:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_floor_des_BIT_0_ETC___d38 = DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_0_5_OR_floor_up_pressed_6_BIT_0_7___d18 ? 0u : (DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_1_2_OR_floor_up_pressed_6_BIT_1_9___d30 ? 1u : (DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_2_OR_floor_down_pressed_BIT_2_0___d11 ? 2u : (INST_top.INST_myElevator.DEF_floor_down_pressed_BIT_1___h1584 ? 1u : 0u)));
	   break;
	 case 1u:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_floor_des_BIT_0_ETC___d38 = DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_1_2_OR_floor_up_pressed_6_BIT_1_9___d30 ? 1u : (DEF_INST_top_INST_myElevator_DEF_floor_des_BIT_2_OR_floor_down_pressed_BIT_2_0___d11 ? 2u : 1u);
	   break;
	 default:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_floor_des_BIT_0_ETC___d38 = 2u;
	 }
	 switch (INST_top.INST_myElevator.DEF_x__h10658) {
	 case 2u:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_currentFloor_EQ_2_ETC___d42 = DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_floor_des_BIT_2_O_ETC___d28;
	   break;
	 case 1u:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_currentFloor_EQ_2_ETC___d42 = INST_top.INST_myElevator.DEF_floor_down_pressed_BIT_2___h1506 ? DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_floor_des_BIT_0_ETC___d38 : DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_floor_des_BIT_2_O_ETC___d28;
	   break;
	 case 0u:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_currentFloor_EQ_2_ETC___d42 = DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_floor_des_BIT_0_ETC___d38;
	   break;
	 default:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_currentFloor_EQ_2_ETC___d42 = INST_top.INST_myElevator.DEF_x__h10658;
	 }
	 switch (INST_top.INST_myElevator.DEF_x__h10658) {
	 case 0u:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_currentFloor_EQ_ETC___d47 = DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_floor_des_BIT_0_ETC___d38;
	   break;
	 case 1u:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_currentFloor_EQ_ETC___d47 = INST_top.INST_myElevator.DEF_floor_up_pressed_BIT_0___h1739 || INST_top.INST_myElevator.DEF_floor_des_BIT_0___h1625 ? DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_floor_des_BIT_2_O_ETC___d28 : DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_floor_des_BIT_0_ETC___d38;
	   break;
	 case 2u:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_currentFloor_EQ_ETC___d47 = DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_floor_des_BIT_2_O_ETC___d28;
	   break;
	 default:
	   DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_currentFloor_EQ_ETC___d47 = INST_top.INST_myElevator.DEF_x__h10658;
	 }
	 DEF_INST_top_INST_myElevator_DEF_IF_direction_reg_THEN_IF_currentFloor_EQ_2_THE_ETC___d48 = INST_top.INST_myElevator.DEF_direction_reg__h12570 ? DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_2_THEN_IF_currentFloor_EQ_2_ETC___d42 : DEF_INST_top_INST_myElevator_DEF_IF_currentFloor_EQ_0_9_THEN_IF_currentFloor_EQ_ETC___d47;
	 INST_top.INST_myElevator.DEF_CAN_FIRE_RL_goingDown = (INST_top.INST_myElevator.DEF_direction_reg__h12570 && INST_top.INST_myElevator.DEF_moving_reg__h10758) && primSLT8(1u,
																						  32u,
																						  (tUInt32)(DEF_INST_top_INST_myElevator_DEF_IF_direction_reg_THEN_IF_currentFloor_EQ_2_THE_ETC___d48),
																						  32u,
																						  (tUInt32)(INST_top.INST_myElevator.DEF_x__h10658));
	 INST_top.INST_myElevator.DEF_WILL_FIRE_RL_goingDown = INST_top.INST_myElevator.DEF_CAN_FIRE_RL_goingDown;
	 INST_top.INST_myElevator.DEF_NOT_direction_reg___d2 = !(INST_top.INST_myElevator.DEF_direction_reg__h12570);
	 INST_top.INST_myElevator.DEF_CAN_FIRE_RL_goingUp = (INST_top.INST_myElevator.DEF_NOT_direction_reg___d2 && INST_top.INST_myElevator.DEF_moving_reg__h10758) && !primSLE8(1u,
																						  32u,
																						  (tUInt32)(DEF_INST_top_INST_myElevator_DEF_IF_direction_reg_THEN_IF_currentFloor_EQ_2_THE_ETC___d48),
																						  32u,
																						  (tUInt32)(INST_top.INST_myElevator.DEF_x__h10658));
	 INST_top.INST_myElevator.DEF_WILL_FIRE_RL_goingUp = INST_top.INST_myElevator.DEF_CAN_FIRE_RL_goingUp;
	 DEF_INST_top_INST_myElevator_DEF_IF_direction_reg_THEN_IF_currentFloor_EQ_2_THE_ETC___d57 = DEF_INST_top_INST_myElevator_DEF_IF_direction_reg_THEN_IF_currentFloor_EQ_2_THE_ETC___d48 == (INST_top.INST_myElevator.DEF_x__h10658);
	 INST_top.INST_myElevator.DEF_CAN_FIRE_RL_changeDirection = INST_top.INST_myElevator.DEF_moving_reg__h10758 && !DEF_INST_top_INST_myElevator_DEF_IF_direction_reg_THEN_IF_currentFloor_EQ_2_THE_ETC___d57;
	 INST_top.INST_myElevator.DEF_WILL_FIRE_RL_changeDirection = (INST_top.INST_myElevator.DEF_CAN_FIRE_RL_changeDirection && !(INST_top.INST_myElevator.DEF_WILL_FIRE_RL_goingDown)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_RL_goingUp);
	 if (INST_top.DEF_WILL_FIRE_RL_finish)
	   INST_top.RL_finish();
	 if (INST_top.DEF_WILL_FIRE_RL_check_stop)
	   INST_top.RL_check_stop();
	 if (INST_top.DEF_WILL_FIRE_RL_nothing)
	   INST_top.RL_nothing();
	 if (INST_top.DEF_WILL_FIRE_RL_step_3)
	   INST_top.RL_step_3();
	 if (INST_top.DEF_WILL_FIRE_RL_update_state)
	   INST_top.RL_update_state();
	 if (INST_top.INST_myElevator.DEF_WILL_FIRE_RL_changeDirection)
	   INST_top.INST_myElevator.RL_changeDirection();
	 if (INST_top.INST_myElevator.DEF_WILL_FIRE_RL_goingDown)
	   INST_top.INST_myElevator.RL_goingDown();
	 if (INST_top.INST_myElevator.DEF_WILL_FIRE_RL_goingUp)
	   INST_top.INST_myElevator.RL_goingUp();
	 if (INST_top.DEF_WILL_FIRE_RL_step_1)
	   INST_top.RL_step_1();
	 if (INST_top.DEF_WILL_FIRE_RL_step_2)
	   INST_top.RL_step_2();
	 if (INST_top.DEF_WILL_FIRE_RL_step_4)
	   INST_top.RL_step_4();
	 INST_top.INST_myElevator.DEF_WILL_FIRE_floor_2_des_request = INST_top.INST_myElevator.PORT_EN_floor_2_des_request;
	 INST_top.INST_myElevator.DEF_WILL_FIRE_floor_1_des_request = INST_top.INST_myElevator.PORT_EN_floor_1_des_request;
	 INST_top.INST_myElevator.DEF_WILL_FIRE_floor_0_des_request = INST_top.INST_myElevator.PORT_EN_floor_0_des_request;
	 INST_top.INST_myElevator.DEF_WILL_FIRE_floor_2_down_request = INST_top.INST_myElevator.PORT_EN_floor_2_down_request;
	 INST_top.INST_myElevator.DEF_WILL_FIRE_floor_1_down_request = INST_top.INST_myElevator.PORT_EN_floor_1_down_request;
	 INST_top.INST_myElevator.DEF_WILL_FIRE_floor_1_up_request = INST_top.INST_myElevator.PORT_EN_floor_1_up_request;
	 INST_top.INST_myElevator.DEF_WILL_FIRE_floor_0_up_request = INST_top.INST_myElevator.PORT_EN_floor_0_up_request;
	 DEF_INST_top_INST_myElevator_DEF_NOT_moving_reg___d55 = !(INST_top.INST_myElevator.DEF_moving_reg__h10758);
	 INST_top.INST_myElevator.DEF_CAN_FIRE_RL_stopGoingDown = ((INST_top.INST_myElevator.DEF_direction_reg__h12570 && DEF_INST_top_INST_myElevator_DEF_NOT_moving_reg___d55) && DEF_INST_top_INST_myElevator_DEF_IF_direction_reg_THEN_IF_currentFloor_EQ_2_THE_ETC___d57) && !((INST_top.INST_myElevator.DEF_CAN_FIRE_RL_goingDown || INST_top.INST_myElevator.DEF_CAN_FIRE_RL_changeDirection) || INST_top.INST_myElevator.DEF_CAN_FIRE_RL_goingUp);
	 INST_top.INST_myElevator.DEF_WILL_FIRE_RL_stopGoingDown = ((((((INST_top.INST_myElevator.DEF_CAN_FIRE_RL_stopGoingDown && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_2_des_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_1_des_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_0_des_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_2_down_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_1_down_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_1_up_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_0_up_request);
	 INST_top.INST_myElevator.DEF_CAN_FIRE_RL_stopGoingUp = ((INST_top.INST_myElevator.DEF_NOT_direction_reg___d2 && DEF_INST_top_INST_myElevator_DEF_NOT_moving_reg___d55) && DEF_INST_top_INST_myElevator_DEF_IF_direction_reg_THEN_IF_currentFloor_EQ_2_THE_ETC___d57) && !((INST_top.INST_myElevator.DEF_CAN_FIRE_RL_goingDown || INST_top.INST_myElevator.DEF_CAN_FIRE_RL_changeDirection) || INST_top.INST_myElevator.DEF_CAN_FIRE_RL_goingUp);
	 INST_top.INST_myElevator.DEF_WILL_FIRE_RL_stopGoingUp = ((((((INST_top.INST_myElevator.DEF_CAN_FIRE_RL_stopGoingUp && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_2_des_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_1_des_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_0_des_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_2_down_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_1_down_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_1_up_request)) && !(INST_top.INST_myElevator.DEF_WILL_FIRE_floor_0_up_request);
	 if (INST_top.INST_myElevator.DEF_WILL_FIRE_RL_stopGoingDown)
	   INST_top.INST_myElevator.RL_stopGoingDown();
	 if (INST_top.INST_myElevator.DEF_WILL_FIRE_RL_stopGoingUp)
	   INST_top.INST_myElevator.RL_stopGoingUp();
	 if (INST_top.DEF_WILL_FIRE_RL_move_down)
	   INST_top.RL_move_down();
	 if (INST_top.DEF_WILL_FIRE_RL_move_up)
	   INST_top.RL_move_up();
	 if (INST_top.DEF_WILL_FIRE_RL_set_floor)
	   INST_top.RL_set_floor();
	 if (INST_top.DEF_WILL_FIRE_RL_start)
	   INST_top.RL_start();
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_myElevator.INST_floor_up_pressed.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_myElevator.INST_floor_down_pressed.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_myElevator.INST_floor_des.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_myElevator.INST_currentFloor.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_myElevator.INST_direction_reg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_myElevator.INST_moving_reg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_realFloor.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_step.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_moving.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_direction.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_update.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_setFloor.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_move_up_timer.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_move_down_timer.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_trace_step.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkRules::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkRules_instance = new MOD_mkRules(sim_hdl, "top", NULL);
  bk_get_or_define_clock(sim_hdl, "CLK");
  if (master)
  {
    bk_alter_clock(sim_hdl, bk_get_clock_by_name(sim_hdl, "CLK"), CLK_LOW, false, 0llu, 5llu, 5llu);
    bk_use_default_reset(sim_hdl);
  }
  bk_set_clock_event_fn(sim_hdl,
			bk_get_clock_by_name(sim_hdl, "CLK"),
			schedule_posedge_CLK,
			NULL,
			(tEdgeDirection)(POSEDGE));
  (mkRules_instance->INST_myElevator.set_clk_0)("CLK");
  (mkRules_instance->set_clk_0)("CLK");
}
void MODEL_mkRules::destroy_model()
{
  delete mkRules_instance;
  mkRules_instance = NULL;
}
void MODEL_mkRules::reset_model(bool asserted)
{
  (mkRules_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkRules::get_instance()
{
  return mkRules_instance;
}

/* Fill in version numbers */
void MODEL_mkRules::get_version(unsigned int *year,
				unsigned int *month,
				char const **annotation,
				char const **build)
{
  *year = 2016u;
  *month = 7u;
  *annotation = "beta1";
  *build = "34806";
}

/* Get the model creation time */
time_t MODEL_mkRules::get_creation_time()
{
  
  /* Wed Mar  8 01:39:05 UTC 2017 */
  return 1488937145llu;
}

/* Control run-time licensing */
tUInt64 MODEL_mkRules::skip_license_check()
{
  return 0llu;
}

/* State dumping function */
void MODEL_mkRules::dump_state()
{
  (mkRules_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkRules & mkRules_backing(tSimStateHdl simHdl)
{
  static MOD_mkRules *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkRules(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkRules::dump_VCD_defs()
{
  (mkRules_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkRules::dump_VCD(tVCDDumpType dt)
{
  (mkRules_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkRules_backing(sim_hdl));
}
