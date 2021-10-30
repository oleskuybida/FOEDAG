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

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

namespace FOEDAG {

class CommandLine {
 private:
 public:
  CommandLine(int argc, char** argv);

  ~CommandLine();

  bool WithQt() const { return m_withQt; }

  const std::vector<std::string>& Args() const { return m_args; }

  const std::string& GuiTestScript() const { return m_runGuiTest; }

  const std::string& Script() const { return m_runScript; }

  void printHelp();

 private:
  std::vector<std::string> m_args;
  bool m_withQt = true;
  std::string m_runScript;
  std::string m_runGuiTest;
};

}  // namespace FOEDAG

#endif