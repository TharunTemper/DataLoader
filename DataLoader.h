/*
    DataLoader.h - Designed and Developed by SSIT Solutions PVT.LTD
                 - Modified by Tharun Mangaraju <tharunm.t9705@gmail.com>

    Copyright (c) 2014 Sense Semiconductor and IT Solutions PVT.LTD
    This file is part of the APPHC project in ESP32 core for Arduino environment.

    This library is licensed and you cannot redistribute it and/or modify it under any terms.

    This Library is used as one of the part of APPHC(Automated Paralysis Patient Health Care) System.

    This Library is used to load data like flex assignments and credentials of Networks into  structures...

    This Library primarily load these details:

        @Flex assignment values
        @WiFi credentials(SSID and PASSWORD)
        @Hotspot credentials(SSID and PASSWORD)
        @Router credentials(SSID and PASSWORD)
        @Bluetooth credentials(Bluetooth Name)

*/


#ifndef _DATALOADER_H
#define _DATALOADER_H

#include <Arduino.h>

/*
@brief - Defining two structure Flex_assignments_t and Network_details_t

*Flex_assignments_t : This Structure stores four string values which are nothing but four distinct finger assignmet values.

*Network_details_t  : This Structure stores  two string values which are nothing but SSID and PASSWORD of respective network, which may varies from network connected.

*/
typedef struct flex_values {
  String flex1 ;
  String flex2 ;
  String flex3 ;
  String flex4 ;
}Flex_assignments_t;

typedef struct credentials {
  String ssid ;
  String password;
}Network_details_t;

/* ----------------------------------------------Class DataLoader-------------------------------------------------------------------------------
@brief : This class used to store received values in a respective structures

*Load_flex_values - Stores flex assignment values in a structure with given inputs
    @param - received (String)
    @return - Flex_assignment_t structure.

*Load_wifi_values - Stores wifi credential values in a structure with given inputs
    @param - received (String)
    @return - Network_details_t structure.

*Load_hotspot_values - Stores hotspot credential values in a structure with given inputs
    @param - received (String)
    @return - Network_details_t structure.

*Load_router_values - Stores wifi credential values in a structure with given inputs
    @param - received (String)
    @return - Network_details_t structure.

*Load_Bluetooth - Stores Bluetooth credential values in a string with given inputs
    @param - received (String)
    @return - String.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
class DataLoader{

private:
  Flex_assignments_t received_data;
  Network_details_t credentials;

public:
    Flex_assignments_t Load_flex_values(String received);    // Change return type to values
    Network_details_t Load_wifi_details(String received);   // Change return type to values
    Network_details_t Load_router_details(String received); // Change return type to values
    Network_details_t Load_hotspot_details(String received);// Change return type to values
};
#endif

