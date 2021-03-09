#ifndef COMMON_H
#define COMMON_H
#include <curl/curl.h>
#include <glog/logging.h>

#include <string>

void initLogging();
std::string httpGet(std::string &url);
std::string packString(std::string ins, int width);
#endif
