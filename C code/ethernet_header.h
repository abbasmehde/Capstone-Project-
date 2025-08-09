#ifndef ETHERNET_HEADER_H
#define ETHERNET_HEADER_H

#include "input_parsar.h"

void parser_ethernet_header() {

    unsigned char dest_length = 6;
    unsigned char src_length = 6;
    unsigned char ether_type_length = 2;

    unsigned char dest_mac[dest_length];
    unsigned char src_mac[src_length];
    unsigned short ether_type;

    for(int i = 0; i<dest_length; i++){
        dest_mac[i] = packet[i];
    }
    for(int i=0; i<src_length; i++){
        src_mac[i] = packet[dest_length + i];
    }
    printf("-----------------------------\n");
    printf("Ethernet Header:\n");
    printf("-----------------------------\n");
    printf("Destination MAC: ");
    
    printf("%d:%d:%d:%d:%d:%d\n", dest_mac[0], dest_mac[1], dest_mac[2],  dest_mac[3], dest_mac[4], dest_mac[5]);

    printf("Source MAC: ");
    printf("%d:%d:%d:%d:%d:%d\n", src_mac[0], src_mac[1], src_mac[2], src_mac[3], src_mac[4], src_mac[5]);

    if(packet[12] == 0x08 && packet[13] == 0x00) {
        printf("Ether Type is IPv4.\n");   
    }
    if(packet[12] == 0x86 && packet[13] == 0xDD) {
        printf("Ether Type is IPv6.\n");
    }
    
    

}






#endif