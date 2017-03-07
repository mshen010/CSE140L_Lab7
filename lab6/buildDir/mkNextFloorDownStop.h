/*
 * Generated by Bluespec Compiler, version 2016.07.beta1 (build 34806, 2016-07-05)
 * 
 * On Mon Mar  6 22:44:25 PST 2017
 * 
 */

/* Generation options: */
#ifndef __mkNextFloorDownStop_h__
#define __mkNextFloorDownStop_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkNextFloorDownStop module */
class MOD_mkNextFloorDownStop : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_Wire<tUInt32> INST_currentFloor_ignore;
  MOD_Reg<tUInt8> INST_currentFloor_initialized;
  MOD_Wire<tUInt32> INST_currentFloor_zaz;
  MOD_Reg<tUInt32> INST_cycle;
  MOD_Wire<tUInt8> INST_floor_des_ignore;
  MOD_Reg<tUInt8> INST_floor_des_initialized;
  MOD_Wire<tUInt8> INST_floor_des_zaz;
  MOD_Wire<tUInt8> INST_floor_down_pressed_ignore;
  MOD_Reg<tUInt8> INST_floor_down_pressed_initialized;
  MOD_Wire<tUInt8> INST_floor_down_pressed_zaz;
  MOD_Wire<tUInt8> INST_floor_up_pressed_ignore;
  MOD_Reg<tUInt8> INST_floor_up_pressed_initialized;
  MOD_Wire<tUInt8> INST_floor_up_pressed_zaz;
 
 /* Constructor */
 public:
  MOD_mkNextFloorDownStop(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_IF_IF_2147483648_PLUS_IF_currentFloor_zaz_whas_ETC___d88;
  tUInt8 DEF_IF_floor_down_pressed_zaz_whas__2_THEN_floor_d_ETC___d67;
  tUInt8 DEF_IF_floor_des_zaz_whas__9_THEN_floor_des_zaz_wg_ETC___d51;
  tUInt8 DEF_IF_floor_des_zaz_whas__9_THEN_floor_des_zaz_wg_ETC___d47;
  tUInt8 DEF_IF_floor_down_pressed_zaz_whas__2_THEN_floor_d_ETC___d65;
  tUInt8 DEF_IF_floor_des_zaz_whas__9_THEN_floor_des_zaz_wg_ETC___d43;
  tUInt8 DEF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_zaz__ETC___d54;
  tUInt8 DEF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_zaz__ETC___d80;
  tUInt8 DEF_IF_IF_2147483648_PLUS_IF_currentFloor_zaz_whas_ETC___d58;
  tUInt8 DEF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_zaz__ETC___d71;
  tUInt8 DEF_IF_IF_2147483648_PLUS_IF_currentFloor_zaz_whas_ETC___d41;
  tUInt8 DEF_IF_IF_2147483648_PLUS_IF_currentFloor_zaz_whas_ETC___d45;
  tUInt8 DEF_IF_IF_2147483648_PLUS_IF_currentFloor_zaz_whas_ETC___d49;
  tUInt8 DEF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_zaz__ETC___d52;
  tUInt32 DEF_IF_IF_2147483648_PLUS_IF_currentFloor_zaz_whas_ETC___d40;
  tUInt32 DEF_x_wget__h3042;
  tUInt32 DEF_x__h3473;
  tUInt8 DEF_x_wget__h2171;
  tUInt8 DEF_x_wget__h1301;
  tUInt32 DEF_IF_2147483648_PLUS_IF_currentFloor_zaz_whas__5_ETC___d37;
  tUInt8 DEF__2147483648_PLUS_IF_currentFloor_zaz_whas__5_TH_ETC___d32;
  tUInt32 DEF_v__h3216;
  tUInt8 DEF_v__h1438;
  tUInt8 DEF_v__h2308;
  tUInt32 DEF_IF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_z_ETC___d73;
  tUInt32 DEF_IF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_z_ETC___d64;
  tUInt32 DEF_IF_2147483648_PLUS_IF_currentFloor_zaz_whas__5_ETC___d35;
  tUInt32 DEF_x__h3847;
  tUInt32 DEF_value__h3219;
  tUInt8 DEF_cycle_9_EQ_128___d31;
  tUInt8 DEF_cycle_9_EQ_0___d30;
  tUInt8 DEF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_zaz__ETC___d84;
  tUInt8 DEF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_zaz__ETC___d66;
  tUInt8 DEF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_zaz__ETC___d48;
  tUInt8 DEF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_zaz__ETC___d44;
  tUInt8 DEF_IF_IF_2147483648_PLUS_IF_currentFloor_zaz_whas_ETC___d69;
  tUInt8 DEF_IF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_z_ETC___d74;
  tUInt8 DEF_IF_IF_2147483648_PLUS_IF_currentFloor_zaz_whas_ETC___d59;
  tUInt8 DEF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_zaz__ETC___d50;
  tUInt8 DEF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_zaz__ETC___d42;
  tUInt8 DEF_NOT_IF_IF_2147483648_PLUS_IF_currentFloor_zaz__ETC___d46;
 
 /* Local definitions */
 private:
  tUInt32 DEF_new_value__h3178;
  tUInt32 DEF_v__h2228;
  tUInt32 DEF_v__h1358;
  tUInt32 DEF_v__h318;
  tUInt8 DEF_x_wget__h253;
  tUInt8 DEF_v__h399;
 
 /* Rules */
 public:
  void RL_floor_up_pressed_every();
  void RL_floor_up_pressed_every_1();
  void RL_floor_down_pressed_every();
  void RL_floor_down_pressed_every_1();
  void RL_floor_des_every();
  void RL_floor_des_every_1();
  void RL_currentFloor_every();
  void RL_currentFloor_every_1();
  void RL_test();
 
 /* Methods */
 public:
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkNextFloorDownStop &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkNextFloorDownStop &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkNextFloorDownStop &backing);
};

#endif /* ifndef __mkNextFloorDownStop_h__ */