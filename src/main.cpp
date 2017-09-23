#include <iostream>
#include "../include/ConfigLoader.h"
#include "../../curlpp/include/curlpp/cURLpp.hpp"
#include "../../curlpp/include/curlpp/Easy.hpp"
#include "../../curlpp/include/curlpp/Options.hpp"
#include "../../KGrawler/include/KGrawler.h"

int main(int argc, char** argv)
{
  std::vector<char *> test_seed {"https://www.liveleak.com", "https://www.pagerduty.com", "https://allegro.pl"};
  ConfigLoader(argc, argv);
  KGrawler Crawl(test_seed);
  Crawl.start();
  Crawl.stop();
}
