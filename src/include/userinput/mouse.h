#include <lib/types.h>

/*

IO Port 	Access Type 	Purpose
0x60 	    Read/Write 	    Data Port
0x64 	    Read 	        Status Register
0x64 	    Write 	        Command Register

0x60 (Data Port) - Used to read/write data from/to the ps/2 controller or the ps/2 device
0x64 (Read - Status Register) - Contains flags that show the state of the ps/2 controller
0x64 (Write - Command Register) - Used to send commands to the ps/2 controller and NOT the actual ps/2 device


More details - https://wiki.osdev.org/%228042%22_PS/2_Controller
*/


int mouse_init();
