#ifndef PAYLOAD_DATA_H
#define PAYLOAD_DATA_H

#include "ip_header.h"
#include "input_parsar.h"





unsigned char payload_length[50] = {0};

void payload(){
    unsigned short payload_length = sizeof(packet) - (total_length+14); // Calculate payload length based on total length of IP header
    unsigned char payload_data[payload_length];
    unsigned char payload_start = total_length + 14; // Start after Ethernet header and IP header
    for(int i = 0; i < payload_length; i++) {
        payload_data[i] = packet[payload_start + i]; // Copy payload data from packet
    }
    printf("-----------------------------\n");
    printf("Payload Data: \n");
    printf("-----------------------------\n");
    
    for(int i = 0; i < payload_length; i++) {
        printf("%02X ", payload_data[i]); // Print payload data in hex format
        if ((i + 1) % 8 == 0) {
            printf("\n"); // New line every 16 bytes
        }
        
    }

   
}





#endif // PAYLOAD_DATA_H