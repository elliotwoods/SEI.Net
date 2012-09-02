// This is the main DLL file.

#include "stdafx.h"

#include "SEI.NET.h"

namespace SEI {
#pragma mark Bus
	//---------------
	Bus::Bus() {
		if (this->count == 0)
			this->init();
		this->count++;
	}

	//---------------
	Bus::~Bus() {
		this->count--;
		if (this->count <= 0)
			this->close();
	}

	//---------------
	void Bus::reset() {
		ResetSEI();
	}

	//---------------
	long Bus::getDeviceCount() {
		return GetNumberOfDevices();
	}

	//---------------
	DeviceInfo ^ Bus::getDeviceInfo(long deviceNumber) {
		long model;
		long serial;
		long version;
		long address;
		GetDeviceInfo(deviceNumber, &model, &serial, &version, &address);

		DeviceInfo ^ d = gcnew DeviceInfo();
		d->model = model;
		d->serial = serial;
		d->version = version;
		d->address = address;

		return d;
	}

	//---------------
	void Bus::init() {
		if (IsInitialized() == 0) {
			InitializeSEI(0, AUTOASSIGN);
		}
	}

	//---------------
	void Bus::close() {
		if (IsInitialized() == 1) {
			CloseSEI();
		}
	}

#pragma mark A2Device
	//---------------
	A2Device::A2Device(long address) {
		this->setAddress(address);
	}

	//---------------
	void A2Device::setAddress(long address) {
		this->address = address;
	}

	//---------------
	long A2Device::getResolution() {
		long resolution;
		A2GetResolution(address, &resolution);
		return resolution;
	}

	//---------------
	long A2Device::getPosiiton() {
		long position;
		A2GetPosition(address, &position);
		return position;
	}
}