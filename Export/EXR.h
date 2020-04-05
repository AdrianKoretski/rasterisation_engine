#pragma once
#include <iostream>

#define TINYEXR_IMPLEMENTATION
#include "tinyexr.h"

/**
 * Saves render buffer to .exr image file.
 * Taken from https://github.com/ecsex46/fall-2019
 */
bool saveEXR(const float* rgb, const std::string& filename, const int width, const int height) {
	EXRHeader header;
	InitEXRHeader(&header);

	EXRImage image;
	InitEXRImage(&image);

	image.num_channels = 3;

	std::vector<float> images[3];
	images[0].resize(width * height);
	images[1].resize(width * height);
	images[2].resize(width * height);

	// Split RGBRGBRGB... into R, G and B layer
	for (int i = 0; i < width * height; i++) {
		images[0][i] = rgb[i * 3 + 0];
		images[1][i] = rgb[i * 3 + 1];
		images[2][i] = rgb[i * 3 + 2];
	}

	float* image_ptr[3];
	image_ptr[0] = &(images[2].at(0)); // B
	image_ptr[1] = &(images[1].at(0)); // G
	image_ptr[2] = &(images[0].at(0)); // R

	image.images = (unsigned char**)image_ptr;
	image.width = width;
	image.height = height;

	header.num_channels = 3;
	header.channels = (EXRChannelInfo*)malloc(sizeof(EXRChannelInfo) * header.num_channels);

	// Must be (A)BGR order, since most of EXR viewers expect this channel order

	header.channels[0].name[0] = 'B';
	header.channels[0].name[1] = '\0';
	header.channels[1].name[0] = 'G';
	header.channels[1].name[1] = '\0';
	header.channels[2].name[0] = 'R';
	header.channels[2].name[1] = '\0';

	header.pixel_types = (int*)malloc(sizeof(int) * header.num_channels);
	header.requested_pixel_types = (int*)malloc(sizeof(int) * header.num_channels);
	for (int i = 0; i < header.num_channels; i++) {
		header.pixel_types[i] = TINYEXR_PIXELTYPE_FLOAT;
		header.requested_pixel_types[i] = TINYEXR_PIXELTYPE_HALF;
	}

	const char* err = nullptr;
	int ret = SaveEXRImageToFile(&image, &header, filename.c_str(), &err);
	if (ret != TINYEXR_SUCCESS) {
		fprintf(stderr, "Save EXR err: %s\n", err);
		FreeEXRErrorMessage(err);
		return false;
	}
	std::cout << "\nSaved EXR image to " << filename << std::endl;

	free(header.channels);
	free(header.pixel_types);
	free(header.requested_pixel_types);
	return true;
}