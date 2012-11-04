#include <iostream>
#include <fstream>

#include "Logger.hpp"

std::string header (Log::PRIORITY)
{
  return "THIS IS SPARTA: ";
}

int main()
{
  log_log << "Some random info" << 4 << std::endl;
  log_err << "Some error" << std::endl;
  log_warn << "Some warning" << std::endl;
  log_debug << "debug text" << std::endl;
  
  log_logf("Simple String\n");
  log_errf("%d %d %d\n", 2112, 12, 21);
  log_warnf("THE WORLD WILL END IN %f SEC\n", 5);
  log_debugf("debug text\n");

  std::ofstream file("temp");
  
  Log::Logger::Instance()->set_output(Log::INFO, &file);
  Log::Logger::Instance()->set_header(header);

  log_log << "Some random info" << 4 << std::endl;
  log_err << "Some error" << std::endl;
  log_warn << "Some warning" << std::endl;
  log_debug << "debug text" << std::endl;
  
  log_logf("Simple String\n");
  log_errf("%d %d %d\n", 2112, 12, 21);
  log_warnf("THE WORLD WILL END IN %f SEC\n", 5);
  log_debugf("debug text\n");

  return 0;
}