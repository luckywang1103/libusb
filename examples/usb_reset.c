#include <stdio.h>
#include <string.h>
#include "libusb.h"

int main()
{
	libusb_device **devs;
	libusb_device_handle *handle = NULL;
	int ret, cnt;

	ret = libusb_init(NULL);
	if (ret < 0) {
		printf("libusb_init fail\n");
		goto exit;
	}

	cnt = libusb_get_device_list(NULL, &devs);
	if (cnt < 0) {
		printf("libusb_get_device_list fail\n");
		goto exit;
	}

	ret = libusb_open(devs[0], &handle);
	if (LIBUSB_SUCCESS != ret) {
		printf("libusb_open fail\n");
		goto exit;
	}

	ret = libusb_reset_device(handle);
	if (ret < 0) {
		printf("libusb_reset_device fail\n");
		goto exit;
	}

exit:
	if (handle)
		libusb_close(handle);

	libusb_exit(NULL);

	return 0;
}
