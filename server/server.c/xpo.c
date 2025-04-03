#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
        
    }
}