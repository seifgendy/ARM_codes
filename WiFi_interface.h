#ifndef WIFI_INTERFACE_H
#define WIFI_INTERFACE_H

void WiFi_voidInit(void);
void WiFi_voidRouterConnect(void);
void WiFi_voidServerConnect(void);
void WiFi_voidServerSendRecordRequest(void);
u16 WiFi_voidRecieve(void);

#endif /* WIFI_INTERFACE_H */
