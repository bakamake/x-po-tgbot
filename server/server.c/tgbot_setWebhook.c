#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>

int tgbot_setWebhook(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;
    char url[256];
    char *token = "6248484848:AAH-1234567890";
    char *webhook_url = "https://your-server.com/webhook";

    // 构建请求URL
    snprintf(url, sizeof(url), "https://api.telegram.org/bot%s/setWebhook", token);
    snprintf(webhook_url, sizeof(webhook_url), "https://%s/webhook", argv[1]);

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize curl\n");
        return 1;
    };

    // 设置请求头
    headers = curl_slist_append(headers, "Content-Type: application/json");

    // 设置请求体
    cJSON *payload = cJSON_CreateObject();
    cJSON_AddStringToObject(payload, "url", webhook_url);
    cJSON_AddBoolToObject(payload, "drop_pending_updates", 1);

    // 将请求体转换为JSON字符串
    char *payload_json = cJSON_Print(payload);
    cJSON_Delete(payload);

    // 设置请求选项
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload_json);

    // 执行请求
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        free(payload_json);
        return 1;
    }

    // 释放资源
    curl_easy_cleanup(curl);    
    curl_slist_free_all(headers);
    free(payload_json);

    return 0;           
    
    
}