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

#include "Command/Command.h"
#include "Command/CommandStack.h"
#include "Main/CommandLine.h"
#include "Tcl/TclInterpreter.h"

#ifndef DESIGN_H
#define DESIGN_H

namespace FOEDAG {

class Design {
 public:
  enum Language {
    VHDL_1987,
    VHDL_1993,
    VHDL_2008,
    VERILOG_1995,
    VERILOG_2001,
    SYSTEMVERILOG_2005,
    SYSTEMVERILOG_2009,
    SYSTEMVERILOG_2012,
    SYSTEMVERILOG_2017,
  };
  Design(std::string& designName) : m_designName(designName) {}
  ~Design();

  const std::string& Name() { return m_designName; }

  void AddFile(Language language, const std::string& fileName) {
    m_fileList.push_back(std::make_pair(language, fileName));
  }
  std::vector<std::pair<Language, std::string>>& FileList() {
    return m_fileList;
  }

  void TopLevel(const std::string& topLevelModule) {
    m_topLevelModule = topLevelModule;
  }
  const std::string& TopLevel() { return m_topLevelModule; }

 private:
  std::string m_designName;
  std::string m_topLevelModule;
  std::vector<std::pair<Language, std::string>> m_fileList;
};

}  // namespace FOEDAG

#endif
