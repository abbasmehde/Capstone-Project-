#include <stdio.h>
#include "input_parsar.h"
#include "ethernet_header.h"
#include "ip_header.h"
#include "payload_data.h"


unsigned char packet_length = sizeof(packet);

int main() {
    unsigned char state = 0;
    unsigned char ipv = 0;
    if(packet[12] == 0x08 && packet[13] == 0x00) {
        state = 1; // Ethernet header
        ipv = 4;
    } else if(packet[12] == 0x86 && packet[13] == 0xDD) {
        state = 2; // Ethernet header for IPv6
        ipv = 6;
    }

    if(ipv == 4 || ipv == 6){
            switch(state) {

            case 0:
                printf("Ready to Take Parser\n");
                break;
            case 1:
                parser_ethernet_header();
                parse_ip_header();
                payload();
                break;
            case 2:
                parser_ethernet_header();
                parse_ip_header();
                payload();
                break;
            default:
                printf("unsupported IP.\n");
            }
    }

    

   
    
    return 0;
}

