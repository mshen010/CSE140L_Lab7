package ElevatorInterface;
typedef enum {UP, DOWN} Direction deriving(Bits, Eq); 
typedef enum {START, STOP} Moving deriving(Bits, Eq); 
typedef 3 NUM_FLOOR;  
 
interface Elevator; 
        method Action floor_0_up_request; 
        method Action floor_1_up_request; 
        method Action floor_1_down_request; 
        method Action floor_2_down_request; 
 
        method Action floor_0_des_request; 
        method Action floor_1_des_request; 
        method Action floor_2_des_request; 
 
        method Action setCurrentFloor(int floor); 
 
        method Moving moving; 
        method Direction direction; 
endinterface 
endpackage
