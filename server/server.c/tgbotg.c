#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>
#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>

#define API_KEY "6248484848:AAH-1234567890"
#define API_URL "https://api.telegram.org/bot"

int webhook_callback(struct evhttp_request *req, void *arg) {
    const char *content_type = evhttp_find_header(req->input_headers, "Content-Type");
    if (!content_type || strcmp(content_type, "application/json") != 0) {
        evhttp_send_reply(req, HTTP_BADREQUEST, NULL, NULL);
        return 0;
    }
    
};

int tgbot(int argc, char *argv[]) {
    struct event_base *base;
    struct evhttp_connection *conn;
    struct evhttp_request *req;
    //从telegram服务器接收post数据
}
