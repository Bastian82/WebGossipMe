#include <iostream>
#include "../include/ConfigLoader.h"
//#include "../../curlpp/include/curlpp/cURLpp.hpp"
//#include "../../curlpp/include/curlpp/Easy.hpp"
//#include "../../curlpp/include/curlpp/Options.hpp"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include "../../KGrawler/include/KGrawler.h"

int main(int argc, char** argv)
{
    //std::vector<char *> test_seed {"http://127.0.0.1", "http://127.0.0.1/next.html"};
    std::vector<char *> test_seed {"https://www.tvn24.pl","https://www.onet.pl", "https://wp.pl"};
    ConfigLoader(argc, argv);
    KGrawler Crawl(test_seed);
    Crawl.start();
    Crawl.stop();
}
