#ifndef IP_HEADER_H
#define IP_HEADER_H

#include "input_parsar.h"
#include <stdio.h>
unsigned short total_length = 0;
void parse_ip_header() {
    // Example function to parse the IP header
     
     unsigned char ihl = 0;
    unsigned char version = (packet[14] >> 4) & 0x0F; // Version

    if(version == 4) {
         ihl = packet[14] & 0x0F;                                // Internet Header Length
         total_length = ihl*4;                                   // Total Length

    }
    if(packet[12] == 0x86 && packet[13] == 0xDD) {
        total_length = 60;                                      // Default for IPv6, can be adjusted based on actual header parsing
        ihl = 0;                                                // IHL is not applicable for IPv6

    }


    unsigned char dest_ip[4];
    unsigned char src_ip[4];
    unsigned char protocol = packet[23]; // Protocol field in IPv4 header
    for(int i = 0; i < 4; i++) {
        dest_ip[i] = packet[30+i]; // Destination IP starts at byte 16
        src_ip[i] = packet[26+i];  // Source IP starts at byte 12
    }
    printf("-----------------------------\n");
    printf("IP Header:\n");
    printf("-----------------------------\n");

    printf("Destination IP: %d.%d.%d.%d\n", dest_ip[0], dest_ip[1], dest_ip[2], dest_ip[3]);
    printf("Source IP: %d.%d.%d.%d\n", src_ip[0], src_ip[1], src_ip[2], src_ip[3]);
    printf("Protocol: 0x%x\n", protocol);

    
}




#endif // IP_HEADER_H