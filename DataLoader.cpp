#include "DataLoader.h"


Flex_assignments_t DataLoader:: Load_flex_values(String received)
{
    int received_data_length = received.length() -1;
    String value = received.substring(0,received_data_length);
    char ack = received[received_data_length];
    switch (ack)
    {
        case 'i': received_data.flex1 = value;
                  Serial.println("Received assign for index finger is: "+ String(value));
                  break;
        case 'm': received_data.flex2 = value;
                  Serial.println("Received assign for middle finger is: "+ String(value));
                  break;
        case 'r': received_data.flex3= value;
                  Serial.println("Received assign for ring finger is: "+ String(value));
                  break;
        case 'l': received_data.flex4= value;
                  Serial.println("Received assign for little finger is: "+ String(value));
                  break;
        default: Serial.println("Invalid acknowledgment for flexes. Retrying...");
    }
    return received_data;
}

Network_details_t DataLoader :: Load_wifi_details(String received)
{
    int received_data_length = received.length() - 1;
    String value = received.substring(0, received_data_length);
    char ack = received[received_data_length];
    switch (ack)
    {
        case 's': credentials.ssid = value;
                  Serial.println("Received SSID is "+ String(value));
                  break;
        case 'p': credentials.password = value;
                  Serial.println("Received Password is "+ String(value));
                  break;
        default: Serial.println("Invalid acknowledgment for wifi. Retrying...");
    }
    return credentials;
}

Network_details_t DataLoader::Load_router_details(String received)
{
    int received_data_length = received.length() - 1;
    String value = received.substring(0, received_data_length);
    char ack = received[received_data_length];
    switch (ack)
    {
        case 's': credentials.ssid = value;
                  Serial.println("Received SSID is "+ String(value));
                  break;
        case 'p': credentials.password = value;
                  Serial.println("Received Password is "+ String(value));
                  break;
        default: Serial.println("Invalid acknowledgment for router. Retrying...");
    }
    return credentials;
}

Network_details_t DataLoader::Load_hotspot_details(String received)
{
    int received_data_length = received.length() - 1;
    String value = received.substring(0, received_data_length);
    char ack = received[received_data_length];
    switch(ack)
    {
        case 's': credentials.ssid = value;
                  Serial.println("Received SSID is "+ String(value));
                  break;
        case 'p': credentials.password = value;
                  Serial.println("Received Password is "+ String(value));
                  break;
        default: Serial.println("Invalid acknowledgment for router. Retrying...");
    }
    return credentials;
}
