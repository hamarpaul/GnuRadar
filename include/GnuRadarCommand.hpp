// Copyright (c) 2010 Ryan Seal <rlseal -at- gmail.com>
//
// This file is part of GnuRadar Software.
//
// GnuRadar is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// GnuRadar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GnuRadar.  If not, see <http://www.gnu.org/licenses/>.
#ifndef GNURADAR_COMMAND_HPP
#define GNURADAR_COMMAND_HPP

#include <iostream>
#include <stdexcept>
#include<gnuradar/commands/Response.pb.h>
#include<gnuradar/commands/Control.pb.h>

namespace gnuradar {
   namespace command {

      class GnuRadarCommand {

         std::string name_;

         public:

         GnuRadarCommand ( const std::string& name ) : name_ ( name ) {}

         virtual const gnuradar::ResponseMessage Execute ( gnuradar::ControlMessage& msg ) = 0;

         const std::string& Name() { return name_; }
      };
   };
};

#endif
