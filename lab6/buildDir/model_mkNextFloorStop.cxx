/*
 * Generated by Bluespec Compiler, version 2016.07.beta1 (build 34806, 2016-07-05)
 * 
 * On Mon Mar  6 22:44:05 PST 2017
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkNextFloorStop.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkNextFloorStop::MODEL_mkNextFloorStop()
{
  mkNextFloorStop_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkNextFloorStop()
{
  MODEL_mkNextFloorStop *model = new MODEL_mkNextFloorStop();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkNextFloorStop &INST_top = *((MOD_mkNextFloorStop *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_NOT_nextTest_3___d54;
	 tUInt8 DEF_INST_top_DEF_NOT_nextTest_3_4_AND_up_pressed_5_BIT_0_6_OR_u_ETC___d75;
	 tUInt8 DEF_INST_top_DEF_nextTest___d53;
	 tUInt8 DEF_INST_top_DEF_floor_up_pressed_initialized__h402;
	 tUInt8 DEF_INST_top_DEF_floor_down_pressed_initialized__h2652;
	 tUInt8 DEF_INST_top_DEF_currentFloor_initialized__h4570;
	 tUInt8 DEF_INST_top_DEF_floor_up_des_initialized__h1555;
	 tUInt8 DEF_INST_top_DEF_floor_down_des_initialized__h3636;
	 tUInt8 DEF_INST_top_DEF_direction_initialized__h4976;
	 tUInt32 DEF_INST_top_DEF_b__h7908;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_des_every;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_des_every;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_des_every_1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_des_every_1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_des_every;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_des_every;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_des_every_1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_des_every_1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_direction_every;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_direction_every;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_direction_every_1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_direction_every_1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_upFloor;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_upFloor;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_go_to_next_stop;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_go_to_next_stop;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_finish;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_finish;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_reset_des;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_reset_des;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_pressed_every;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_pressed_every;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_pressed_every_1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_pressed_every_1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_pressed_every;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_pressed_every;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_pressed_every_1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_pressed_every_1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_currentFloor_every;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_currentFloor_every;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_currentFloor_every_1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_currentFloor_every_1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_test;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_test;
	 DEF_INST_top_DEF_CAN_FIRE_RL_currentFloor_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_currentFloor_every = DEF_INST_top_DEF_CAN_FIRE_RL_currentFloor_every;
	 DEF_INST_top_DEF_currentFloor_initialized__h4570 = INST_top.INST_currentFloor_initialized.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_currentFloor_every_1 = !DEF_INST_top_DEF_currentFloor_initialized__h4570;
	 DEF_INST_top_DEF_WILL_FIRE_RL_currentFloor_every_1 = DEF_INST_top_DEF_CAN_FIRE_RL_currentFloor_every_1;
	 DEF_INST_top_DEF_CAN_FIRE_RL_direction_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_direction_every = DEF_INST_top_DEF_CAN_FIRE_RL_direction_every;
	 DEF_INST_top_DEF_direction_initialized__h4976 = INST_top.INST_direction_initialized.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_direction_every_1 = !DEF_INST_top_DEF_direction_initialized__h4976;
	 DEF_INST_top_DEF_WILL_FIRE_RL_direction_every_1 = DEF_INST_top_DEF_CAN_FIRE_RL_direction_every_1;
	 INST_top.DEF_des__h7877 = INST_top.INST_des.METH_read();
	 INST_top.DEF_des_BIT_0___h7812 = (tUInt8)((tUInt8)1u & (INST_top.DEF_des__h7877));
	 INST_top.DEF_des_BIT_1___h7845 = (tUInt8)((tUInt8)1u & ((INST_top.DEF_des__h7877) >> 1u));
	 INST_top.DEF_des_BIT_2___h7878 = (tUInt8)((INST_top.DEF_des__h7877) >> 2u);
	 INST_top.DEF_down_pressed__h7604 = INST_top.INST_down_pressed.METH_read();
	 INST_top.DEF_down_pressed_BIT_2___h7605 = (tUInt8)((INST_top.DEF_down_pressed__h7604) >> 2u);
	 INST_top.DEF_down_pressed_BIT_1___h7572 = (tUInt8)((tUInt8)1u & ((INST_top.DEF_down_pressed__h7604) >> 1u));
	 INST_top.DEF_down_pressed_BIT_0___h7539 = (tUInt8)((tUInt8)1u & (INST_top.DEF_down_pressed__h7604));
	 INST_top.DEF_up_pressed__h7332 = INST_top.INST_up_pressed.METH_read();
	 INST_top.DEF_up_pressed_BIT_1___h7300 = (tUInt8)((tUInt8)1u & ((INST_top.DEF_up_pressed__h7332) >> 1u));
	 INST_top.DEF_up_pressed_BIT_0___h7267 = (tUInt8)((tUInt8)1u & (INST_top.DEF_up_pressed__h7332));
	 DEF_INST_top_DEF_nextTest___d53 = INST_top.INST_nextTest.METH_read();
	 INST_top.DEF_up_pressed_BIT_2___h7333 = (tUInt8)((INST_top.DEF_up_pressed__h7332) >> 2u);
	 INST_top.DEF_NOT_down_pressed_1_BIT_0_2___d145 = !(INST_top.DEF_down_pressed_BIT_0___h7539);
	 INST_top.DEF_NOT_down_pressed_1_BIT_1_3___d146 = !(INST_top.DEF_down_pressed_BIT_1___h7572);
	 INST_top.DEF_NOT_down_pressed_1_BIT_2_4___d147 = !(INST_top.DEF_down_pressed_BIT_2___h7605);
	 INST_top.DEF_NOT_up_pressed_5_BIT_0_6___d134 = !(INST_top.DEF_up_pressed_BIT_0___h7267);
	 INST_top.DEF_NOT_up_pressed_5_BIT_1_7___d135 = !(INST_top.DEF_up_pressed_BIT_1___h7300);
	 INST_top.DEF_NOT_up_pressed_5_BIT_2_8___d136 = !(INST_top.DEF_up_pressed_BIT_2___h7333);
	 INST_top.DEF_NOT_des_8_BIT_0_9___d129 = !(INST_top.DEF_des_BIT_0___h7812);
	 DEF_INST_top_DEF_NOT_nextTest_3___d54 = !DEF_INST_top_DEF_nextTest___d53;
	 INST_top.DEF_NOT_des_8_BIT_1_0___d130 = !(INST_top.DEF_des_BIT_1___h7845);
	 INST_top.DEF_NOT_des_8_BIT_2_1___d131 = !(INST_top.DEF_des_BIT_2___h7878);
	 DEF_INST_top_DEF_CAN_FIRE_RL_finish = DEF_INST_top_DEF_NOT_nextTest_3___d54 && (((INST_top.DEF_NOT_up_pressed_5_BIT_0_6___d134 && (INST_top.DEF_NOT_up_pressed_5_BIT_1_7___d135 && INST_top.DEF_NOT_up_pressed_5_BIT_2_8___d136)) && (INST_top.DEF_NOT_down_pressed_1_BIT_0_2___d145 && (INST_top.DEF_NOT_down_pressed_1_BIT_1_3___d146 && INST_top.DEF_NOT_down_pressed_1_BIT_2_4___d147))) && (INST_top.DEF_NOT_des_8_BIT_0_9___d129 && (INST_top.DEF_NOT_des_8_BIT_1_0___d130 && INST_top.DEF_NOT_des_8_BIT_2_1___d131)));
	 DEF_INST_top_DEF_WILL_FIRE_RL_finish = DEF_INST_top_DEF_CAN_FIRE_RL_finish;
	 DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_des_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_des_every = DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_des_every;
	 DEF_INST_top_DEF_floor_down_des_initialized__h3636 = INST_top.INST_floor_down_des_initialized.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_des_every_1 = !DEF_INST_top_DEF_floor_down_des_initialized__h3636;
	 DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_des_every_1 = DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_des_every_1;
	 DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_pressed_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_pressed_every = DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_pressed_every;
	 DEF_INST_top_DEF_floor_down_pressed_initialized__h2652 = INST_top.INST_floor_down_pressed_initialized.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_pressed_every_1 = !DEF_INST_top_DEF_floor_down_pressed_initialized__h2652;
	 DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_pressed_every_1 = DEF_INST_top_DEF_CAN_FIRE_RL_floor_down_pressed_every_1;
	 DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_des_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_des_every = DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_des_every;
	 DEF_INST_top_DEF_floor_up_des_initialized__h1555 = INST_top.INST_floor_up_des_initialized.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_des_every_1 = !DEF_INST_top_DEF_floor_up_des_initialized__h1555;
	 DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_des_every_1 = DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_des_every_1;
	 DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_pressed_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_pressed_every = DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_pressed_every;
	 DEF_INST_top_DEF_floor_up_pressed_initialized__h402 = INST_top.INST_floor_up_pressed_initialized.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_pressed_every_1 = !DEF_INST_top_DEF_floor_up_pressed_initialized__h402;
	 DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_pressed_every_1 = DEF_INST_top_DEF_CAN_FIRE_RL_floor_up_pressed_every_1;
	 DEF_INST_top_DEF_b__h7908 = INST_top.INST_phase.METH_read();
	 DEF_INST_top_DEF_NOT_nextTest_3_4_AND_up_pressed_5_BIT_0_6_OR_u_ETC___d75 = DEF_INST_top_DEF_NOT_nextTest_3___d54 && (((INST_top.DEF_up_pressed_BIT_0___h7267 || (INST_top.DEF_up_pressed_BIT_1___h7300 || INST_top.DEF_up_pressed_BIT_2___h7333)) || (INST_top.DEF_down_pressed_BIT_0___h7539 || (INST_top.DEF_down_pressed_BIT_1___h7572 || INST_top.DEF_down_pressed_BIT_2___h7605))) || (INST_top.DEF_des_BIT_0___h7812 || (INST_top.DEF_des_BIT_1___h7845 || INST_top.DEF_des_BIT_2___h7878)));
	 DEF_INST_top_DEF_CAN_FIRE_RL_go_to_next_stop = DEF_INST_top_DEF_NOT_nextTest_3_4_AND_up_pressed_5_BIT_0_6_OR_u_ETC___d75 && DEF_INST_top_DEF_b__h7908 == 1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_go_to_next_stop = DEF_INST_top_DEF_CAN_FIRE_RL_go_to_next_stop;
	 DEF_INST_top_DEF_CAN_FIRE_RL_reset_des = DEF_INST_top_DEF_NOT_nextTest_3___d54 && DEF_INST_top_DEF_b__h7908 == 2u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_reset_des = DEF_INST_top_DEF_CAN_FIRE_RL_reset_des && !DEF_INST_top_DEF_WILL_FIRE_RL_finish;
	 INST_top.DEF_x__h16571 = INST_top.INST_cycle.METH_read();
	 INST_top.DEF_display__h16267 = INST_top.INST_display.METH_read();
	 INST_top.DEF_cycle_23_EQ_128___d234 = (INST_top.DEF_x__h16571) == 128u;
	 INST_top.DEF_cycle_23_EQ_0___d233 = (INST_top.DEF_x__h16571) == 0u;
	 DEF_INST_top_DEF_CAN_FIRE_RL_test = (INST_top.DEF_cycle_23_EQ_0___d233 || (INST_top.DEF_cycle_23_EQ_128___d234 || (INST_top.DEF_display__h16267 || (DEF_INST_top_DEF_floor_up_pressed_initialized__h402 && (DEF_INST_top_DEF_floor_up_des_initialized__h1555 && (DEF_INST_top_DEF_floor_down_pressed_initialized__h2652 && (DEF_INST_top_DEF_floor_down_des_initialized__h3636 && (DEF_INST_top_DEF_currentFloor_initialized__h4570 && DEF_INST_top_DEF_direction_initialized__h4976)))))))) && DEF_INST_top_DEF_nextTest___d53;
	 DEF_INST_top_DEF_WILL_FIRE_RL_test = DEF_INST_top_DEF_CAN_FIRE_RL_test;
	 DEF_INST_top_DEF_CAN_FIRE_RL_upFloor = DEF_INST_top_DEF_NOT_nextTest_3_4_AND_up_pressed_5_BIT_0_6_OR_u_ETC___d75 && DEF_INST_top_DEF_b__h7908 == 0u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_upFloor = DEF_INST_top_DEF_CAN_FIRE_RL_upFloor;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_finish)
	   INST_top.RL_finish();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_go_to_next_stop)
	   INST_top.RL_go_to_next_stop();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_pressed_every)
	   INST_top.RL_floor_up_pressed_every();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_des_every)
	   INST_top.RL_floor_up_des_every();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_pressed_every)
	   INST_top.RL_floor_down_pressed_every();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_des_every)
	   INST_top.RL_floor_down_des_every();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_currentFloor_every)
	   INST_top.RL_currentFloor_every();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_currentFloor_every_1)
	   INST_top.RL_currentFloor_every_1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_direction_every)
	   INST_top.RL_direction_every();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_direction_every_1)
	   INST_top.RL_direction_every_1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_des_every_1)
	   INST_top.RL_floor_down_des_every_1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_floor_down_pressed_every_1)
	   INST_top.RL_floor_down_pressed_every_1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_des_every_1)
	   INST_top.RL_floor_up_des_every_1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_floor_up_pressed_every_1)
	   INST_top.RL_floor_up_pressed_every_1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_reset_des)
	   INST_top.RL_reset_des();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_test)
	   INST_top.RL_test();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_upFloor)
	   INST_top.RL_upFloor();
	 INST_top.INST_direction_zaz.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_direction_ignore.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_currentFloor_zaz.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_currentFloor_ignore.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_floor_down_des_zaz.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_floor_down_des_ignore.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_floor_down_pressed_zaz.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_floor_down_pressed_ignore.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_floor_up_des_zaz.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_floor_up_des_ignore.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_floor_up_pressed_zaz.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_floor_up_pressed_ignore.clk((tUInt8)1u, (tUInt8)1u);
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_cycle.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_floor_up_pressed_initialized.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_floor_up_des_initialized.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_floor_down_pressed_initialized.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_floor_down_des_initialized.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_currentFloor_initialized.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_direction_initialized.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_nextTest.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_up_pressed.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_up_des.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_down_pressed.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_down_des.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_des.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_current.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_c_direction.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_reset_des_reg.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_display.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_up_floor.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_phase.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_tle.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkNextFloorStop::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkNextFloorStop_instance = new MOD_mkNextFloorStop(sim_hdl, "top", NULL);
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
  (mkNextFloorStop_instance->INST_floor_up_pressed_ignore.set_clk_0)("CLK");
  (mkNextFloorStop_instance->INST_floor_up_pressed_zaz.set_clk_0)("CLK");
  (mkNextFloorStop_instance->INST_floor_up_des_ignore.set_clk_0)("CLK");
  (mkNextFloorStop_instance->INST_floor_up_des_zaz.set_clk_0)("CLK");
  (mkNextFloorStop_instance->INST_floor_down_pressed_ignore.set_clk_0)("CLK");
  (mkNextFloorStop_instance->INST_floor_down_pressed_zaz.set_clk_0)("CLK");
  (mkNextFloorStop_instance->INST_floor_down_des_ignore.set_clk_0)("CLK");
  (mkNextFloorStop_instance->INST_floor_down_des_zaz.set_clk_0)("CLK");
  (mkNextFloorStop_instance->INST_currentFloor_ignore.set_clk_0)("CLK");
  (mkNextFloorStop_instance->INST_currentFloor_zaz.set_clk_0)("CLK");
  (mkNextFloorStop_instance->INST_direction_ignore.set_clk_0)("CLK");
  (mkNextFloorStop_instance->INST_direction_zaz.set_clk_0)("CLK");
  (mkNextFloorStop_instance->set_clk_0)("CLK");
}
void MODEL_mkNextFloorStop::destroy_model()
{
  delete mkNextFloorStop_instance;
  mkNextFloorStop_instance = NULL;
}
void MODEL_mkNextFloorStop::reset_model(bool asserted)
{
  (mkNextFloorStop_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkNextFloorStop::get_instance()
{
  return mkNextFloorStop_instance;
}

/* Fill in version numbers */
void MODEL_mkNextFloorStop::get_version(unsigned int *year,
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
time_t MODEL_mkNextFloorStop::get_creation_time()
{
  
  /* Tue Mar  7 06:44:05 UTC 2017 */
  return 1488869045llu;
}

/* Control run-time licensing */
tUInt64 MODEL_mkNextFloorStop::skip_license_check()
{
  return 0llu;
}

/* State dumping function */
void MODEL_mkNextFloorStop::dump_state()
{
  (mkNextFloorStop_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkNextFloorStop & mkNextFloorStop_backing(tSimStateHdl simHdl)
{
  static MOD_mkNextFloorStop *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkNextFloorStop(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkNextFloorStop::dump_VCD_defs()
{
  (mkNextFloorStop_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkNextFloorStop::dump_VCD(tVCDDumpType dt)
{
  (mkNextFloorStop_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkNextFloorStop_backing(sim_hdl));
}