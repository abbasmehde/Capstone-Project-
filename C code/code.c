#include "stdio.h"
#include "ethernet.h"
#include "ip.h"
#include "payload.h"
#include "input_packet.h"

unsigned char protocol_checker(unsigned char *arry, unsigned char length);

int main() {
    printf("Starting Packet Parser...\n");
    
    unsigned char type = 0;
    unsigned char state = 0;
    type = protocol_checker(packet, packet_length);
    printf("type is checked\n");
    if(type == IPV_4) { state =1;}
    else if(type == IPV_6) { state =2;}
    else { state = -1; }
    printf("state is selected\n");
    
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
                printf("2nd layer is not IPV4 nor IPV6\n");
                printf("unsupported IP in Packet.\n");
            }
    
    return 0;
}

unsigned char protocol_checker(unsigned char arry[], unsigned char length) {
    unsigned char type = 0;
    for(int i = 0; i < length; i++) {
        if(arry[i] == 0x08 && arry[i+1] == 0x00) {
            // printf("Ether Type is IPv4.\n");
            type = 4; // IPv4
        }
        if(arry[i] == 0x86 && arry[i+1] == 0xDD) {
            // printf("Ether Type is IPv6.\n");
            type = 6; // IPv6
        }
    }
    return type;
}
