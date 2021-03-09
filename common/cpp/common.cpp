#include "common.h"
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

void initLogging()
{
    google::InitGoogleLogging("edgartools");
    FLAGS_logtostderr = 1;
    FLAGS_v = 10;
};

/* Utility function to help curl chunked read*/
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string *data)
{
    data->append((char *)ptr, size * nmemb);
    return size * nmemb;
};

/* utility function to get data from http url*/
string httpGet(string &url)
{
    string response = "";
    auto curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl = nullptr;
    }
    return response;
};

///////////////////////////////////////////////////////////////////////////////

std::string packString(std::string ins, int width){
    string fmt_str = "%-" + boost::lexical_cast<string>(width) + string{"s"};
    return boost::lexical_cast<string>(boost::format(fmt_str) % ins);


    //return ins;
}