/*
 * Generated by Bluespec Compiler, version 2016.07.beta1 (build 34806, 2016-07-05)
 * 
 * On Thu Mar  9 21:05:03 PST 2017
 * 
 */
#include "bluesim_primitives.h"
#include "mkTbNextFloor.h"
#include "imported_BDPI_functions.h"


/* Constructor */
MOD_mkTbNextFloor::MOD_mkTbNextFloor(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_currentFloor_ignore(simHdl, "currentFloor_ignore", this, 32u, (tUInt8)0u),
    INST_currentFloor_initialized(simHdl, "currentFloor_initialized", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_currentFloor_zaz(simHdl, "currentFloor_zaz", this, 32u, (tUInt8)0u),
    INST_cycle(simHdl, "cycle", this, 32u, 0u, (tUInt8)0u),
    INST_direction_ignore(simHdl, "direction_ignore", this, 1u, (tUInt8)0u),
    INST_direction_initialized(simHdl, "direction_initialized", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_direction_zaz(simHdl, "direction_zaz", this, 1u, (tUInt8)0u),
    INST_floor_des_ignore(simHdl, "floor_des_ignore", this, 3u, (tUInt8)0u),
    INST_floor_des_initialized(simHdl, "floor_des_initialized", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_floor_des_zaz(simHdl, "floor_des_zaz", this, 3u, (tUInt8)0u),
    INST_floor_down_pressed_ignore(simHdl, "floor_down_pressed_ignore", this, 3u, (tUInt8)0u),
    INST_floor_down_pressed_initialized(simHdl,
					"floor_down_pressed_initialized",
					this,
					1u,
					(tUInt8)0u,
					(tUInt8)0u),
    INST_floor_down_pressed_zaz(simHdl, "floor_down_pressed_zaz", this, 3u, (tUInt8)0u),
    INST_floor_up_pressed_ignore(simHdl, "floor_up_pressed_ignore", this, 3u, (tUInt8)0u),
    INST_floor_up_pressed_initialized(simHdl,
				      "floor_up_pressed_initialized",
				      this,
				      1u,
				      (tUInt8)0u,
				      (tUInt8)0u),
    INST_floor_up_pressed_zaz(simHdl, "floor_up_pressed_zaz", this, 3u, (tUInt8)0u),
    INST_outFIFO(simHdl, "outFIFO", this, 42u, 2u, 1u, 0u),
    PORT_RST_N((tUInt8)1u),
    DEF_v__h3556(2863311530u),
    DEF_new_value__h3175(2863311530u),
    DEF_v__h2224(2863311530u),
    DEF_v__h1354(2863311530u),
    DEF_v__h314(2863311530u)
{
  symbol_count = 29u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTbNextFloor::init_symbols_0()
{
  init_symbol(&symbols[0u], "currentFloor_ignore", SYM_MODULE, &INST_currentFloor_ignore);
  init_symbol(&symbols[1u], "currentFloor_initialized", SYM_MODULE, &INST_currentFloor_initialized);
  init_symbol(&symbols[2u], "currentFloor_zaz", SYM_MODULE, &INST_currentFloor_zaz);
  init_symbol(&symbols[3u], "cycle", SYM_MODULE, &INST_cycle);
  init_symbol(&symbols[4u], "direction_ignore", SYM_MODULE, &INST_direction_ignore);
  init_symbol(&symbols[5u], "direction_initialized", SYM_MODULE, &INST_direction_initialized);
  init_symbol(&symbols[6u], "direction_zaz", SYM_MODULE, &INST_direction_zaz);
  init_symbol(&symbols[7u], "floor_des_ignore", SYM_MODULE, &INST_floor_des_ignore);
  init_symbol(&symbols[8u], "floor_des_initialized", SYM_MODULE, &INST_floor_des_initialized);
  init_symbol(&symbols[9u], "floor_des_zaz", SYM_MODULE, &INST_floor_des_zaz);
  init_symbol(&symbols[10u],
	      "floor_down_pressed_ignore",
	      SYM_MODULE,
	      &INST_floor_down_pressed_ignore);
  init_symbol(&symbols[11u],
	      "floor_down_pressed_initialized",
	      SYM_MODULE,
	      &INST_floor_down_pressed_initialized);
  init_symbol(&symbols[12u], "floor_down_pressed_zaz", SYM_MODULE, &INST_floor_down_pressed_zaz);
  init_symbol(&symbols[13u], "floor_up_pressed_ignore", SYM_MODULE, &INST_floor_up_pressed_ignore);
  init_symbol(&symbols[14u],
	      "floor_up_pressed_initialized",
	      SYM_MODULE,
	      &INST_floor_up_pressed_initialized);
  init_symbol(&symbols[15u], "floor_up_pressed_zaz", SYM_MODULE, &INST_floor_up_pressed_zaz);
  init_symbol(&symbols[16u], "outFIFO", SYM_MODULE, &INST_outFIFO);
  init_symbol(&symbols[17u], "RL_currentFloor_every", SYM_RULE);
  init_symbol(&symbols[18u], "RL_currentFloor_every_1", SYM_RULE);
  init_symbol(&symbols[19u], "RL_direction_every", SYM_RULE);
  init_symbol(&symbols[20u], "RL_direction_every_1", SYM_RULE);
  init_symbol(&symbols[21u], "RL_floor_des_every", SYM_RULE);
  init_symbol(&symbols[22u], "RL_floor_des_every_1", SYM_RULE);
  init_symbol(&symbols[23u], "RL_floor_down_pressed_every", SYM_RULE);
  init_symbol(&symbols[24u], "RL_floor_down_pressed_every_1", SYM_RULE);
  init_symbol(&symbols[25u], "RL_floor_up_pressed_every", SYM_RULE);
  init_symbol(&symbols[26u], "RL_floor_up_pressed_every_1", SYM_RULE);
  init_symbol(&symbols[27u], "RL_test", SYM_RULE);
  init_symbol(&symbols[28u], "x__h3971", SYM_DEF, &DEF_x__h3971, 32u);
}


/* Rule actions */

void MOD_mkTbNextFloor::RL_floor_up_pressed_every()
{
  tUInt8 DEF_new_value__h356;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h314 = rand32();
  DEF_new_value__h356 = (tUInt8)((tUInt8)7u & DEF_v__h314);
  INST_floor_up_pressed_zaz.METH_wset(DEF_new_value__h356);
}

void MOD_mkTbNextFloor::RL_floor_up_pressed_every_1()
{
  DEF_x_wget__h249 = INST_floor_up_pressed_zaz.METH_wget();
  DEF_v__h395 = INST_floor_up_pressed_zaz.METH_whas() ? DEF_x_wget__h249 : (tUInt8)0u;
  INST_floor_up_pressed_ignore.METH_wset(DEF_v__h395);
}

void MOD_mkTbNextFloor::RL_floor_down_pressed_every()
{
  tUInt8 DEF_new_value__h1396;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h1354 = rand32();
  DEF_new_value__h1396 = (tUInt8)((tUInt8)7u & DEF_v__h1354);
  INST_floor_down_pressed_zaz.METH_wset(DEF_new_value__h1396);
}

void MOD_mkTbNextFloor::RL_floor_down_pressed_every_1()
{
  DEF_x_wget__h1297 = INST_floor_down_pressed_zaz.METH_wget();
  DEF_v__h1434 = INST_floor_down_pressed_zaz.METH_whas() ? DEF_x_wget__h1297 : (tUInt8)0u;
  INST_floor_down_pressed_ignore.METH_wset(DEF_v__h1434);
}

void MOD_mkTbNextFloor::RL_floor_des_every()
{
  tUInt8 DEF_new_value__h2266;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h2224 = rand32();
  DEF_new_value__h2266 = (tUInt8)((tUInt8)7u & DEF_v__h2224);
  INST_floor_des_zaz.METH_wset(DEF_new_value__h2266);
}

void MOD_mkTbNextFloor::RL_floor_des_every_1()
{
  DEF_x_wget__h2167 = INST_floor_des_zaz.METH_wget();
  DEF_v__h2304 = INST_floor_des_zaz.METH_whas() ? DEF_x_wget__h2167 : (tUInt8)0u;
  INST_floor_des_ignore.METH_wset(DEF_v__h2304);
}

void MOD_mkTbNextFloor::RL_currentFloor_every()
{
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    rand32();
    DEF_new_value__h3175 = rand32();
  }
  INST_currentFloor_zaz.METH_wset(DEF_new_value__h3175);
}

void MOD_mkTbNextFloor::RL_currentFloor_every_1()
{
  DEF_x_wget__h3039 = INST_currentFloor_zaz.METH_wget();
  DEF_value__h3216 = INST_currentFloor_zaz.METH_whas() ? DEF_x_wget__h3039 : 0u;
  DEF_v__h3213 = 2147483648u + DEF_value__h3216;
  INST_currentFloor_ignore.METH_wset(DEF_v__h3213);
}

void MOD_mkTbNextFloor::RL_direction_every()
{
  tUInt8 DEF_new_value__h3598;
  if (!(PORT_RST_N == (tUInt8)0u))
    DEF_v__h3556 = rand32();
  DEF_new_value__h3598 = (tUInt8)((tUInt8)1u & DEF_v__h3556);
  INST_direction_zaz.METH_wset(DEF_new_value__h3598);
}

void MOD_mkTbNextFloor::RL_direction_every_1()
{
  tUInt8 DEF_v__h3636;
  DEF_direction_zaz_whas____d33 = INST_direction_zaz.METH_whas();
  DEF_direction_zaz_wget____d34 = INST_direction_zaz.METH_wget();
  DEF_v__h3636 = DEF_direction_zaz_whas____d33 && DEF_direction_zaz_wget____d34;
  INST_direction_ignore.METH_wset(DEF_v__h3636);
}

void MOD_mkTbNextFloor::RL_test()
{
  tUInt32 DEF_x__h5593;
  tUInt8 DEF_NOT_cycle_6_EQ_0_7_7_AND_NOT_cycle_6_EQ_128_8_8___d49;
  tUInt64 DEF__0_CONCAT_IF_floor_up_pressed_zaz_whas_THEN_flo_ETC___d57;
  DEF_x_wget__h3039 = INST_currentFloor_zaz.METH_wget();
  DEF_x__h3971 = INST_cycle.METH_read();
  DEF_x_wget__h2167 = INST_floor_des_zaz.METH_wget();
  DEF_x_wget__h1297 = INST_floor_down_pressed_zaz.METH_wget();
  DEF_direction_zaz_whas____d33 = INST_direction_zaz.METH_whas();
  DEF_x_wget__h249 = INST_floor_up_pressed_zaz.METH_wget();
  DEF_direction_zaz_wget____d34 = INST_direction_zaz.METH_wget();
  DEF_v__h395 = INST_floor_up_pressed_zaz.METH_whas() ? DEF_x_wget__h249 : (tUInt8)0u;
  DEF_v__h1434 = INST_floor_down_pressed_zaz.METH_whas() ? DEF_x_wget__h1297 : (tUInt8)0u;
  DEF_value__h3216 = INST_currentFloor_zaz.METH_whas() ? DEF_x_wget__h3039 : 0u;
  DEF_cycle_6_EQ_128___d38 = DEF_x__h3971 == 128u;
  DEF_v__h2304 = INST_floor_des_zaz.METH_whas() ? DEF_x_wget__h2167 : (tUInt8)0u;
  DEF_cycle_6_EQ_0___d37 = DEF_x__h3971 == 0u;
  DEF_v__h3213 = 2147483648u + DEF_value__h3216;
  DEF__0_CONCAT_IF_floor_up_pressed_zaz_whas_THEN_flo_ETC___d57 = 4398046511103llu & (((((((((tUInt64)((tUInt8)0u)) << 41u) | (((tUInt64)((tUInt8)((tUInt8)3u & DEF_v__h395))) << 39u)) | (((tUInt64)((tUInt8)(DEF_v__h1434 >> 1u))) << 37u)) | (((tUInt64)((tUInt8)0u)) << 36u)) | (((tUInt64)(DEF_v__h2304)) << 33u)) | (((tUInt64)(DEF_v__h3213)) << 1u)) | (tUInt64)(!DEF_direction_zaz_whas____d33 || !DEF_direction_zaz_wget____d34));
  DEF_NOT_cycle_6_EQ_0_7_7_AND_NOT_cycle_6_EQ_128_8_8___d49 = !DEF_cycle_6_EQ_0___d37 && !DEF_cycle_6_EQ_128___d38;
  if (DEF_cycle_6_EQ_0___d37)
    INST_floor_up_pressed_initialized.METH_write((tUInt8)1u);
  DEF_x__h5593 = DEF_x__h3971 + 1u;
  if (DEF_cycle_6_EQ_0___d37)
    INST_floor_down_pressed_initialized.METH_write((tUInt8)1u);
  if (DEF_cycle_6_EQ_0___d37)
    INST_floor_des_initialized.METH_write((tUInt8)1u);
  if (DEF_cycle_6_EQ_0___d37)
    INST_currentFloor_initialized.METH_write((tUInt8)1u);
  if (DEF_cycle_6_EQ_0___d37)
    INST_direction_initialized.METH_write((tUInt8)1u);
  if (DEF_NOT_cycle_6_EQ_0_7_7_AND_NOT_cycle_6_EQ_128_8_8___d49)
    INST_outFIFO.METH_enq(DEF__0_CONCAT_IF_floor_up_pressed_zaz_whas_THEN_flo_ETC___d57);
  INST_cycle.METH_write(DEF_x__h5593);
}


/* Methods */

tUInt64 MOD_mkTbNextFloor::METH_getObj()
{
  tUInt64 DEF_outFIFO_first____d59;
  tUInt64 PORT_getObj;
  DEF_outFIFO_first____d59 = INST_outFIFO.METH_first();
  PORT_getObj = DEF_outFIFO_first____d59;
  INST_outFIFO.METH_deq();
  return PORT_getObj;
}

tUInt8 MOD_mkTbNextFloor::METH_RDY_getObj()
{
  tUInt8 DEF_CAN_FIRE_getObj;
  tUInt8 PORT_RDY_getObj;
  DEF_CAN_FIRE_getObj = INST_outFIFO.METH_i_notEmpty();
  PORT_RDY_getObj = DEF_CAN_FIRE_getObj;
  return PORT_RDY_getObj;
}


/* Reset routines */

void MOD_mkTbNextFloor::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_outFIFO.reset_RST(ARG_rst_in);
  INST_floor_up_pressed_initialized.reset_RST(ARG_rst_in);
  INST_floor_down_pressed_initialized.reset_RST(ARG_rst_in);
  INST_floor_des_initialized.reset_RST(ARG_rst_in);
  INST_direction_initialized.reset_RST(ARG_rst_in);
  INST_cycle.reset_RST(ARG_rst_in);
  INST_currentFloor_initialized.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTbNextFloor::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTbNextFloor::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_currentFloor_ignore.dump_state(indent + 2u);
  INST_currentFloor_initialized.dump_state(indent + 2u);
  INST_currentFloor_zaz.dump_state(indent + 2u);
  INST_cycle.dump_state(indent + 2u);
  INST_direction_ignore.dump_state(indent + 2u);
  INST_direction_initialized.dump_state(indent + 2u);
  INST_direction_zaz.dump_state(indent + 2u);
  INST_floor_des_ignore.dump_state(indent + 2u);
  INST_floor_des_initialized.dump_state(indent + 2u);
  INST_floor_des_zaz.dump_state(indent + 2u);
  INST_floor_down_pressed_ignore.dump_state(indent + 2u);
  INST_floor_down_pressed_initialized.dump_state(indent + 2u);
  INST_floor_down_pressed_zaz.dump_state(indent + 2u);
  INST_floor_up_pressed_ignore.dump_state(indent + 2u);
  INST_floor_up_pressed_initialized.dump_state(indent + 2u);
  INST_floor_up_pressed_zaz.dump_state(indent + 2u);
  INST_outFIFO.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTbNextFloor::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 37u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "cycle_6_EQ_0___d37", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "cycle_6_EQ_128___d38", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "direction_zaz_wget____d34", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "direction_zaz_whas____d33", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "new_value__h3175", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h1354", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h1434", 3u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h2224", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h2304", 3u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h314", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h3213", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h3556", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "v__h395", 3u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "value__h3216", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x__h3971", 32u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x_wget__h1297", 3u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x_wget__h2167", 3u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x_wget__h249", 3u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "x_wget__h3039", 32u);
  num = INST_currentFloor_ignore.dump_VCD_defs(num);
  num = INST_currentFloor_initialized.dump_VCD_defs(num);
  num = INST_currentFloor_zaz.dump_VCD_defs(num);
  num = INST_cycle.dump_VCD_defs(num);
  num = INST_direction_ignore.dump_VCD_defs(num);
  num = INST_direction_initialized.dump_VCD_defs(num);
  num = INST_direction_zaz.dump_VCD_defs(num);
  num = INST_floor_des_ignore.dump_VCD_defs(num);
  num = INST_floor_des_initialized.dump_VCD_defs(num);
  num = INST_floor_des_zaz.dump_VCD_defs(num);
  num = INST_floor_down_pressed_ignore.dump_VCD_defs(num);
  num = INST_floor_down_pressed_initialized.dump_VCD_defs(num);
  num = INST_floor_down_pressed_zaz.dump_VCD_defs(num);
  num = INST_floor_up_pressed_ignore.dump_VCD_defs(num);
  num = INST_floor_up_pressed_initialized.dump_VCD_defs(num);
  num = INST_floor_up_pressed_zaz.dump_VCD_defs(num);
  num = INST_outFIFO.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTbNextFloor::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbNextFloor &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTbNextFloor::vcd_defs(tVCDDumpType dt, MOD_mkTbNextFloor &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 3u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 3u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 3u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 32u);
    vcd_write_x(sim_hdl, num++, 3u);
    vcd_write_x(sim_hdl, num++, 3u);
    vcd_write_x(sim_hdl, num++, 3u);
    vcd_write_x(sim_hdl, num++, 32u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
      if ((backing.DEF_cycle_6_EQ_0___d37) != DEF_cycle_6_EQ_0___d37)
      {
	vcd_write_val(sim_hdl, num, DEF_cycle_6_EQ_0___d37, 1u);
	backing.DEF_cycle_6_EQ_0___d37 = DEF_cycle_6_EQ_0___d37;
      }
      ++num;
      if ((backing.DEF_cycle_6_EQ_128___d38) != DEF_cycle_6_EQ_128___d38)
      {
	vcd_write_val(sim_hdl, num, DEF_cycle_6_EQ_128___d38, 1u);
	backing.DEF_cycle_6_EQ_128___d38 = DEF_cycle_6_EQ_128___d38;
      }
      ++num;
      if ((backing.DEF_direction_zaz_wget____d34) != DEF_direction_zaz_wget____d34)
      {
	vcd_write_val(sim_hdl, num, DEF_direction_zaz_wget____d34, 1u);
	backing.DEF_direction_zaz_wget____d34 = DEF_direction_zaz_wget____d34;
      }
      ++num;
      if ((backing.DEF_direction_zaz_whas____d33) != DEF_direction_zaz_whas____d33)
      {
	vcd_write_val(sim_hdl, num, DEF_direction_zaz_whas____d33, 1u);
	backing.DEF_direction_zaz_whas____d33 = DEF_direction_zaz_whas____d33;
      }
      ++num;
      if ((backing.DEF_new_value__h3175) != DEF_new_value__h3175)
      {
	vcd_write_val(sim_hdl, num, DEF_new_value__h3175, 32u);
	backing.DEF_new_value__h3175 = DEF_new_value__h3175;
      }
      ++num;
      if ((backing.DEF_v__h1354) != DEF_v__h1354)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h1354, 32u);
	backing.DEF_v__h1354 = DEF_v__h1354;
      }
      ++num;
      if ((backing.DEF_v__h1434) != DEF_v__h1434)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h1434, 3u);
	backing.DEF_v__h1434 = DEF_v__h1434;
      }
      ++num;
      if ((backing.DEF_v__h2224) != DEF_v__h2224)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h2224, 32u);
	backing.DEF_v__h2224 = DEF_v__h2224;
      }
      ++num;
      if ((backing.DEF_v__h2304) != DEF_v__h2304)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h2304, 3u);
	backing.DEF_v__h2304 = DEF_v__h2304;
      }
      ++num;
      if ((backing.DEF_v__h314) != DEF_v__h314)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h314, 32u);
	backing.DEF_v__h314 = DEF_v__h314;
      }
      ++num;
      if ((backing.DEF_v__h3213) != DEF_v__h3213)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h3213, 32u);
	backing.DEF_v__h3213 = DEF_v__h3213;
      }
      ++num;
      if ((backing.DEF_v__h3556) != DEF_v__h3556)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h3556, 32u);
	backing.DEF_v__h3556 = DEF_v__h3556;
      }
      ++num;
      if ((backing.DEF_v__h395) != DEF_v__h395)
      {
	vcd_write_val(sim_hdl, num, DEF_v__h395, 3u);
	backing.DEF_v__h395 = DEF_v__h395;
      }
      ++num;
      if ((backing.DEF_value__h3216) != DEF_value__h3216)
      {
	vcd_write_val(sim_hdl, num, DEF_value__h3216, 32u);
	backing.DEF_value__h3216 = DEF_value__h3216;
      }
      ++num;
      if ((backing.DEF_x__h3971) != DEF_x__h3971)
      {
	vcd_write_val(sim_hdl, num, DEF_x__h3971, 32u);
	backing.DEF_x__h3971 = DEF_x__h3971;
      }
      ++num;
      if ((backing.DEF_x_wget__h1297) != DEF_x_wget__h1297)
      {
	vcd_write_val(sim_hdl, num, DEF_x_wget__h1297, 3u);
	backing.DEF_x_wget__h1297 = DEF_x_wget__h1297;
      }
      ++num;
      if ((backing.DEF_x_wget__h2167) != DEF_x_wget__h2167)
      {
	vcd_write_val(sim_hdl, num, DEF_x_wget__h2167, 3u);
	backing.DEF_x_wget__h2167 = DEF_x_wget__h2167;
      }
      ++num;
      if ((backing.DEF_x_wget__h249) != DEF_x_wget__h249)
      {
	vcd_write_val(sim_hdl, num, DEF_x_wget__h249, 3u);
	backing.DEF_x_wget__h249 = DEF_x_wget__h249;
      }
      ++num;
      if ((backing.DEF_x_wget__h3039) != DEF_x_wget__h3039)
      {
	vcd_write_val(sim_hdl, num, DEF_x_wget__h3039, 32u);
	backing.DEF_x_wget__h3039 = DEF_x_wget__h3039;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_cycle_6_EQ_0___d37, 1u);
      backing.DEF_cycle_6_EQ_0___d37 = DEF_cycle_6_EQ_0___d37;
      vcd_write_val(sim_hdl, num++, DEF_cycle_6_EQ_128___d38, 1u);
      backing.DEF_cycle_6_EQ_128___d38 = DEF_cycle_6_EQ_128___d38;
      vcd_write_val(sim_hdl, num++, DEF_direction_zaz_wget____d34, 1u);
      backing.DEF_direction_zaz_wget____d34 = DEF_direction_zaz_wget____d34;
      vcd_write_val(sim_hdl, num++, DEF_direction_zaz_whas____d33, 1u);
      backing.DEF_direction_zaz_whas____d33 = DEF_direction_zaz_whas____d33;
      vcd_write_val(sim_hdl, num++, DEF_new_value__h3175, 32u);
      backing.DEF_new_value__h3175 = DEF_new_value__h3175;
      vcd_write_val(sim_hdl, num++, DEF_v__h1354, 32u);
      backing.DEF_v__h1354 = DEF_v__h1354;
      vcd_write_val(sim_hdl, num++, DEF_v__h1434, 3u);
      backing.DEF_v__h1434 = DEF_v__h1434;
      vcd_write_val(sim_hdl, num++, DEF_v__h2224, 32u);
      backing.DEF_v__h2224 = DEF_v__h2224;
      vcd_write_val(sim_hdl, num++, DEF_v__h2304, 3u);
      backing.DEF_v__h2304 = DEF_v__h2304;
      vcd_write_val(sim_hdl, num++, DEF_v__h314, 32u);
      backing.DEF_v__h314 = DEF_v__h314;
      vcd_write_val(sim_hdl, num++, DEF_v__h3213, 32u);
      backing.DEF_v__h3213 = DEF_v__h3213;
      vcd_write_val(sim_hdl, num++, DEF_v__h3556, 32u);
      backing.DEF_v__h3556 = DEF_v__h3556;
      vcd_write_val(sim_hdl, num++, DEF_v__h395, 3u);
      backing.DEF_v__h395 = DEF_v__h395;
      vcd_write_val(sim_hdl, num++, DEF_value__h3216, 32u);
      backing.DEF_value__h3216 = DEF_value__h3216;
      vcd_write_val(sim_hdl, num++, DEF_x__h3971, 32u);
      backing.DEF_x__h3971 = DEF_x__h3971;
      vcd_write_val(sim_hdl, num++, DEF_x_wget__h1297, 3u);
      backing.DEF_x_wget__h1297 = DEF_x_wget__h1297;
      vcd_write_val(sim_hdl, num++, DEF_x_wget__h2167, 3u);
      backing.DEF_x_wget__h2167 = DEF_x_wget__h2167;
      vcd_write_val(sim_hdl, num++, DEF_x_wget__h249, 3u);
      backing.DEF_x_wget__h249 = DEF_x_wget__h249;
      vcd_write_val(sim_hdl, num++, DEF_x_wget__h3039, 32u);
      backing.DEF_x_wget__h3039 = DEF_x_wget__h3039;
    }
}

void MOD_mkTbNextFloor::vcd_prims(tVCDDumpType dt, MOD_mkTbNextFloor &backing)
{
  INST_currentFloor_ignore.dump_VCD(dt, backing.INST_currentFloor_ignore);
  INST_currentFloor_initialized.dump_VCD(dt, backing.INST_currentFloor_initialized);
  INST_currentFloor_zaz.dump_VCD(dt, backing.INST_currentFloor_zaz);
  INST_cycle.dump_VCD(dt, backing.INST_cycle);
  INST_direction_ignore.dump_VCD(dt, backing.INST_direction_ignore);
  INST_direction_initialized.dump_VCD(dt, backing.INST_direction_initialized);
  INST_direction_zaz.dump_VCD(dt, backing.INST_direction_zaz);
  INST_floor_des_ignore.dump_VCD(dt, backing.INST_floor_des_ignore);
  INST_floor_des_initialized.dump_VCD(dt, backing.INST_floor_des_initialized);
  INST_floor_des_zaz.dump_VCD(dt, backing.INST_floor_des_zaz);
  INST_floor_down_pressed_ignore.dump_VCD(dt, backing.INST_floor_down_pressed_ignore);
  INST_floor_down_pressed_initialized.dump_VCD(dt, backing.INST_floor_down_pressed_initialized);
  INST_floor_down_pressed_zaz.dump_VCD(dt, backing.INST_floor_down_pressed_zaz);
  INST_floor_up_pressed_ignore.dump_VCD(dt, backing.INST_floor_up_pressed_ignore);
  INST_floor_up_pressed_initialized.dump_VCD(dt, backing.INST_floor_up_pressed_initialized);
  INST_floor_up_pressed_zaz.dump_VCD(dt, backing.INST_floor_up_pressed_zaz);
  INST_outFIFO.dump_VCD(dt, backing.INST_outFIFO);
}