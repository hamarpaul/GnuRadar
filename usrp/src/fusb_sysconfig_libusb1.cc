/* -*- c++ -*- */
/*
 * Copyright 2003,2009 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include <usrp/usb/fusb.h>
#include <usrp/usb/fusb_libusb1.h>

static const int MAX_BLOCK_SIZE = 16 * 1024;		// hard limit
static const int DEFAULT_BLOCK_SIZE =   4 * 1024;
static const int FUSB_BUFFER_SIZE = 1 * (1L << 20);	// 1 MB

struct libusb_context;

fusb_devhandle *
fusb_sysconfig::make_devhandle (libusb_device_handle *udh, libusb_context *ctx)
{
  return new fusb_devhandle_libusb1 (udh, ctx);
}
	
int fusb_sysconfig::max_block_size ()
{
  return MAX_BLOCK_SIZE;
}

int fusb_sysconfig::default_block_size ()
{
  return DEFAULT_BLOCK_SIZE;
}

int fusb_sysconfig::default_buffer_size ()
{
  return FUSB_BUFFER_SIZE;
}
