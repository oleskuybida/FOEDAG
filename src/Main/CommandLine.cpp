/*
Copyright 2021 The Foedag team

GPL License

Copyright (c) 2021 The Open-Source FPGA Foundation

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "CommandLine.h"

using namespace FOEDAG;

void CommandLine::printHelp() {
  std::cout << "-------------------------" << std::endl;
  std::cout << "-----  FOEDAG HELP  -----" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "   --help:  This help" << std::endl;
  std::cout << "   --noqt:  Tcl only, no GUI" << std::endl;
  std::cout << "   --gui_test <script>: Replay GUI test" << std::endl;
  std::cout << "   --script   <script>: Execute a Tcl script" << std::endl;
  std::cout << "Tcl commands:" << std::endl;
  std::cout << "   help" << std::endl;
  std::cout << "   gui_start" << std::endl;
  std::cout << "   gui_stop" << std::endl;
  std::cout << "   tcl_exit" << std::endl;
  std::cout << "-------------------------" << std::endl;
}

CommandLine::CommandLine(int argc, char** argv) {
  for (int i = 1; i < argc; i++) {
    std::string token(argv[i]);
    if (token == "--noqt") {
      m_withQt = false;
    } else if (token == "--gui_test") {
      i++;
      m_runGuiTest = argv[i];
    } else if (token == "--script") {
      i++;
      m_runScript = argv[i];
    } else if (token == "--help") {
      printHelp();
    } else {
      std::cout << "Unknown command line option: " << argv[i] << std::endl;
    }
  }
}

CommandLine::~CommandLine() {}
