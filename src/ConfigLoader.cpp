#include "../include/ConfigLoader.h"
#include <boost/program_options.hpp>
#include "../include/version.h"
#include <string>
#include <fstream>

ConfigLoader::ConfigLoader(int ac, char** av)
{


  const std::string AUTHOR="Krzysztof Grzempa";
  const std::string LICENCE="GNU GPLv3";
  const int YEAR=2016;

  namespace po = boost::program_options;
  po::options_description desc("Available options");
  po::positional_options_description p;
  po::options_description confdesc("Config Options");

  try {
    std::ifstream Config_File(av[1]);
    desc.add_options()
      ("about", "Authors and licences")
      ("help,h", "produce help message")
      ("version,v", "print version informations")
      ("configfile", po::value<std::string>(), "Configuration file");
    p.add("configfile", -1);
    po::variables_map vm;
    po::store(po::command_line_parser(ac, av).options(desc).positional(p).run(), vm);
    //po::store(po::parse_config_file(Config_File, desc), vm);

    if (vm.count("help")) {
      std::cout << desc << "\n";

    }

    if (vm.count("version")) {
      using AutoVersion::MINOR;
      using AutoVersion::MAJOR;
      using AutoVersion::BUILD;
      using AutoVersion::REVISION;
      using AutoVersion::STATUS;
      using AutoVersion::STATUS_SHORT;
      std::cout <<  MAJOR << "." << MINOR << "." << BUILD << STATUS_SHORT << " rev: " << REVISION << std::endl;

    }

    if (vm.count("about")) {
      std::cout << "Author: " << AUTHOR << " " << YEAR << "\n"
      << "Under licence: " << LICENCE << "\n";

    }

    if(vm.count("configfile")) {
      std::cout << "Z pliku loga" << vm["configfile"].as<std::string>();
      confdesc.add_options()
        ("LogFile", po::value<std::string>())
        ("IgnoreFile", po::value<std::string>());
      po::store(po::parse_config_file(Config_File, confdesc), vm);

      std::cout << vm["LogFile"].as<std::string>();
      std::cout << vm["IgnoreFile"].as<std::string>();
    }

    po::notify(vm);

  } catch(po::error & ba) {

    std::cout << "ERROR: " << ba.what();

  }

}
