// SEI.NET.h

#pragma once

using namespace System;

namespace SEI {

	#include "SEIDrv32.h"

	public ref class DeviceInfo
	{
	public:
		long model;
		long serial;
		long version;
		long address;
	};

	public ref class Bus
	{
	public:
		Bus();
		~Bus();

		void reset();
		long getDeviceCount();
		DeviceInfo ^ getDeviceInfo(long deviceNumber);
	private:
		static void init();
		static void close();
		static int count = 0;
		// TODO: Add your methods for this class here.
	};

	public ref class A2Device
	{
	public:
		A2Device(long address);
		void setAddress(long address);
		long getResolution();
		long getPosiiton();
	private:
		long address;
		Bus bus;
	};
}
