/*
* Copyright 2016 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#include "ImageSlide.h"

#include "SkCanvas.h"
#include "SkData.h"
#include "SkImage.h"

ImageSlide::ImageSlide(const SkString& name, const SkString& path) : fPath(path) {
    fName = name;
}

SkISize ImageSlide::getDimensions() const {
    return fImage ? fImage->dimensions() : SkISize::Make(0, 0);
}

void ImageSlide::draw(SkCanvas* canvas) {
    canvas->drawImage(fImage, 0, 0);
}

void ImageSlide::load(SkScalar, SkScalar) {
    sk_sp<SkData> encoded = SkData::MakeFromFileName(fPath.c_str());
    fImage = SkImage::MakeFromEncoded(encoded);
}

void ImageSlide::unload() {
    fImage.reset(nullptr);
}
