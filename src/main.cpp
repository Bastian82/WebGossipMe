#include <iostream>
#include "../include/ConfigLoader.h"
//#include "../../curlpp/include/curlpp/cURLpp.hpp"
//#include "../../curlpp/include/curlpp/Easy.hpp"
//#include "../../curlpp/include/curlpp/Options.hpp"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include "../../KGrawler/include/KGrawler.h"
/* TODO (grzempek#1#01/13/18): Dodac blackliste rozszerzen (pliki graficzne, inne binaria) */
void signalHandler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!.\n";

    // cleanup and close up stuff here
    // terminate program
/* TODO (grzempek#1#02/09/18): Zamiast stop() ma byc tutaj obsluga dumpów zarowno tablicy found, history, czyli instancje metod KGrawler::show('found'), KGrawler::show('history'), KGrawler::show('feeder) */
    KGrawler::stop();
    //exit(signum);
}


int main(int argc, char** argv)
{
    //std::vector<char *> test_seed {"http://127.0.0.1", "http://127.0.0.1/next.html"};
//    std::vector<char *> test_seed {"https://www.tvn24.pl","https://www.onet.pl", "https://wp.pl"};
//    std::vector<char *> test_seed {"https://serafin.tech/", "https://www.onet.pl", "https://pl-pl.facebook.com/allegro/", "https://edition.cnn.com/"};

    // register signal SIGINT and signal hander
    signal(SIGUSR1, signalHandler);

    std::vector<char *> test_seed {"http://amp.mcclatchydc.com/news/nation-world/national/article195231139.html"};
    ConfigLoader(argc, argv);
    KGrawler Crawl(test_seed);
    Crawl.start();

}
