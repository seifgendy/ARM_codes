#ifndef WIFI_PRIVATE_H
#define WIFI_PRIVATE_H

#define READY                      "AT\r\n"
#define RESET                      "AT+RST\r\n"
#define STATIONMODE                "AT+CWMODE=1\r\n"
#define ACCESSPOINTMODE            "AT+CWMODE=2\r\n"
#define DISABLE_ECHO               "ATE0\r\n"
#define ENABLE_ECHO                "ATE1\r\n"
#define INTERNET_CONNECT           "AT+CWJAP_CUR=\""
#define SERVER_CONNECT             "AT+CIPSTART=\""
#define CHAR_NUM                   "AT+CIPSEND="
#define ENTER_COMMAND              "\r\n"
#define GET                        "GET "
#define ECHO_TIMEOUT               100
#define NODE_MODE_TIMEOUT          150
#define ROUTER_TIMEOUT             2000000
#define SERVER_TIMEOUT             2000000
#define PREREQUEST_TIMEOUT         200
#define REQUEST_TIMEOUT            900000

static u8 u8ValidateCmd(u32 Copy_u32timeout);
u8 AsciToHex(u8 Copy_u8Ascii);

#endif /* WIFI_PRIVATE_H */
