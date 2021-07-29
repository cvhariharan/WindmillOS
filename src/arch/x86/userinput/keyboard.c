#include <userinput/keyboard.h>

char QWERTYTable[] = {
    0, 0, '1', '2', '3',
    '4', '5', '6', '7', '8',
    '9', '0', '-', '=', 0, 
    0, 'q', 'w', 'e', 'r',
    't', 'y', 'u', 'i', 'o',
    'p', '[', ']', 0, 0,
    'a', 's', 'd', 'f', 'g',
    'h', 'j', 'k', 'l', ';',
    '\'', '`', 0, '\\', 'z',
    'x', 'c', 'v', 'b', 'n',
    'm', ',', '.', '/', 0,
    '*', 0, ' '
};


char get_key_from_scancode(u8int_t scancode) {
    if(scancode > 0x39) {
        return 0;
    }
    
    return QWERTYTable[scancode];
}